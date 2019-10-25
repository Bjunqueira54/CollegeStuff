breed [Eaters Eater]
breed [Cleaners Cleaner]
breed [Sick Biohazard]

turtles-own [energy]
cleaners-own [cargo toxicity destx desty]
eaters-own [toxicity]

to Setup
  clear-all
  reset-ticks
  Setup-patches
  Setup-agents
End

to Go
  eaters-proc
  cleaners-proc
  kill ; verify energy

  if SickAgents?
  [
    chernobyl-proc ; turn sick
  ]

  if count turtles = 0 ; terminate simulation
  [ stop ]

  if ticks = 5000
  [ stop ]

  replenish-patches

  tick
End

to Setup-patches
  ask patches with [pcolor = black]
  [
    if random 101 < nGarbage
    [
      set pcolor yellow
    ]

    if random 101 < nToxic
    [
      set pcolor red
    ]

    if random 101 < nFood
    [
      set pcolor green
    ]
  ]

  ask n-of nDeposits patches with [pcolor = black]
  [
    set pcolor blue
  ]
End

to Setup-agents
  create-eaters nEaters
  [
    set color pink
    setxy random-xcor random-ycor
    while [pcolor != black]
    [
      setxy random-xcor random-ycor
    ]
    set size 1

    ifelse random 101 < 50
    [set heading 0]
    [set heading 90]
  ]

  create-cleaners nCleaners
  [
    set color orange
    setxy random-xcor random-ycor
    while [pcolor != black]
    [
      setxy random-xcor random-ycor
    ]
    set size 1

    ifelse random 101 < 50
    [set heading 180]
    [set heading -90]

    set cargo 0
    set desty 1337
    set destx 1337
  ]

  ask turtles
  [
    set energy sEnergy
    set toxicity 0
    set xcor (precision xcor 0)
    set ycor (precision ycor 0)
    ;set shape "person"
  ]
End

to eaters-proc
  ask eaters
  [
    ifelse pcolor = green
    [
      ask patch-here
      [
        set pcolor black
      ]

      set energy energy + fEnergy
    ]
    [
      ifelse priorityEaters = "I_Want_Food"
      [
        if eaters-look-for-food = 0 ; report 1 if food was found, 0 if not
        [ ; no food
          if gtfo = 0 ; report 1 if trash was found, 0 if not
          [ ; no trash
            random-action-eaters
          ]
        ]
      ]
      [
        if gtfo = 0 ; report 1 if trash was found, 0 if not
        [ ; no trash
          if eaters-look-for-food = 0 ; report 1 if food was found, 0 if not
          [ ; no food
            random-action-eaters
          ]
        ]
      ]
    ]
  ]
End

to-report eaters-look-for-food
  if [pcolor] of patch-ahead 1 = green
  [
    fd 1
    set energy energy - 1
    report 1
  ]

  if [pcolor] of patch-left-and-ahead 90 1 = green
  [
    rt -90
    set energy energy - 1
    report 1
  ]

  if [pcolor] of patch-right-and-ahead 90 1 = green
  [
    rt 90
    set energy energy - 1
    report 1
  ]

  if turtlesExtraPerception?
  [
    if [pcolor] of patch-left-and-ahead 45 1 = green
    [
      fd 1
      set energy energy - 1
      report 1
    ]

    if [pcolor] of patch-right-and-ahead 45 1 = green
    [
      fd 1
      set energy energy - 1
      report 1
    ]

    if [pcolor] of patch-left-and-ahead 135 1 = green
    [
      rt -90
      set energy energy - 1
      report 1
    ]

    if [pcolor] of patch-right-and-ahead 135 1 = green
    [
      rt 90
      set energy energy - 1
      report 1
    ]
  ]

  report 0
End

