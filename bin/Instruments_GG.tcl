#!/bin/sh
# the next line restarts using wish \
exec wish8.4 "$0" -- "$@"
#
# GG.tcl
#
# Copyright (c) IPG Automotive GmbH, Karlsruhe, Germany (www.ipg.de)

set Pgm(Dir)  [file dirname [info script]]
set Pgm(Arch) [expr {$tcl_platform(os)=="Linux" ? "linux" : "win32"}]
catch { set env(HOME) $env(USERPROFILE) }

set Pgm(Name)           "GG Diagram"
set Pgm(Version)	"1.1"
set Pgm(VersionDate)    "2008-04-07"

option add "*Label.Font" "Helvetica -12 bold" widgetDefault

array set HIL {
    AcceptHost  ""
    AcceptPid   ""
    AcceptUser  ""
    AcceptClass	""
    AcceptName	""
}

array set Config {
    MaxAx 	1.5
    MaxAy 	2.0
    Lang        english
    Mode	CM
}

# Subscription = list of variables to be subscriped
#   Tcl var             quantity        alternate quantities
set Subscription {
    {Qu(axCar)		Car.Con.atHori 	}
    {Qu(ayCar)		Car.Con.alHori 	}
}


## Handle args of command line ################################################

proc PrintUsage {} {
    global HIL Config
puts "
usage: Instruments \[options\]
 -appclass c	restrict connections to appl class c    ($HIL(AcceptClass))
 -appname n	.. to appl named n                      ($HIL(AcceptName))
 -apphost h	.. to appl running on host h n          ($HIL(AcceptHost))
 -appuser u	.. to appl owned by user u              ($HIL(AcceptUser))
 -apppid pid	.. to appl process pid                  ($HIL(AcceptPid))
 -connect	auto-connect after program start
 -maxax	ax	set max acceleration ax			($Config(MaxAx))
 -maxay	ay	set max acceleration ay			($Config(MaxAy))
"
	exit 1
}

