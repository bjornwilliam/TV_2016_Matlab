## **********************************************************************
## FileCreator 	CarMaker
## FileName 	FS_RaceCar.tcl
## Description: Formula Student Race Car
## 		wheel base 1600.0 mm
## 		track width front 1200.0 mm
## 		track width rear 1150.0 mm
## 		tire 195/50 R13
## **********************************************************************
set Scale 1.5

proc DefineCarTop {cv {col gray} {ShowDetails 0}} {

## Wheels
    $cv create rectangle 25     49.95 75   69.45 -fill black -outline black -tag tire
    $cv create rectangle 25    -69.45 75  -49.95 -fill black -outline black -tag tire
    $cv create rectangle 185.0  49.95 235  69.45 -fill black -outline black -tag tire
    $cv create rectangle 185.0 -69.45 235 -49.95 -fill black -outline black -tag tire

## 2 first values: coordinates of the 1st point, 2 last values: coordinates of the final point
    ## upper half of the car
       ## main body 
    $cv create line 25 30 25 0 -fill $col
    $cv create line 25 30 35 37 -fill $col
    $cv create line 35 37 225 37 -fill $col
    $cv create line 225 37 245 36 -fill $col
    $cv create line 245 36 285 31 -fill $col
    $cv create line 285 31 305 26 -fill $col
    $cv create line 305 26 315 15 -fill $col
    $cv create line 315 15 320 -1 -fill $col
       ## side eir intake
    $cv create line 95 37 95 65 -fill $col
    $cv create line 95 65 98 70 -fill $col
    $cv create line 98 70 125 70 -fill $col
    $cv create line 125 70 165 65 -fill $col
    $cv create line 165 65 185 37 -fill $col
       ## cockpit
    $cv create line 85 0 87 27 -fill $col
    $cv create line 87 27 91 30 -fill $col
    $cv create line 91 30 155 29 -fill $col
    $cv create line 155 29 175 24 -fill $col
    $cv create line 175 24 185 8 -fill $col
    $cv create line 185 8 185 0 -fill $col
       ## wishbones
    $cv create line  45 50 32 37 -fill $col
    $cv create line  55 50 72 37 -fill $col
    $cv create line 206 50 191 37 -fill $col
    $cv create line 220 50 233 37 -fill $col


    ## bottom half of the car
       ## main body
    $cv create line 25 -30 25 1 -fill $col
    $cv create line 25 -30 35 -37 -fill $col
    $cv create line 35 -37 225 -37 -fill $col
    $cv create line 225 -37 245 -36 -fill $col
    $cv create line 245 -36 285 -31 -fill $col
    $cv create line 285 -31 305 -26 -fill $col
    $cv create line 305 -26 315 -15 -fill $col
    $cv create line 315 -15 320 0 -fill $col
       ## side air intake
    $cv create line 95 -37 95 -65 -fill $col
    $cv create line 95 -65 98 -70 -fill $col
    $cv create line 98 -70 125 -70 -fill $col
    $cv create line 125 -70 165 -65 -fill $col
    $cv create line 165 -65 185 -37 -fill $col
       ## cockpit
    $cv create line 85 0 87 -27 -fill $col
    $cv create line 87 -27 91 -30 -fill $col
    $cv create line 91 -30 155 -29 -fill $col
    $cv create line 155 -29 175 -24 -fill $col
    $cv create line 175 -24 185 -8 -fill $col
    $cv create line 185 -8 185 0 -fill $col
       ## wishbones
    $cv create line  45 -50 32 -37 -fill $col
    $cv create line  55 -50 72 -37 -fill $col
    $cv create line 206 -50 191 -37 -fill $col
    $cv create line 220 -50 233 -37 -fill $col






}
proc DefineCarSide {cv {col gray} {ShowDetails 0}} {
    ## Wheels
    $cv create oval 25 -2.5 75 54.5 -outline $col -fill black
    $cv create oval 33 8.2 67 43.8 -outline $col -fill grey
    $cv create oval 185 -2.5 235 54.5 -outline $col -fill black
    $cv create oval 193 8.2 227 43.8 -outline $col -fill grey

    ## main body
    $cv create line 68 5 195 5 -fill $col
    $cv create line 225 5 250 5 -fill $col
    $cv create line 250 5 280 8 -fill $col
    $cv create line 280 8 310 25 -fill $col
    $cv create line 310 25 310 35 -fill $col
    $cv create line 310 35 275 52 -fill $col
    $cv create line 275 52 260 57 -fill $col
    $cv create line 260 57 220 65 -fill $col
    $cv create line 220 65 180 67 -fill $col
    $cv create line 180 67 155 67 -fill $col
    $cv create line 155 67 145 60 -fill $col
    $cv create line 145 60 100 60 -fill $col
    $cv create line 100 60 95 65 -fill $col
    $cv create line 95 65 80 65 -fill $col
    $cv create line 80 65 85 45 -fill $col
    $cv create line 85 45 85 30 -fill $col

    ## side air intake
    $cv create line 75 30 150 30 -fill $col
    $cv create line 150 30 130 20 -fill $col
    $cv create line 130 20 120 5 -fill $col
    $cv create line 75 30 130 20 -fill $col
    $cv create line 150 30 145 5 -fill $col

    ## exhaust
    $cv create line 70 45 85 45 -fill $col
    $cv create line 30 45 25 45 -fill $col
    $cv create line 25 45 25 60 -fill $col
    $cv create line 25 60 80 60 -fill $col

    ## protections
    $cv create line 50 60 80 85 -fill $col
    $cv create line 60 60 82 78 -fill $col
    $cv create line 80 65 80 88 -fill $col
    $cv create line 80 88 90 88 -fill $col
    $cv create line 90 88 90 65 -fill $col



}
