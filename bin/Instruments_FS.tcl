#!/bin/sh
# the next line restarts using wish \
exec wish8.4 "$0" -- "$@"
#
# Instruments.tcl
#
# Copyright (c) IPG Automotive GmbH, Karlsruhe, Germany (www.ipg.de)

set Pgm(Dir)  [file dirname [info script]]
set Pgm(Arch) [expr {$tcl_platform(os)=="Linux" ? "linux" : "win32"}]
catch { set env(HOME) $env(USERPROFILE) }

set Pgm(Name)           "Instruments FS"
set Pgm(Version)	"2.1.4"
set Pgm(VersionDate)    "2005-12-20"

option add "*Label.Font" "Helvetica -12 bold" widgetDefault

array set HIL {
    AcceptHost  ""
    AcceptPid   ""
    AcceptUser  ""
    AcceptClass	""
    AcceptName	""
}

array set Config {
    MaxSpeed 	180
    MaxRPM	16000
    MaxStW	180
    nGears	6
    Lang        english
    Mode	CM
    withPedals 	1
}

# Subscription = list of variables to be subscriped
#   Tcl var             quantity        alternate quantities
set Subscription {
    {Qu(Distance) 	Vhcl.Distance	}
    {Qu(vCar) 		IO.vCar		Car.v		MC.v	}
    {Qu(nEngine) 	IO.nEngine	Vhcl.Engine.rotv }
    {Qu(Gas) 		IO.Gas		DM.Gas		}
    {Qu(Clutch) 	IO.Clutch	DM.Clutch	}
    {Qu(Brake) 		DM.Brake	}
    {Qu(BrakeLever) 	DM.BrakeLever	}
    {Qu(GearNo) 	DM.GearNo	}
    {Qu(StWhlAngle) 	Steer.WhlAng	}
    {Qu(Kl15SW) 	Kl15SW  	}
    {Qu(LaABS) 		IO.LaABS	}
    {Qu(LaESP) 		IO.LaESP	IO.LaASRFDR	}
    {Qu(LaBrake) 	IO.LaBrake	}
    {Qu(BLS) 		IO.BLS		}
    {Qu(LapTime)	DM.Lap.Time 	}
    {Qu(LapNo)		DM.Lap.No 	}
    {Qu(TriggerPointTime)	DM.TriggerPoint.Time }
    {Qu(TriggerPointDist)	DM.TriggerPoint.Dist }
    {Qu(TriggerPointId)		DM.TriggerPoint.Id   }
}

# max 8 Lights
set LEDs {
    0 "PWR" red   
    2 "ABS" blue 
    3 "ESP" orange
    4 "(o)" red   
    5 "BLS" red
}

set LEDs_MCM {
    0 "PWR" red   
    2 "ABS" blue 
    4 "(o)" red   
    5 "BLS" red
}



## Handle args of command line ################################################

proc PrintUsage {} {
    global HIL Config
puts "
usage: Instruments \[options\]
 -appclass c     restrict connections to appl class c    ($HIL(AcceptClass))
 -appname n      .. to appl named n                      ($HIL(AcceptName))
 -apphost h      .. to appl running on host h n          ($HIL(AcceptHost))
 -appuser u      .. to appl owned by user u              ($HIL(AcceptUser))
 -apppid pid     .. to appl process pid                  ($HIL(AcceptPid))
 -connect        auto-connect after program start
 -maxspeed v     set max speed                           ($Config(MaxSpeed))
 -maxrpm v       set max RPM                             ($Config(MaxRPM))
 -maxstw v       set max steering wheel angle            ($Config(MaxStW))
 -ngears v       set number of gears                     ($Config(nGears))
 -lang l         set user interface language             ($Config(Lang))
 -MCM            MotorCycleMaker mode
"
	exit 1
}

for {set i 0} {$i<$argc} {incr i} {
    set arg [lindex $argv $i]
    switch -glob -- $arg {
     -noPedals { set Config(withPedals) 0 }
     -apphost  { set HIL(AcceptHost)  [lindex $argv [incr i]] }
     -appuser  { set HIL(AcceptUser)  [lindex $argv [incr i]] }
     -appclass { set HIL(AcceptClass) [lindex $argv [incr i]] }
     -apppid   { set HIL(AcceptPid)   [lindex $argv [incr i]] }
     -connect  { after idle Connect }
     -maxspeed { set Config(MaxSpeed) [lindex $argv [incr i]] }
     -maxrpm   { set Config(MaxRPM)   [lindex $argv [incr i]] }
     -maxst*   { set Config(MaxStW)   [lindex $argv [incr i]] }
     -ngears   { set Config(nGears)   [lindex $argv [incr i]] }
     -lang     { set Config(Lang)     [lindex $argv [incr i]] }
     -MCM      { set Config(Mode)     MCM 
     		 set Config(MaxSpeed) 240
		 set Config(MaxRPM)   12000
		 set Config(MaxStW)   50
		 set Config(nGears)   0
		 set LEDs $LEDs_MCM
     	       }
     -*        { PrintUsage }
    }
}