to-report gtfo
  let per 0
  let return 0

  if ([pcolor] of patch-ahead 1 = red) or ([pcolor] of patch-ahead 1 = yellow) or ([pcolor] of patch-ahead 1 = violet)
  [
    set per energy / 100

    ; test ahead
    set return determine-bad 0

    ifelse SickAgents?
    [
      if return = 1
      [
        set per per * 5
        set toxicity toxicity + 5
      ]
      if return = 2
      [
        set per per * 10
        set toxicity toxicity + 10
      ]
      if return = 3
      [
        set toxicity toxicity + radioactivePatchLevel
      ]
    ]
    [
      ifelse return = 1 ; 1 for yellow
      [ set per per * 5 ] ; aparentemente isto não é bem 5%
      [ set per per * 10 ]
    ]

    set energy energy - per

    ifelse determine-bad 1 = 0
    [ rt -90 ]
    [
    ifelse determine-bad 2 = 0
      [ rt 90 ]
      [
        ifelse random 101 < 50
        [ rt 90 ]
        [ rt -90 ]
      ]
    ]

    set energy energy - 1

    report 1
  ]

  if ([pcolor] of patch-left-and-ahead 90 1 = red) or ([pcolor] of patch-left-and-ahead 90 1 = yellow) or ([pcolor] of patch-left-and-ahead 90 1 = violet)
  [
    set per energy / 100

    ; test left
    set return determine-bad 1

    ifelse SickAgents?
    [
      if return = 1
      [
        set per per * 5
        set toxicity toxicity + 5
      ]
      if return = 2
      [
        set per per * 10
        set toxicity toxicity + 10
      ]
      if return = 3
      [
        set toxicity toxicity + radioactivePatchLevel
      ]
    ]
    [
      ifelse return = 1 ; 1 for yellow
      [ set per per * 5 ] ; aparentemente isto não é bem 5%
      [ set per per * 10 ]
    ]

    set energy energy - per

    fd 1
    set energy energy - 1

    report 1
  ]

  if ([pcolor] of patch-right-and-ahead 90 1 = red) or ([pcolor] of patch-right-and-ahead 90 1 = yellow) or ([pcolor] of patch-right-and-ahead 90 1 = violet)
  [
    set per energy / 100

    ; test right
    set return determine-bad 2

    ifelse SickAgents?
    [
      if return = 1
      [
        set per per * 5
        set toxicity toxicity + 5
      ]
      if return = 2
      [
        set per per * 10
        set toxicity toxicity + 10
      ]
      if return = 3
      [
        set toxicity toxicity + radioactivePatchLevel
      ]
    ]
    [
      ifelse return = 1 ; 1 for yellow
      [ set per per * 5 ] ; aparentemente isto não é bem 5%
      [ set per per * 10 ]
    ]

    set energy energy - per

    fd 1
    set energy energy - 1

    report 1
  ]

  if turtlesExtraPerception? ; switch extra perceptions
  [
    if ([pcolor] of patch-left-and-ahead 45 1 = red) or ([pcolor] of patch-left-and-ahead 45 1 = yellow) or ([pcolor] of patch-left-and-ahead 45 1 = violet)
    [
      set per energy / 100

      ; test left and ahead
      set return determine-bad 3

      ifelse SickAgents?
    [
      if return = 1
      [
        set per per * 5
        set toxicity toxicity + 5
      ]
      if return = 2
      [
        set per per * 10
        set toxicity toxicity + 10
      ]
      if return = 3
      [
        set toxicity toxicity + radioactivePatchLevel
      ]
    ]
    [
      ifelse return = 1 ; 1 for yellow
      [ set per per * 5 ] ; aparentemente isto não é bem 5%
      [ set per per * 10 ]
    ]

      set energy energy - per

      rt 90 ; left and ahead - turn right
      set energy energy - 1

      report 1
    ]

    if ([pcolor] of patch-left-and-ahead 135 1 = red) or ([pcolor] of patch-left-and-ahead 135 1 = yellow) or ([pcolor] of patch-left-and-ahead 135 1 = violet)
    [
      set per energy / 100

      ; test left and back
      set return determine-bad 5

      ifelse SickAgents?
    [
      if return = 1
      [
        set per per * 5
        set toxicity toxicity + 5
      ]
      if return = 2
      [
        set per per * 10
        set toxicity toxicity + 10
      ]
      if return = 3
      [
        set toxicity toxicity + radioactivePatchLevel
      ]
    ]
    [
      ifelse return = 1 ; 1 for yellow
      [ set per per * 5 ] ; aparentemente isto não é bem 5%
      [ set per per * 10 ]
    ]

      set energy energy - per

      fd 1 ; left and back - ahead
      set energy energy - 1

      report 1
    ]

    if ([pcolor] of patch-right-and-ahead 45 1 = red) or ([pcolor] of patch-right-and-ahead 45 1 = yellow) or ([pcolor] of patch-right-and-ahead 45 1 = violet)
    [
      set per energy / 100

      ; test right and ahead
      set return determine-bad 4

      ifelse SickAgents?
    [
      if return = 1
      [
        set per per * 5
        set toxicity toxicity + 5
      ]
      if return = 2
      [
        set per per * 10
        set toxicity toxicity + 10
      ]
      if return = 3
      [
        set toxicity toxicity + radioactivePatchLevel
      ]
    ]
    [
      ifelse return = 1 ; 1 for yellow
      [ set per per * 5 ] ; aparentemente isto não é bem 5%
      [ set per per * 10 ]
    ]

      set energy energy - per

      rt -90 ; right and ahead - turn left
      set energy energy - 1

      report 1
    ]

    if ([pcolor] of patch-right-and-ahead 135 1 = red) or ([pcolor] of patch-right-and-ahead 135 1 = yellow) or ([pcolor] of patch-right-and-ahead 135 1 = violet)
    [
      set per energy / 100

      ; test left and back
      set return determine-bad 6

      ifelse SickAgents?
      [
        if return = 1
        [
          set per per * 5
          set toxicity toxicity + 5
        ]
        if return = 2
        [
          set per per * 10
          set toxicity toxicity + 10
        ]
        if return = 3
        [
          set toxicity toxicity + radioactivePatchLevel
        ]
      ]
      [
        ifelse return = 1 ; 1 for yellow
        [ set per per * 5 ] ; aparentemente isto não é bem 5%
        [ set per per * 10 ]
      ]

      set energy energy - per

      fd 1 ; right and back - ahead
      set energy energy - 1

      report 1
    ]
  ]

  ;criar um proc para descobrir se é
  ;amarelo ou vermelho
  ;EXEMPLO: to-report find-bad [typeflag]

  ;onde devolve 1 ou 2 se for amarelo ou vermelho respectivamente
  ;recebe typeflag como argumento para saber se verifica a frente,
  ;a esquerda ou a direita. EXEMPLO: find-bad 0 (vai verificar a patch-ahead)
  ;find-bad 1 (vai verificar a patch da esquerda)

  ;usar o valor reportado nesta funçao "gtfo" para saber o que fazer

  report 0; para na função que chamou isto saber que afinal não existe lixo\toxico a volta do agente
End

