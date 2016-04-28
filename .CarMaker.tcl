### CarMaker Specials
source bin/FileConverter.tcl
menubutton .mbar.special -text [l "Specials" "Spezial"] -menu .mbar.special.m
pack .mbar.special -side left
set m [menu .mbar.special.m]
$m add com -lab "Instruments FS"                            -command {StartTool bin/Instruments_FS.tcl}
$m add com -lab [l "GG Diagram" "GG Diagramm"]              -command {StartTool bin/Instruments_GG.tcl}
$m add com -lab [l "File Converter" "Datei Konvertierer"]   -command {FC::Popup}
