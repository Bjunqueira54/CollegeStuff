breed [Flies Fly]
breed [Sflies sfly]
breed [Eggs Egg]

turtles-own [energy]
Eggs-own [spawntick]

to Setup
  clear-all
  reset-ticks
  setup-patches
  setup-turtles
End

to setup-patches
  ask patches with [pcolor = black]
  [
    if random 101 < pFood
    [
      set pcolor brown
    ]
  ]
End

to setup-turtles
  create-flies nFlies
  [
    set color green
    setxy random-xcor random-ycor
    while [pcolor = brown]
    [
      setxy random-xcor random-ycor
    ]
  ]
  create-sflies nSflies
  [
    set color yellow
    setxy random-xcor random-ycor
    while [pcolor = brown]
    [
      setxy random-xcor random-ycor
    ]
  ]

  ask turtles
  [
    set shape "butterfly"
    set energy random 100
    set heading 0
  ]
End

to Go
  move-sflies
  move-flies

  ask turtles
  [
    if(energy <= 0)
    [
      die
    ]
  ]

  if count turtles = 0
  [
    stop
  ]
  tick
End

to move-sflies
  ask Sflies
  [
    fd 1
    set energy energy - 1
  ]
End

to move-flies
  ask Flies
  [
    fd 1
    set energy energy - 1
  ]
End