;Arguments: 0 = ahead, 1 = left, 2 = right
;Extra Perceptions: 3 = left and ahead, 4 = right and ahead, 5 = left and back, 6 = right and back
;Returns: 0 = nothing/green, 1 = yellow, 2 = red, 3 = violet
to-report determine-bad [typeflag]
  if typeflag = 0 ; ahead
  [
    if [pcolor] of patch-ahead 1 = yellow
    [
      report 1
    ]

    if [pcolor] of patch-ahead 1 = red
    [
      report 2
    ]

    if [pcolor] of patch-ahead 1 = violet
    [
      report 3
    ]
  ]

  if typeflag = 1 ; left
  [
    if [pcolor] of patch-left-and-ahead 90 1 = yellow
    [
      report 1
    ]

    if [pcolor] of patch-left-and-ahead 90 1 = red
    [
      report 2
    ]

    if [pcolor] of patch-left-and-ahead 90 1 = violet
    [
      report 3
    ]
  ]

  if typeflag = 2 ; right
  [
    if [pcolor] of patch-right-and-ahead 90 1 = yellow
    [
      report 1
    ]

    if [pcolor] of patch-right-and-ahead 90 1 = red
    [
      report 2
    ]

    if [pcolor] of patch-right-and-ahead 90 1 = violet
    [
      report 3
    ]
  ]

  if typeflag = 3 ; left and ahead
  [
    if [pcolor] of patch-left-and-ahead 45 1 = yellow
    [
      report 1
    ]

    if [pcolor] of patch-left-and-ahead 45 1 = red
    [
      report 2
    ]

    if [pcolor] of patch-left-and-ahead 90 1 = violet
    [
      report 3
    ]
  ]

  if typeflag = 4 ; right and ahead
  [
    if [pcolor] of patch-right-and-ahead 45 1 = yellow
    [
      report 1
    ]

    if [pcolor] of patch-right-and-ahead 45 1 = red
    [
      report 2
    ]

    if [pcolor] of patch-right-and-ahead 45 1 = violet
    [
      report 3
    ]
  ]

  if typeflag = 5 ; left and back
  [
    if [pcolor] of patch-left-and-ahead 135 1 = yellow
    [
      report 1
    ]

    if [pcolor] of patch-left-and-ahead 135 1 = red
    [
      report 2
    ]

    if [pcolor] of patch-left-and-ahead 135 1 = violet
    [
      report 3
    ]
  ]

  if typeflag = 6 ; right and back
  [
    if [pcolor] of patch-right-and-ahead 135 1 = yellow
    [
      report 1
    ]

    if [pcolor] of patch-right-and-ahead 135 1 = red
    [
      report 2
    ]

    if [pcolor] of patch-right-and-ahead 135 1 = violet
    [
      report 3
    ]
  ]

  report 0
End

to random-action-eaters
  ifelse random 101 < moveForwardProbability
  [ fd 1 ]
  [
    ifelse random 101 < 50
    [ rt 90 ]
    [ rt -90 ]
  ]

  set energy energy - 1
End

to cleaners-proc
  let aux 0

  ask cleaners
  [
    ifelse pcolor != black
    [
      if pcolor = green
      [
        ask patch-here [set pcolor black]

        ifelse cargo <= (limitCapacity / 2)
        [set energy energy + fEnergy]
        [set energy energy + (fEnergy / 2)]
      ]

      if pcolor = blue
      [
        ifelse cargo > 0
        [
          set cargo 0
          set energy (energy + (cargo * 10))
          set destx 1337
          set desty 1337
        ]
        [
          fd 1
          set energy energy - 1
        ]
      ]

      if pcolor = yellow or pcolor = red or pcolor = violet
      [
        ifelse cargo < limitCapacity
        [
          set aux determine-cargo-type

          ask patch-here [set pcolor black]

          set cargo cargo + aux

          if not cleanersImmune?
          [
            if aux = 5
            [ set toxicity toxicity + radioactivePatchLevel ]
          ]

          set energy energy - 1
        ]
        [
          random-action-cleaners
        ]
      ]
    ]
    [
      ifelse cargo < limitCapacity
      [
        ifelse priorityCleaners = "I_Want_Food"
        [
          if cleaners-look-for-food = 0
          [
            if look-for-trash = 0
            [random-action-cleaners]
          ]
        ]
        [
          if look-for-trash = 0
          [
            if cleaners-look-for-food = 0
            [random-action-cleaners]
          ]
        ]
      ]
      [
        if (destx = 1337) and (desty = 1337)
        [
          look-for-deposits;
        ]

        cleaner-move-to-deposit
      ]
    ]
  ]
End

to-report cleaners-look-for-food
  if [pcolor] of patch-ahead 1 = green
  [
    fd 1
    set energy energy - 1
    report 1
  ]

  if [pcolor] of patch-right-and-ahead 90 1 = green
  [
    rt 90
    set energy energy - 1
    report 1
  ]

  if turtlesExtraPerception?
  [
    if [pcolor] of patch-right-and-ahead 45 1 = green
    [
      fd 1
      set energy energy - 1
      report 1
    ]

    if [pcolor] of patch-right-and-ahead 135 1 = green
    [
      rt 90
      set energy energy - 1
      report 1
    ]
  ]

  report 0
End

to-report look-for-trash
  if ([pcolor] of patch-ahead 1 = red) or ([pcolor] of patch-ahead 1 = yellow)
  [
    fd 1
    set energy energy - 1
    report 1
  ]

  if ([pcolor] of patch-right-and-ahead 90 1 = red) or ([pcolor] of patch-right-and-ahead 90 1 = yellow)
  [
    rt 90
    set energy energy - 1
    report 1
  ]

  if turtlesExtraPerception?
  [
    if ([pcolor] of patch-right-and-ahead 45 1 = red) or ([pcolor] of patch-right-and-ahead 45 1 = yellow)
    [
      fd 1
      set energy energy - 1
      report 1
    ]

    if ([pcolor] of patch-right-and-ahead 135 1 = red) or ([pcolor] of patch-right-and-ahead 135 1 = yellow)
    [
      rt 90
      set energy energy - 1
      report 1
    ]
  ]

  report 0
End

to-report determine-cargo-type
  if pcolor = yellow
  [
    report 1
  ]

  if pcolor = red
  [
    report 2
  ]

  if pcolor = violet
  [
    report 5
  ]

  report 0
End

to look-for-deposits
  ; search for blue cell
  ; when found:
  ; set cargo 0
  let px 0
  let py 0

  ask min-one-of (patches with [pcolor = blue]) [distance myself]
  [
    set px pxcor
    set py pycor
  ]

  set destx px
  set desty py
End

to cleaner-move-to-deposit
  ifelse (xcor > destx)
  [
    ifelse(heading = 270)
    [ fd 1 ]
    [
      ifelse (heading = 0)
      [ lt 90 ]
      [ rt 90 ]
    ]
  ]
  [
    ifelse(xcor < destx)
    [
      ifelse(heading = 90)
      [ fd 1 ]
      [
        ifelse(heading = 0)
        [rt 90]
        [lt 90]
      ]
    ]
    [
      ifelse(ycor > desty)
      [
        ifelse(heading = 180)
        [ fd 1 ]
        [
          ifelse (heading = 90)
          [rt 90]
          [lt 90]
        ]
      ]
      [
        if (ycor < desty)
        [
          ifelse(heading = 0)
          [ fd 1 ]
          [
            ifelse (heading = 90)
            [lt 90]
            [rt 90]
          ]
        ]
      ]
    ]
  ]

  set energy energy - 1