switch -glob -- $Config(Lang) {
 ger*	 { proc l {e g} {return $g} }
 default { proc l {e g} {return $e} }
}

proc MCM {a b} {
    return [expr {$::Config(Mode)=="MCM" ? $a : $b}]
}


## Unter-/Hilfsmodule laden #######

if {![file exists $Pgm(Dir)/Tacho.tcl]} { append Pgm(Dir) "/../GUI/lib" } 
if {![file exists $Pgm(Dir)/Tacho.tcl]} { set Pgm(Dir) "$env(CM_HOME)/GUI/lib" }

load $LibDir/apoc.so

source $Pgm(Dir)/Tacho.tcl
source $Pgm(Dir)/HVBar.tcl
source $Pgm(Dir)/Gearbox.tcl


### Communikation port for remote control (send/dde) ###

tk appname Instruments
if {$Pgm(Arch)=="win32"} { dde servername Instruments }

## APO communication ##################################################################

set ApoId ""


proc Subscribe {{sid ""}} {
    global ApoId HIL Qu Subscription

    foreach qu [dataprocess dictionary $ApoId] {
    	set Dict([lindex $qu 0]) $qu
    }
    foreach sub $Subscription {
	set var [lindex $sub 0]
	for {set i 1} {$i < [llength $sub]} {incr i} {
	    set qu [lindex $sub $i]
	    if {[info exist Dict($qu)]} break
	}
        lappend Subs [list $qu $var]
	set $var 0
    }
    set Rejected [dataprocess subscribe $ApoId 0 100 HandleDataVec $Subs]
    foreach i $Rejected {
	puts "Not available: #$i [lindex $Subs $i 0]"
    }
}


proc Connect {{Target ""}} {
    global ApoId Pgm HIL

    set MyHost [string tolower [lindex [split [info hostname] "."] 0]]
    if {$Target != ""} {
	set HIL(AcceptPid) ""
	if {[scan $Target {%[^: ]:%d} HIL(AcceptHost) HIL(AcceptPid)] != 2} {
	    if {[scan $Target {%d} HIL(AcceptPid)] == 1} { set HIL(AcceptHost) $MyHost }
	}
	set HIL(AcceptHost) [string tolower $HIL(AcceptHost)]
    }

    apoc query 1000 $HIL(AcceptHost)
    while {![apoc querydone]} {after 100; update}

    set SelIndex      -1
    set Sel(AppStart) 0
    set Sel(AppHost)  ""
    set i 0
    foreach s [apoc servers] {
	set Info(AppClass) 	[lindex $s 0]
	set Info(AppName) 	[lindex $s 1]
	set Info(AppInfo)	[lindex $s 2]
	set Info(AppStart)	[lindex $s 5]
	set Info(AppUser)	[lindex $s 6]
	set Info(AppHost)	[lindex $s 7]
	set Info(AppPid)	[lindex $s 8]
	if {($HIL(AcceptUser)==""  || $HIL(AcceptUser)==$Info(AppUser))
	 && ($HIL(AcceptClass)=="" || $HIL(AcceptClass)==$Info(AppClass))
	 && ($HIL(AcceptName)==""  || $HIL(AcceptName)==$Info(AppName))
	 && ($HIL(AcceptHost)==""  || $HIL(AcceptHost)==$Info(AppHost))
	 && ($HIL(AcceptPid)==""   || $HIL(AcceptPid)==$Info(AppPid))} {
	    if {$Info(AppHost)==$MyHost && $Sel(AppHost)!=$MyHost
	     || ($Info(AppHost)==$MyHost) == ($Sel(AppHost)==$MyHost) 
	         	&& $Info(AppStart) > $Sel(AppStart)} {
		set SelIndex $i
		array set Sel [array get Info]
	    }
	}
	incr i
    }
    if {$SelIndex < 0} {return 0}
    Disconnect

    if {[catch {dataprocess new $SelIndex 3} ApoId] != 0} {
	wm title . "$Pgm(Name) - could not connect"
	set ApoId ""
	return
    }
    dataprocess dictchanged $ApoId Subscribe
    wm title . "$Pgm(Name) - '$Sel(AppHost)' online"

    Subscribe
}