for {set i 0} {$i<$argc} {incr i} {
    set arg [lindex $argv $i]
    switch -glob -- $arg {
     -appclass	{ set HIL(AcceptClass)	[lindex $argv [incr i]] }
     -apphost	{ set HIL(AcceptHost)	[lindex $argv [incr i]] }
     -appuser	{ set HIL(AcceptUser)	[lindex $argv [incr i]] }
     -apppid	{ set HIL(AcceptPid)	[lindex $argv [incr i]] }
     -connect	{ after idle Connect }
     -maxax	{ set Config(MaxAx)	[lindex $argv [incr i]] }
     -maxay	{ set Config(MaxAy)	[lindex $argv [incr i]] }
     -*		{ PrintUsage }
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
    global Config Qu

	if {$Qu(axCar) == 0} {
            HVBar__Set .gg.ax_plus   [expr {0}]
            HVBar__Set .gg.ax_minus  [expr {0}]
        } elseif {$Qu(axCar) > 0} {
            HVBar__Set .gg.ax_plus   [expr {$Qu(axCar)/9.81}]
            HVBar__Set .gg.ax_minus  [expr {0}]
        } elseif {$Qu(axCar) < 0} {
            HVBar__Set .gg.ax_plus   [expr {0}]
            HVBar__Set .gg.ax_minus  [expr {$Qu(axCar)/9.81}]
	}

        if {$Qu(ayCar) == 0} {
            HVBar__Set .gg.ay_plus   [expr {0}]
            HVBar__Set .gg.ay_minus  [expr {0}]
        } elseif {$Qu(ayCar) >= 0} {
            HVBar__Set .gg.ay_plus   [expr {$Qu(ayCar)/9.81}]
            HVBar__Set .gg.ay_minus  [expr {0}]
        } elseif {$Qu(ayCar) < 0} {
            HVBar__Set .gg.ay_plus   [expr {0}]
            HVBar__Set .gg.ay_minus  [expr {$Qu(ayCar)/9.81}]
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

    ## GG
    frame .gg -relief raised -bd 1
    set MaxAx $Config(MaxAx)
    set MaxAy $Config(MaxAy)
    set wi 18
    HVBar__Create     .gg.ay_plus  -mode bar_minus -width  72 -height $wi -min 0       -max $MaxAy -title "" -unit "" -color yellow
    HVBar__Create     .gg.ay_minus -mode bar_plus  -width  72 -height $wi -min -$MaxAy -max 0      -title "" -unit "" -color yellow
    HVBar__CreateVBar .gg.ax_plus  -mode bar_plus  -width $wi -height  72 -min 0       -max $MaxAx -title "" -unit "" -color #1e1
    HVBar__CreateVBar .gg.ax_minus -mode bar_minus -width $wi -height  72 -min -$MaxAx -max 0      -title "" -unit "" -color #f11
                             
    label .gg.t0 -text G -font {Helvetica -14 bold}
    label .gg.t1 -text  $MaxAy
    label .gg.t2 -text -$MaxAy
    label .gg.t3 -text  $MaxAx
    label .gg.t4 -text -$MaxAx

    label .gg.t5 -text "Turn Right"
    label .gg.t6 -text "Turn Left"
    label .gg.t7 -text "Throttle"
    label .gg.t8 -text "Brake"

    grid .gg          -row 1 -column 1 -sticky news

    grid .gg.ay_plus  -row 1 -column 2 -sticky we
    grid .gg.ay_minus -row 1 -column 0 -sticky we
    grid .gg.ax_plus  -row 0 -column 1 -sticky ns
    grid .gg.ax_minus -row 2 -column 1 -sticky ns

    grid .gg.t0       -row 1 -column 1

    grid .gg.t1       -row 2 -column 2 -sticky ne
    grid .gg.t2       -row 2 -column 0 -sticky nw
    grid .gg.t3       -row 0 -column 0 -sticky ne
    grid .gg.t4       -row 2 -column 0 -sticky se

    grid .gg.t5       -row 0 -column 0 -sticky sw
    grid .gg.t6       -row 0 -column 2 -sticky se
    grid .gg.t7       -row 0 -column 2 -sticky nw
    grid .gg.t8       -row 2 -column 2 -sticky sw

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
catch {source ~/.gg.rc}


proc PrefSave {} {
    global Pref
    scan [wm geo .] "%*dx%*d%s" Pref(WindowPos.Main)
    catch {
        set fd [open "~/.gg.rc" w]
        foreach n [array names Pref] { puts $fd "set Pref($n) $Pref($n)" }
	close $fd
    }
}


## HVBar_Special #################################


proc HVBar__Create {w args} {
    global Pgm
    upvar #0 HVBar::v$w v

    set sx		300
    set sy		220

    set title		""
    set unit		""

    set scaleform	"%g"
    set scalefont	"Helvetica -10"
    set colbar		LightSeaGreen

    array set v {
	Min		0.0
	Max		100.0
	Major		10.0
	nMinor		2

	Mode		bar
	Orientation	h
	Length		100

	Min0		0
	Min1		0
	Max0		0
	Max1		0
	Factor		0
	Inverse         0
    }

    for {set i 0} {[set arg [lindex $args $i]] != ""} {incr i} {
	switch -glob -- $arg {
	    -width	{ set sx [lindex $args [incr i]] }
	    -height	{ set sy [lindex $args [incr i]] }
	    -color      { set colbar [lindex $args [incr i]] }
	    -min	{ set v(Min) [lindex $args [incr i]] }
	    -max	{ set v(Max) [lindex $args [incr i]] }
	    -title	{ set title [lindex $args [incr i]] }
	    -unit	{ set unit [lindex $args [incr i]] }
	    -format	{ set scaleform [lindex $args [incr i]] }
	    -major	{ set v(Major) [lindex $args [incr i]] }
	    -nminor	{ set v(nMinor) [lindex $args [incr i]] }
	    -orient*    { set v(Orientation) [string range [lindex $args [incr i]] 0 0] }
	    -mode       { set v(Mode) [lindex $args [incr i]] }
	    -inverse	{ set v(Inverse) 1 }
	    -hor*	{ set v(Horizontal) 1 }
	}
    }

    canvas $w -width $sx -height $sy

    set v(Min) [expr double($v(Min))]
    set v(Max) [expr double($v(Max))]
    set v(Major) [expr double($v(Major))]
    HVBar::CalcScale $w

    if {$v(Orientation)=="h"} {
	# Titel und Einheit.
	set toff 10
	set x [expr $sx / 2]
	$w create text $x $toff -text "$title" -font "Helvetica -12 bold"

	# Box.
	set boff 10
	set v(MinX) $boff
	set v(MaxX) [expr $sx - $boff]

	## Special GG
	switch -- $v(Mode) {
	    bar_plus  { 
		set v(MinX) [expr $boff + 1] 
		set v(MaxX) [expr $sx - 2]
            }
	    bar_minus { 
		set v(MaxX) [expr $sx - $boff]
		set v(MinX) [expr + 1] 
            }
	}

	set v(MinY) [expr $sy/2 - 8]
	set v(MaxY) [expr $sy/2 + 8]
	set v(Factor) [expr {($v(MaxX)-$v(MinX)) / $v(Delta)}]

	$w create rect $v(MinX) $v(MinY) $v(MaxX) $v(MaxY) -fill "white" -outline black
	$w create rect 0 0 0 0 -fill $colbar -tags bar

	## Special GG
	switch -- $v(Mode) {
	    bar_plus  { 
		$w create polygon $v(MinX) $v(MinY) $v(MinX) $v(MaxY) [expr $v(MinX) - 8] [expr $v(MaxY) - 8] -fill $colbar -outline black
	    }
	    bar_minus { 
		$w create polygon $v(MaxX) $v(MinY) $v(MaxX) $v(MaxY) [expr $v(MaxX) + 8] [expr $v(MaxY) - 8] -fill $colbar -outline black
	    }

	}

    } {
	# Titel und Einheit.
	set toff 9
	set x [expr $sx / 2]
	set y $toff
	$w create text $x $y -text $title -font "Helvetica -12 bold" -anchor center
	set y [expr $sy - $toff]
	$w create text $x $y -text $unit -font "Helvetica -12" -anchor center

	# Box.
	set boff 10
	set v(MinX) [expr $sx/2 - 8]
	set v(MaxX) [expr $sx/2 + 8]
	set v(MinY) $boff
	set v(MaxY) [expr $sy - $boff]

	## Special GG
	switch -- $v(Mode) {
	    bar_plus  { 
		set v(MinY) [expr $boff + 1] 
		set v(MaxY) [expr $sy - 2]
            }
	    bar_minus { 
		set v(MaxY) [expr $sy - $boff]
		set v(MinY) [expr + 1] 
            }
	}

	set v(Factor) [expr ($v(MaxY) - $v(MinY)) / $v(Delta)]
	$w create rect $v(MinX) $v(MinY) $v(MaxX) $v(MaxY) -fill "white" -outline black
	$w create rect 0 0 0 0 -fill $colbar -tags bar

	## Special GG
	switch -- $v(Mode) {
	    bar_plus  {
		$w create polygon $v(MinX) $v(MinY) $v(MaxX) $v(MinY) [expr $v(MinX)+8] [expr $v(MinY)-8] -fill $colbar -outline black
	    }
	    bar_minus {
		$w create polygon $v(MinX) $v(MaxY) $v(MaxX) $v(MaxY) [expr $v(MaxX)-8] [expr $v(MaxY)+8] -fill $colbar -outline black
	    }

	}

    }
    HVBar__Set $w 0
    return $w
}



proc HVBar__Set {w val} {
    upvar #0 HVBar::v$w v

    if {$v(Inverse)} {set val [expr {-$val}]}
    if {$v(Orientation)=="h"} {
	set e [expr {$v(MinX) + ($val-$v(Min))*$v(Factor)}]
	switch -- $v(Mode) {
	 bar       { $w coords bar $e $v(MinY) $v(MaxX) $v(MaxY) }
	 needle    { $w coords bar [expr $e-2] $v(MinY) [expr $e+2] $v(MaxY) }
	 bar_plus  { $w coords bar $e       $v(MinY) $v(MaxX) $v(MaxY) }
	 bar_minus { $w coords bar $v(MinX) $v(MinY) $e       $v(MaxY) }
	}
    } {
    	set e [expr $v(MaxY) - ($val - $v(Min))*$v(Factor)]
	switch -- $v(Mode) {
	 bar       { $w coords bar $v(MinX) $e $v(MaxX) $v(MaxY) }
	 needle    { $w coords bar $v(MinX) [expr $e-2] $v(MaxX) [expr $e+2] }
	 bar_plus  { $w coords bar $v(MinX) $e       $v(MaxX) $v(MaxY) }
	 bar_minus { $w coords bar $v(MinX) $v(MinY) $v(MaxX) $e       }
	}
    }
}


proc HVBar__CreateVBar {w args} {
    eval HVBar__Create $w -orient vert $args
}


## MAIN ##########################################

proc ProgramExit {} {
    PrefSave
    exit
}

CreateDialog
bind all <Control-Key-q> "ProgramExit"
bind all <Alt-Key-x>     "ProgramExit"

apoc pollinterval 100