End

to random-action-cleaners
  ifelse random 101 < moveForwardProbability
  [ fd 1 ]
  [ rt 90 ]

  set energy energy - 1
End

to kill
  ask turtles
  [
    if energy <= 0
    [ die ]
  ]
End

to chernobyl-proc
  ask eaters
  [
    if toxicity >= maxToxicity
    [
      hatch-Sick 1
      [ set color cyan ]
      die
    ]
  ]
  ask cleaners
  [
    if toxicity >= maxToxicity
    [
      hatch-Sick 1
      [ set color cyan ]
      die
    ]
  ]

  if count sick != 0
  [
    sick-proc
  ]
End

to sick-proc
  ask sick
  [
    ifelse pcolor = green
    [
      ask patch-here
      [
        set pcolor black
      ]

      set energy energy + ( fEnergy / 2 )
    ]
    [
      ifelse prioritySick = "Eat_To_Survive"
      [
        if sick-look-for-food = 0
        [
          if sick-look-for-trash = 0
          [
            random-action-sick
          ]
        ]
      ]
      [
        if sick-look-for-trash = 0
        [
          if sick-look-for-food = 0
          [
            random-action-sick
          ]
        ]
      ]
    ]
  ]
End

; normal perceptions = neighbors 4
; extra perceptions = neighbors 8 + patch-ahead 2
to-report sick-look-for-food
  if [pcolor] of patch-ahead 1 = green
  [
    fd 1
    set energy energy - 1
    report 1
  ]

  if [pcolor] of patch-left-and-ahead 90 1 = green
  [
    rt -90
    set energy energy - 1
    report 1
  ]

  if [pcolor] of patch-right-and-ahead 90 1 = green
  [
    rt 90
    set energy energy - 1
    report 1
  ]

  if [pcolor] of patch-right-and-ahead 180 1 = green
  [
    ifelse random 101 < 50
    [rt 90]
    [rt -90]
    set energy energy - 1
    report 1
  ]

  if turtlesExtraPerception?
  [
    if [pcolor] of patch-ahead 2 = green
    [
      fd 1
      set energy energy - 1
      report 1
    ]

    if [pcolor] of patch-left-and-ahead 45 1 = green
    [
      fd 1
      set energy energy - 1
      report 1
    ]

    if [pcolor] of patch-right-and-ahead 45 1 = green
    [
      fd 1
      set energy energy - 1
      report 1
    ]

    if [pcolor] of patch-left-and-ahead 135 1 = green
    [
      rt -90
      set energy energy - 1
      report 1
    ]

    if [pcolor] of patch-right-and-ahead 135 1 = green
    [
      rt 90
      set energy energy - 1
      report 1
    ]
  ]

  report 0
End

to-report sick-look-for-trash
  if any? neighbors4 with [pcolor = red]
    [
      ask one-of neighbors4 with [pcolor = red]
      [set pcolor violet]
      set energy energy - 5
      report 1
    ]

  if (any? neighbors4 with [pcolor = yellow])
  [
    ask one-of neighbors4 with [pcolor = yellow]
    [ set pcolor red ]
    set energy energy - 5
    report 1
  ]

  if turtlesExtraPerception?
  [
    if ([pcolor] of patch-left-and-ahead 45 1 = red) or ([pcolor] of patch-left-and-ahead 45 1 = yellow)
    [
      fd 1
      set energy energy - 1
      report 1
    ]

    if ([pcolor] of patch-left-and-ahead 135 1 = red) or ([pcolor] of patch-left-and-ahead 135 1 = yellow)
    [
      rt -90
      set energy energy - 1
      report 1
    ]

    if ([pcolor] of patch-right-and-ahead 45 1 = red) or ([pcolor] of patch-right-and-ahead 45 1 = yellow)
    [
      fd 1
      set energy energy - 1
      report 1
    ]

    if ([pcolor] of patch-right-and-ahead 135 1 = red) or ([pcolor] of patch-right-and-ahead 135 1 = yellow)
    [
      rt 90
      set energy energy - 1
      report 1
    ]
  ]

  report 0
End

to random-action-sick
  ifelse random 101 < moveForwardProbability
  [ fd 1 ]
  [
    ifelse random 101 < 50
    [ rt 90 ]
    [ rt -90 ]
  ]

  set energy energy - 1
End