proc Disconnect {} {
    catch {dataprocess delete $::ApoId}
    set ::ApoId ""
    wm title . "$::Pgm(Name) - disconnected"
}


proc SendMsg {Channel Msg} {
    catch {dataprocess sendmsg $::ApoId $Channel $Msg}
}


###############################################################################


proc HandleDataVec {sid msgid} {
    global Config Qu LED

    Tacho::SetNeedle .rpm 0 [expr {0.009549*$Qu(nEngine)}]
    Tacho::SetNeedle .spd 0 [expr {$Qu(vCar)*3.6}]
    .spd itemconfig km -text [format "%8.3f" [expr {$Qu(Distance)*0.001}]]
    .rpm itemconfig gear -text [Gearbox::GearName $Qu(GearNo)]

    if {$Config(withPedals)} {
        .lights itemconfigure TrapTime -text [format " %.3f s"       $Qu(TriggerPointTime)]
        .lights itemconfigure TrapId   -text [format " Sector:   %i" $Qu(TriggerPointId)]
        .lights itemconfigure LapTime  -text [format " %.3f s"       $Qu(LapTime)]
        .lights itemconfigure LapNo    -text [format " Lap Time: %i" $Qu(LapNo)]

	HVBar::Set .mid.steer  [expr {$Qu(StWhlAngle)*57.296}]
	HVBar::Set .mid.gas    [expr {100*$Qu(Gas)}]
	HVBar::Set .mid.brake  [expr {100*$Qu(Brake)}]
	HVBar::Set .mid.brake2 [expr {100*$Qu(BrakeLever)}]
	HVBar::Set .mid.clutch [expr {100*$Qu(Clutch)}]
	if {$Config(nGears)>0} {
	    Gearbox::Set .gear.no $Qu(GearNo)
	}
	.lights.l0.l configure -bg $LED(0,$Qu(Kl15SW))
	.lights.l1.l configure -bg $LED(5,$Qu(BLS))
    }
}


################################################################################