to replenish-patches
  let CurrentPatches 0
  let selPatches 0

  if(patchReplenishTick != 0)
  [
    if (ticks mod patchReplenishTick) = 0
    [
      set CurrentPatches (((count patches with [pcolor = green]) / (count patches)) * 100)

      if CurrentPatches < nFood ;if current food patches < percentage of food patches we configured...
      [
        ;Algorith: (TotalPatches*(nFood/100)-(TotalPatches*(CurrentPercentage/100))
        set selPatches (((count patches) * (nFood / 100)) - ((count patches) * (currentPatches / 100)))
        if(count patches with [pcolor = black]) > selPatches
        [
          ask n-of selPatches patches with [pcolor = black]
          [
            set pcolor green
          ]
        ]
      ]
    ]
  ]

  if(patchReplenishTick != 0)
  [
    if (ticks mod patchReplenishTick) = 0
    [
      set CurrentPatches (((count patches with [pcolor = yellow]) / (count patches)) * 100)

      if CurrentPatches < nGarbage ;if current garbage patches < percentage of garbage patches we configured...
      [
        set selPatches (((count patches) * (nGarbage / 100)) - ((count patches) * (currentPatches / 100)))

        if(count patches with [pcolor = black]) > selPatches
        [
          ask n-of selPatches patches with [pcolor = black]
          [
            set pcolor yellow
          ]
        ]
      ]
    ]
  ]

  if(patchReplenishTick != 0)
  [
    if (ticks mod patchReplenishTick) = 0
    [
      set CurrentPatches (((count patches with [pcolor = red]) / (count patches)) * 100)

      if CurrentPatches < nToxic ;if current toxic patches < percentage of toxic patches we configured...
      [
        set selPatches (((count patches) * (nToxic / 100)) - ((count patches) * (currentPatches / 100)))

        if(count patches with [pcolor = black]) > selPatches
        [
          ask n-of selPatches patches with [pcolor = black]
          [
            set pcolor red
          ]
        ]
      ]
    ]
  ]
End

to Paint-TPNK
  Paint-U
  Paint-R
  Paint-M
  Paint-T
  Paint-P
End

to Paint-R
  ask patch -8 2
  [set pcolor yellow]
  ask patch -8 1
  [set pcolor yellow]
  ask patch -8 0
  [set pcolor yellow]
  ask patch -8 -1
  [set pcolor yellow]
  ask patch -8 -2
  [set pcolor yellow]
  ask patch -7 2
  [set pcolor yellow]
  ask patch -7 0
  [set pcolor yellow]
  ask patch -6 2
  [set pcolor yellow]
  ask patch -6 0
  [set pcolor yellow]
  ask patch -6 -1
  [set pcolor yellow]
  ask patch -5 1
  [set pcolor yellow]
  ask patch -5 -2
  [set pcolor yellow]
End

to Paint-M
  ask patch 5 2
  [set pcolor yellow]
  ask patch 5 1
  [set pcolor yellow]
  ask patch 5 0
  [set pcolor yellow]
  ask patch 5 -1
  [set pcolor yellow]
  ask patch 5 -2
  [set pcolor yellow]
  ask patch 9 2
  [set pcolor yellow]
  ask patch 9 1
  [set pcolor yellow]
  ask patch 9 0
  [set pcolor yellow]
  ask patch 9 -1
  [set pcolor yellow]
  ask patch 9 -2
  [set pcolor yellow]
  ask patch 6 1
  [set pcolor yellow]
  ask patch 8 1
  [set pcolor yellow]
  ask patch 7 0
  [set pcolor yellow]
End

to Paint-P
  ask patch 12 2
  [set pcolor yellow]
  ask patch 12 1
  [set pcolor yellow]
  ask patch 12 0
  [set pcolor yellow]
  ask patch 12 -1
  [set pcolor yellow]
  ask patch 12 -2
  [set pcolor yellow]
  ask patch 13 2
  [set pcolor yellow]
  ask patch 13 0
  [set pcolor yellow]
  ask patch 14 2
  [set pcolor yellow]
  ask patch 14 0
  [set pcolor yellow]
  ask patch 15 1
  [set pcolor yellow]
End

to Paint-U
  ask patch -2 2
  [set pcolor yellow]
  ask patch 2 2
  [set pcolor yellow]
  ask patch 2 -1
  [set pcolor yellow]
  ask patch -2 -1
  [set pcolor yellow]
  ask patch 2 0
  [set pcolor yellow]
  ask patch -2 0
  [set pcolor yellow]
  ask patch 2 1
  [set pcolor yellow]
  ask patch -2 1
  [set pcolor yellow]
  ask patch -1 -2
  [set pcolor yellow]
  ask patch 1 -2
  [set pcolor yellow]
  ask patch 0 -2
  [set pcolor yellow]
End

to Paint-T
  ask patch -15 2
  [set pcolor yellow]
  ask patch -14 2
  [set pcolor yellow]
  ask patch -13 2
  [set pcolor yellow]
  ask patch -12 2
  [set pcolor yellow]
  ask patch -11 2
  [set pcolor yellow]
  ask patch -13 1
  [set pcolor yellow]
  ask patch -13 0
  [set pcolor yellow]
  ask patch -13 -1
  [set pcolor yellow]
  ask patch -13 -2
  [set pcolor yellow]
End
@#$#@#$#@
GRAPHICS-WINDOW
355
10
792
448
-1
-1
13.0
1
10
1
1
1
0
1
1
1
-16
16
-16
16
0
0
1
ticks
30.0

SLIDER
179
228
351
261
nGarbage
nGarbage
0
15
5.0
1
1
NIL
HORIZONTAL

SLIDER
179
261
351
294
nToxic
nToxic
0
15
15.0
1
1
NIL
HORIZONTAL

SLIDER
179
327
351
360
nFood
nFood
5
20
20.0
1
1
NIL
HORIZONTAL

SLIDER
179
294
351
327
nDeposits
nDeposits
1
10
10.0
1
1
NIL
HORIZONTAL

SLIDER
2
281
174
314
fEnergy
fEnergy
1
50
5.0
1
1
NIL
HORIZONTAL

SLIDER
797
113
969
146
nCleaners
nCleaners
0
100
100.0
1
1
NIL
HORIZONTAL

SLIDER
797
146
969
179
nEaters
nEaters
0
100
100.0
1
1
NIL
HORIZONTAL

SLIDER
2
315
174
348
sEnergy
sEnergy
20
100
50.0
5
1
NIL
HORIZONTAL

BUTTON
797
10
882
43
NIL
Setup
NIL
1
T
OBSERVER
NIL
NIL
NIL
NIL
1

BUTTON
797
45
882
78
NIL
Go
T
1
T
OBSERVER
NIL
NIL
NIL
NIL
1

PLOT
178
10
350
160
Count Turtles
NIL
NIL
0.0
10.0
0.0
10.0
true
false
"" ""
PENS
"Eaters" 1.0 0 -2064490 true "" "plot count eaters"
"Cleaners" 1.0 0 -955883 true "" "plot count cleaners"
"Sick" 1.0 0 -11221820 true "" "plot count sick"

CHOOSER
973
113
1145
158
priorityEaters
priorityEaters
"I_Want_Food" "Better_Be_Safe"
0

MONITOR
3
160
118
205
Eaters
count eaters with [color = pink]
17
1
11

MONITOR
119
160
234
205
Cleaners
count cleaners
17
1
11

SLIDER
797
245
969
278
moveForwardProbability
moveForwardProbability
0
75
75.0
1
1
NIL
HORIZONTAL

SLIDER
797
179
969
212
limitCapacity
limitCapacity
25
100
50.0
5
1
NIL
HORIZONTAL

CHOOSER
973
158
1145
203
priorityCleaners
priorityCleaners
"I_Want_Food" "Dumpster_Diving"
0

PLOT
3
10
174
160
Patch Monitor
NIL
NIL
0.0
10.0
0.0
10.0
true
false
"" ""
PENS
"food" 1.0 0 -10899396 true "" "plot count patches with [pcolor = green]"
"normal-trash" 1.0 0 -1184463 true "" "plot count patches with [pcolor = yellow]"
"toxic-trash" 1.0 0 -2674135 true "" "plot count patches with [pcolor = red]"
"radioactive-trash" 1.0 0 -8630108 true "" "plot count patches with [pcolor = violet]"

SLIDER
797
212
969
245
maxToxicity
maxToxicity
50
150
100.0
50
1
NIL
HORIZONTAL

SLIDER
179
360
351
393
radioactivePatchLevel
radioactivePatchLevel
5
25
25.0
5
1
NIL
HORIZONTAL

SWITCH
798
370
970
403
SickAgents?
SickAgents?
0
1
-1000

BUTTON
266
415
351
448
TPNK
ask turtles\n[die]\nask patches\n[set pcolor orange]\nPaint-TPNK\nask patches\n[set pcolor yellow]\nask patches\n[set pcolor black]\nstop
NIL
1
T
OBSERVER
NIL
NIL
NIL
NIL
1

TEXTBOX
51
211
135
229
Patch Replenish
11
0.0
1

TEXTBOX
862
285
914
303
Switches\n
11
0.0
1

TEXTBOX
868
96
907
114
Agents
11
0.0
1

TEXTBOX
248
211
292
229
Patches
11
0.0
1

MONITOR
235
160
350
205
Sick
count sick
17
1
11

TEXTBOX
1039
95
1087
113
Priorities
11
0.0
1

TEXTBOX
70
265
109
283
Energy
11
0.0
1

CHOOSER
973
203
1145
248
prioritySick
prioritySick
"Eat_To_Survive" "Spread_The_Sickness"
0

SWITCH
797
335
969
368
cleanersImmune?
cleanersImmune?
1
1
-1000

SWITCH
797
302
970
336
turtlesExtraPerception?
turtlesExtraPerception?
0
1
-1000

SLIDER
2
229
174
262
patchReplenishTick
patchReplenishTick
0
10
5.0
1
1
NIL
HORIZONTAL

@#$#@#$#@
## WHAT IS IT?

(a general understanding of what the model is trying to show or explain)

## HOW IT WORKS

(what rules the agents use to create the overall behavior of the model)

## HOW TO USE IT

(how to use the model, including a description of each of the items in the Interface tab)

## THINGS TO NOTICE

(suggested things for the user to notice while running the model)

## THINGS TO TRY

(suggested things for the user to try to do (move sliders, switches, etc.) with the model)

## EXTENDING THE MODEL

(suggested things to add or change in the Code tab to make the model more complicated, detailed, accurate, etc.)

## NETLOGO FEATURES

(interesting or unusual features of NetLogo that the model uses, particularly in the Code tab; or where workarounds were needed for missing features)

## RELATED MODELS

(models in the NetLogo Models Library and elsewhere which are of related interest)

## CREDITS AND REFERENCES

(a reference to the model's URL on the web if it has one, as well as any other necessary credits, citations, and links)
@#$#@#$#@
default
true
0
Polygon -7500403 true true 150 5 40 250 150 205 260 250

airplane
true
0
Polygon -7500403 true true 150 0 135 15 120 60 120 105 15 165 15 195 120 180 135 240 105 270 120 285 150 270 180 285 210 270 165 240 180 180 285 195 285 165 180 105 180 60 165 15

arrow
true
0
Polygon -7500403 true true 150 0 0 150 105 150 105 293 195 293 195 150 300 150

box
false
0
Polygon -7500403 true true 150 285 285 225 285 75 150 135
Polygon -7500403 true true 150 135 15 75 150 15 285 75
Polygon -7500403 true true 15 75 15 225 150 285 150 135
Line -16777216 false 150 285 150 135
Line -16777216 false 150 135 15 75
Line -16777216 false 150 135 285 75

bug
true
0
Circle -7500403 true true 96 182 108
Circle -7500403 true true 110 127 80
Circle -7500403 true true 110 75 80
Line -7500403 true 150 100 80 30
Line -7500403 true 150 100 220 30

butterfly
true
0
Polygon -7500403 true true 150 165 209 199 225 225 225 255 195 270 165 255 150 240
Polygon -7500403 true true 150 165 89 198 75 225 75 255 105 270 135 255 150 240
Polygon -7500403 true true 139 148 100 105 55 90 25 90 10 105 10 135 25 180 40 195 85 194 139 163
Polygon -7500403 true true 162 150 200 105 245 90 275 90 290 105 290 135 275 180 260 195 215 195 162 165
Polygon -16777216 true false 150 255 135 225 120 150 135 120 150 105 165 120 180 150 165 225
Circle -16777216 true false 135 90 30
Line -16777216 false 150 105 195 60
Line -16777216 false 150 105 105 60

car
false
0
Polygon -7500403 true true 300 180 279 164 261 144 240 135 226 132 213 106 203 84 185 63 159 50 135 50 75 60 0 150 0 165 0 225 300 225 300 180
Circle -16777216 true false 180 180 90
Circle -16777216 true false 30 180 90
Polygon -16777216 true false 162 80 132 78 134 135 209 135 194 105 189 96 180 89
Circle -7500403 true true 47 195 58
Circle -7500403 true true 195 195 58

circle
false
0
Circle -7500403 true true 0 0 300

circle 2
false
0
Circle -7500403 true true 0 0 300
Circle -16777216 true false 30 30 240

cow
false
0
Polygon -7500403 true true 200 193 197 249 179 249 177 196 166 187 140 189 93 191 78 179 72 211 49 209 48 181 37 149 25 120 25 89 45 72 103 84 179 75 198 76 252 64 272 81 293 103 285 121 255 121 242 118 224 167
Polygon -7500403 true true 73 210 86 251 62 249 48 208
Polygon -7500403 true true 25 114 16 195 9 204 23 213 25 200 39 123

cylinder
false
0
Circle -7500403 true true 0 0 300

dot
false
0
Circle -7500403 true true 90 90 120

face happy
false
0
Circle -7500403 true true 8 8 285
Circle -16777216 true false 60 75 60
Circle -16777216 true false 180 75 60
Polygon -16777216 true false 150 255 90 239 62 213 47 191 67 179 90 203 109 218 150 225 192 218 210 203 227 181 251 194 236 217 212 240

face neutral
false
0
Circle -7500403 true true 8 7 285
Circle -16777216 true false 60 75 60
Circle -16777216 true false 180 75 60
Rectangle -16777216 true false 60 195 240 225

face sad
false
0
Circle -7500403 true true 8 8 285
Circle -16777216 true false 60 75 60
Circle -16777216 true false 180 75 60
Polygon -16777216 true false 150 168 90 184 62 210 47 232 67 244 90 220 109 205 150 198 192 205 210 220 227 242 251 229 236 206 212 183

fish
false
0
Polygon -1 true false 44 131 21 87 15 86 0 120 15 150 0 180 13 214 20 212 45 166
Polygon -1 true false 135 195 119 235 95 218 76 210 46 204 60 165
Polygon -1 true false 75 45 83 77 71 103 86 114 166 78 135 60
Polygon -7500403 true true 30 136 151 77 226 81 280 119 292 146 292 160 287 170 270 195 195 210 151 212 30 166
Circle -16777216 true false 215 106 30

flag
false
0
Rectangle -7500403 true true 60 15 75 300
Polygon -7500403 true true 90 150 270 90 90 30
Line -7500403 true 75 135 90 135
Line -7500403 true 75 45 90 45

flower
false
0
Polygon -10899396 true false 135 120 165 165 180 210 180 240 150 300 165 300 195 240 195 195 165 135
Circle -7500403 true true 85 132 38
Circle -7500403 true true 130 147 38
Circle -7500403 true true 192 85 38
Circle -7500403 true true 85 40 38
Circle -7500403 true true 177 40 38
Circle -7500403 true true 177 132 38
Circle -7500403 true true 70 85 38
Circle -7500403 true true 130 25 38
Circle -7500403 true true 96 51 108
Circle -16777216 true false 113 68 74
Polygon -10899396 true false 189 233 219 188 249 173 279 188 234 218
Polygon -10899396 true false 180 255 150 210 105 210 75 240 135 240

house
false
0
Rectangle -7500403 true true 45 120 255 285
Rectangle -16777216 true false 120 210 180 285
Polygon -7500403 true true 15 120 150 15 285 120
Line -16777216 false 30 120 270 120

leaf
false
0
Polygon -7500403 true true 150 210 135 195 120 210 60 210 30 195 60 180 60 165 15 135 30 120 15 105 40 104 45 90 60 90 90 105 105 120 120 120 105 60 120 60 135 30 150 15 165 30 180 60 195 60 180 120 195 120 210 105 240 90 255 90 263 104 285 105 270 120 285 135 240 165 240 180 270 195 240 210 180 210 165 195
Polygon -7500403 true true 135 195 135 240 120 255 105 255 105 285 135 285 165 240 165 195

line
true
0
Line -7500403 true 150 0 150 300

line half
true
0
Line -7500403 true 150 0 150 150

pentagon
false
0
Polygon -7500403 true true 150 15 15 120 60 285 240 285 285 120

person
false
0
Circle -7500403 true true 110 5 80
Polygon -7500403 true true 105 90 120 195 90 285 105 300 135 300 150 225 165 300 195 300 210 285 180 195 195 90
Rectangle -7500403 true true 127 79 172 94
Polygon -7500403 true true 195 90 240 150 225 180 165 105
Polygon -7500403 true true 105 90 60 150 75 180 135 105

plant
false
0
Rectangle -7500403 true true 135 90 165 300
Polygon -7500403 true true 135 255 90 210 45 195 75 255 135 285
Polygon -7500403 true true 165 255 210 210 255 195 225 255 165 285
Polygon -7500403 true true 135 180 90 135 45 120 75 180 135 210
Polygon -7500403 true true 165 180 165 210 225 180 255 120 210 135
Polygon -7500403 true true 135 105 90 60 45 45 75 105 135 135
Polygon -7500403 true true 165 105 165 135 225 105 255 45 210 60
Polygon -7500403 true true 135 90 120 45 150 15 180 45 165 90

sheep
false
15
Circle -1 true true 203 65 88
Circle -1 true true 70 65 162
Circle -1 true true 150 105 120
Polygon -7500403 true false 218 120 240 165 255 165 278 120
Circle -7500403 true false 214 72 67
Rectangle -1 true true 164 223 179 298
Polygon -1 true true 45 285 30 285 30 240 15 195 45 210
Circle -1 true true 3 83 150
Rectangle -1 true true 65 221 80 296
Polygon -1 true true 195 285 210 285 210 240 240 210 195 210
Polygon -7500403 true false 276 85 285 105 302 99 294 83
Polygon -7500403 true false 219 85 210 105 193 99 201 83

square
false
0
Rectangle -7500403 true true 30 30 270 270

square 2
false
0
Rectangle -7500403 true true 30 30 270 270
Rectangle -16777216 true false 60 60 240 240

star
false
0
Polygon -7500403 true true 151 1 185 108 298 108 207 175 242 282 151 216 59 282 94 175 3 108 116 108

target
false
0
Circle -7500403 true true 0 0 300
Circle -16777216 true false 30 30 240
Circle -7500403 true true 60 60 180
Circle -16777216 true false 90 90 120
Circle -7500403 true true 120 120 60

tree
false
0
Circle -7500403 true true 118 3 94
Rectangle -6459832 true false 120 195 180 300
Circle -7500403 true true 65 21 108
Circle -7500403 true true 116 41 127
Circle -7500403 true true 45 90 120
Circle -7500403 true true 104 74 152

triangle
false
0
Polygon -7500403 true true 150 30 15 255 285 255

triangle 2
false
0
Polygon -7500403 true true 150 30 15 255 285 255
Polygon -16777216 true false 151 99 225 223 75 224

truck
false
0
Rectangle -7500403 true true 4 45 195 187
Polygon -7500403 true true 296 193 296 150 259 134 244 104 208 104 207 194
Rectangle -1 true false 195 60 195 105
Polygon -16777216 true false 238 112 252 141 219 141 218 112
Circle -16777216 true false 234 174 42
Rectangle -7500403 true true 181 185 214 194
Circle -16777216 true false 144 174 42
Circle -16777216 true false 24 174 42
Circle -7500403 false true 24 174 42
Circle -7500403 false true 144 174 42
Circle -7500403 false true 234 174 42

turtle
true
0
Polygon -10899396 true false 215 204 240 233 246 254 228 266 215 252 193 210
Polygon -10899396 true false 195 90 225 75 245 75 260 89 269 108 261 124 240 105 225 105 210 105
Polygon -10899396 true false 105 90 75 75 55 75 40 89 31 108 39 124 60 105 75 105 90 105
Polygon -10899396 true false 132 85 134 64 107 51 108 17 150 2 192 18 192 52 169 65 172 87
Polygon -10899396 true false 85 204 60 233 54 254 72 266 85 252 107 210
Polygon -7500403 true true 119 75 179 75 209 101 224 135 220 225 175 261 128 261 81 224 74 135 88 99

wheel
false
0
Circle -7500403 true true 3 3 294
Circle -16777216 true false 30 30 240
Line -7500403 true 150 285 150 15
Line -7500403 true 15 150 285 150
Circle -7500403 true true 120 120 60
Line -7500403 true 216 40 79 269
Line -7500403 true 40 84 269 221
Line -7500403 true 40 216 269 79
Line -7500403 true 84 40 221 269

wolf
false
0
Polygon -16777216 true false 253 133 245 131 245 133
Polygon -7500403 true true 2 194 13 197 30 191 38 193 38 205 20 226 20 257 27 265 38 266 40 260 31 253 31 230 60 206 68 198 75 209 66 228 65 243 82 261 84 268 100 267 103 261 77 239 79 231 100 207 98 196 119 201 143 202 160 195 166 210 172 213 173 238 167 251 160 248 154 265 169 264 178 247 186 240 198 260 200 271 217 271 219 262 207 258 195 230 192 198 210 184 227 164 242 144 259 145 284 151 277 141 293 140 299 134 297 127 273 119 270 105
Polygon -7500403 true true -1 195 14 180 36 166 40 153 53 140 82 131 134 133 159 126 188 115 227 108 236 102 238 98 268 86 269 92 281 87 269 103 269 113

x
false
0
Polygon -7500403 true true 270 75 225 30 30 225 75 270
Polygon -7500403 true true 30 75 75 30 270 225 225 270
@#$#@#$#@
NetLogo 6.1.0
@#$#@#$#@
@#$#@#$#@
@#$#@#$#@
<experiments>
  <experiment name="TP_IIA" repetitions="10" runMetricsEveryStep="true">
    <setup>setup</setup>
    <go>go</go>
    <metric>count sick</metric>
    <metric>count cleaners</metric>
    <metric>count eaters</metric>
    <enumeratedValueSet variable="turtlesExtraPerception?">
      <value value="true"/>
      <value value="false"/>
    </enumeratedValueSet>
    <enumeratedValueSet variable="SickAgents?">
      <value value="true"/>
      <value value="false"/>
    </enumeratedValueSet>
    <enumeratedValueSet variable="cleanersImmune?">
      <value value="true"/>
      <value value="false"/>
    </enumeratedValueSet>
    <enumeratedValueSet variable="limitCapacity">
      <value value="50"/>
    </enumeratedValueSet>
    <enumeratedValueSet variable="nCleaners">
      <value value="50"/>
      <value value="100"/>
    </enumeratedValueSet>
    <enumeratedValueSet variable="fEnergy">
      <value value="5"/>
      <value value="50"/>
    </enumeratedValueSet>
    <enumeratedValueSet variable="prioritySick">
      <value value="&quot;Eat_To_Survive&quot;"/>
      <value value="&quot;Spread_The_Sickness&quot;"/>
    </enumeratedValueSet>
    <enumeratedValueSet variable="nDeposits">
      <value value="10"/>
    </enumeratedValueSet>
    <enumeratedValueSet variable="nToxic">
      <value value="5"/>
      <value value="15"/>
    </enumeratedValueSet>
    <enumeratedValueSet variable="nFood">
      <value value="5"/>
      <value value="20"/>
    </enumeratedValueSet>
    <enumeratedValueSet variable="patchReplenishTick">
      <value value="0"/>
      <value value="5"/>
    </enumeratedValueSet>
    <enumeratedValueSet variable="radioactivePatchLevel">
      <value value="25"/>
    </enumeratedValueSet>
    <enumeratedValueSet variable="maxToxicity">
      <value value="100"/>
    </enumeratedValueSet>
    <enumeratedValueSet variable="nEaters">
      <value value="50"/>
      <value value="100"/>
    </enumeratedValueSet>
    <enumeratedValueSet variable="moveForwardProbability">
      <value value="75"/>
    </enumeratedValueSet>
    <enumeratedValueSet variable="priorityCleaners">
      <value value="&quot;Dumpster_Diving&quot;"/>
      <value value="&quot;I_Want_Food&quot;"/>
    </enumeratedValueSet>
    <enumeratedValueSet variable="priorityEaters">
      <value value="&quot;I_Want_Food&quot;"/>
      <value value="&quot;Better_Be_Safe&quot;"/>
    </enumeratedValueSet>
    <enumeratedValueSet variable="nGarbage">
      <value value="5"/>
      <value value="15"/>
    </enumeratedValueSet>
    <enumeratedValueSet variable="sEnergy">
      <value value="50"/>
    </enumeratedValueSet>
  </experiment>
</experiments>
@#$#@#$#@
@#$#@#$#@
default
0.0
-0.2 0 0.0 1.0
0.0 1 1.0 0.0
0.2 0 0.0 1.0
link direction
true
0
Line -7500403 true 150 150 90 180
Line -7500403 true 150 150 210 180
@#$#@#$#@
0
@#$#@#$#@