proc CreateDialog {} {
    global simData Config Pref Pgm
    upvar #0 simData v

    wm title . "$Pgm(Name) $Pgm(Version) $Pgm(VersionDate)"
    wm iconname . $Pgm(Name)
    wm protocol  . WM_DELETE_WINDOW ProgramExit
    wm resizable . 0 0
    catch {wm geo . $Pref(WindowPos.Main)}

    frame .top -relief raised -bd 1

    ## Tacho
    Tacho::Create .spd -width 250 -height 200 -scaledist 0.72 \
	    -max $Config(MaxSpeed) \
	    -major 20 -nminor 5
    .spd create text 125 95 -text "km/h" -anchor center -fill white \
	    -font {Helvetica -16} -tags bg
    .spd create rect 92 166 158 182 -fill grey20 -outline grey40 -tags bg
    .spd create text 156 175 -text "0.000" -anchor e -fill grey90 \
	    -font {Helvetica -14 bold} -tags km
    .spd lower bg needles

    ## Motor RPM
    Tacho::Create .rpm -width 250 -height 200 \
	    -max [expr $Config(MaxRPM)/1000] \
	    -major 2 -nminor 5
    .rpm create text 125 93 -text "[l "rpm" "U/min"]\nx 1000" \
    	    -anchor center -ju c -fill white -font {Helvetica -16} -tags bg
    .rpm create rect 110 156 140 185 -fill grey20 -outline grey40 -tags bg
    .rpm create text 125 171 -anchor center -fill grey90 \
	    -font {Helvetica -24 bold} -tags gear
    .rpm lower bg needles

    grid .spd .rpm -in .top -row 0 -sticky we

    if {$Config(withPedals)} {
	## Control Lights
        global LED LEDs
	set cv .lights
	canvas $cv -width 100 -height 170 -relief raised -bd 1
	foreach {i txt co} $LEDs {
	    set LED($i,0)   grey70
	    set LED($i,1)   $co
	    set LED($i,txt) $txt
	}
	for {set i 0} {$i<2} {incr i} {
	    if {![info exists LED($i,0)]} {
		set LED($i,0)   grey70
		set LED($i,1)   red
		set LED($i,txt) ""
	    }
	    set x [expr 9 + $i%2 * 45]
	    set y [expr 9 + $i/2 * 40]
	    frame $cv.l$i -relief sunken -bd 1
	    label $cv.l$i.l -fg white -text $LED($i,txt)
	    pack  $cv.l$i.l -padx 1 -pady 1 -fill both -expand 1
	    $cv create window $x $y -anchor nw -width 40 -height 32 -window $cv.l$i
	}
	bind $cv.l0.l <ButtonPress>   { SendMsg 2 "Kl15\0"; %W configure -relief sunken }
	bind $cv.l0.l <ButtonRelease> {                   %W configure -relief flat }

	## Laptime
        .lights create text 50  90 -text 0 -anchor center -fill blue  -font {Helvetica -16 bold} -tags TrapId
        .lights create text 50 110 -text 0 -anchor center -fill black -font {Helvetica -14 bold} -tags TrapTime
        .lights create text 50 130 -text 0 -anchor center -fill blue  -font {Helvetica -16 bold} -tags LapNo
        .lights create text 50 150 -text 0 -anchor center -fill red   -font {Helvetica -14 bold} -tags LapTime
	
	frame .mid -relief raised -bd 1

	## Steering Wheel
	set txt [MCM [l "Steering Angle \[deg]" "Lenkwinkel \[Grad]"] \
	    	     [l "Steering Wheel Angle \[deg]" "Lenkradwinkel \[Grad]"] ]
	HVBar::Create .mid.steer -mode needle -width [MCM 280 250] -height 64 \
		-title $txt -color #1e1 \
		-min -$Config(MaxStW) -max $Config(MaxStW) -inverse \
		-major [MCM 10 90] -nminor [MCM 5 3]
	
	## Clutch
	HVBar::CreateVBar .mid.clutch -width 65 -height 100 -major 20 -color #11f \
		-title [l "Clutch" "Kupplung"] -unit "%" 
	
	## Gas Pedal
	HVBar::CreateVBar .mid.gas -width 65 -height 100 -major 20 -color #1e1 \
		-title "Gas" -unit "%" 
	
	## Brake Pedal
	HVBar::CreateVBar .mid.brake -width 75 -height 100 -major 20 -color #f11 \
		-title [MCM [l "Brake Pedal" "Bremspedal"] [l "Brake" "Bremse"]] -unit "%"
	
	## Brake Lever
	HVBar::CreateVBar .mid.brake2 -width 75 -height 100 -major 20 -color #f11 \
		-title [l "Brake Lever" "Bremshebel"] -unit "%"
	
	## Gearbox
	frame .gear -relief raised -bd 1
	if {$Config(Mode)!="MCM" && $Config(nGears)>0} {
	    label .gear.la -text [l "Gearbox" "Schaltung"] 
	    Gearbox::Create .gear.no -width 110 -height 120 -n $Config(nGears)
	    pack .gear.la -side top -anchor n -pady 3
	    pack .gear.no -side top -expand 1
	}
    }

    grid .top -columnspan 6 -sticky we

    if {$Config(withPedals)} {
	grid .lights -row 1 -column 0 -sticky news
	grid .mid    -row 1 -column 1 -sticky news
	grid .gear   -row 1 -column 2 -sticky news
	grid columnconfig . 1 -weight 1
	grid columnconfig . 2 -minsize 100 -weight 1

	grid x .mid.steer - - - -sticky news
	if {$Config(Mode)=="MCM"} {
	    grid x .mid.clutch .mid.brake .mid.brake2 .mid.gas 
	} {
	    grid x .mid.clutch .mid.brake .mid.gas -sticky ews
	}
	grid columnconfig .mid 0 -weight 1 
	grid columnconfig .mid 5 -weight 1
    }

    ## Initialize Instruments
    Tacho::SetNeedle .spd 0 0
    Tacho::SetNeedle .rpm 0 0

    ## Context menu
    set m [menu .cmenu -tearoff 0]
    $m add com -lab "Connect"    -u 0 -comm Connect
    $m add com -lab "Disconnect" -u 0 -comm Disconnect
    $m add com -lab "Exit"       -u 2 -comm ProgramExit
    bind all <Button-3> "tk_popup .cmenu %X %Y"
}


## Preferences ###################################

array set Pref {			
    WindowPos.Main	""
}
catch {source ~/.instruments.rc}


proc PrefSave {} {
    global Pref
    scan [wm geo .] "%*dx%*d%s" Pref(WindowPos.Main)
    catch {
        set fd [open "~/.instruments.rc" w]
        foreach n [array names Pref] { puts $fd "set Pref($n) $Pref($n)" }
	close $fd
    }
}


## MAIN ##########################################

proc ProgramExit {} {
    PrefSave
    exit
}

CreateDialog
bind all <Key-F2> 	{SendMsg 2 "Kl15\0"}
bind all <Control-Key-q> "ProgramExit"
bind all <Alt-Key-x>     "ProgramExit"

apoc pollinterval 100

