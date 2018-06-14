;////////////
;///MACROS///
;////////////

goto_xy	macro POSx, POSy
	mov	ah,	02h
	mov	bh, 0		; numero da página
	mov	dl, POSx
	mov	dh, POSy
	int	10h
endm

mostra macro str
    mov ah, 09h
    lea dx, str
    int 21h
endm

getcor macro
    mov ah, 08h
    int 10h
endm

explode macro
	mov ah, 09h
	mov al, 'x'
	mov Car, al
    mov Car2, al
	mov bh, 0
	mov bl, 0fh
	mov Cor, bl
    mov Cor2, bl
	mov cx, 1
	int 10h
endm

setcor macro
    mov ah, 09h
    mov bh, 0
    mov cx, 1
    int 10h
endm

.8086
.model	small
.stack	2048

dseg    segment para public 'data'
 	;Variaveis

;////////////////////////////////////
;///VARIAVEIS DO TABULEIRO DE JOGO///
;////////////////////////////////////

	tabultimo_num_aleat	dw	0
	tabstr_num	db	5	dup(?),'$'
	tablinha    db	0	; Define o número da linha que está a ser desenhada
	tabnlinhas	db	0
	tabcor	    db	0
	tabcar	    db	' '

;///////////////////////////
;///VARIAVEIS PARA O MENU///
;///////////////////////////

    option1 db  "1- Iniciar jogo!",'$'
    option2 db  "2- Ver Pontuacoes!", '$'
    option3 db  "3- Configurar Tabuleiro!", '$'
    option4 db  "4- Sair...", '$'
	
;///////////////////////////////////
;///VARIAVEIS PARA O TEMPORIZADOR///
;///////////////////////////////////

	unidades    db 30h
    decimas     db 36h
	str_time    db "Tempo Restante", '$'
	show_time   db "         "
	oldSeg      db ?

;/////////////////////////////
;///VARIAVEIS PARA O CURSOR///
;/////////////////////////////

    Car		db	32	; Guarda um caracter do Ecran 
	Cor		db	7	; Guarda os atributos de cor do caracter
	Car2	db	32	; Guarda um caracter do Ecran 
	Cor2	db	7	; Guarda os atributos de cor do caracter
	curPOSy	db	12	; a linha pode ir de [1 .. 25]
	curPOSx	db	38	; POSx pode ir [1..80]	
	POSya	db	5	; Posição anterior de y
	POSxa	db	10	; Posição anterior de x

;///////////////////////////////////////
;///VARIAVEIS PARA A SELEÇÃO DE CORES///
;///////////////////////////////////////

    debug   db "Ola debug"
    selCor  db  ?   ;A cor selecionada
    selPreto    db  00h ;A cor que fica depois da explosão
    selx    db  0,0   ;Variaveis de auxilio ao algoritmo
    sely    db  0,0

;////////////////////////////////
;///VARIAVEIS PARA A PONTUAÇÃO///
;////////////////////////////////

    score_str   db  "Pontos",'$'
    show_score   db  "0000$"    ;Max points 9999

;//////////////////////////////
;///FLAGS E OUTRAS VARIAVEIS///
;//////////////////////////////

    xaux    db  0
    hunt    db  0
    flagh   db  0
    modf    db  0
    flagv   db  0
    antCor  db  0

dseg    ends

sseg	segment para public 'stack'
	db 2048 dup(?)
sseg    ends

cseg	segment para public 'code'
	assume  cs:cseg, ds:dseg, ss:sseg
	
;//////////////////////
;///MAIN DO PROGRAMA///
;//////////////////////

main	proc
	mov     ax, dseg
	mov     ds, ax

	; Código

    mov ax, 0b800h
    mov es, ax

menu_draw:	
    call apaga_ecra
    call GameMenu
	
menu_input:
	call LeTecla
    cmp al, 0
    jne menu_normal
    jmp menu_input
menu_normal:
    cmp al, '1'
    je game_start
    cmp al, '2'
    je menu_input
    cmp al, '3'
    je menu_input
    cmp al, '4'
    je fim_main
    cmp al, 27
    je fim_main

game_start:
	call apaga_ecra ;Apaga o ecra do DOS
	call Tabela     ;e cria um novo tabuleiro de jogo
	
	goto_xy 60,5    ;Posição do da string do temporizador
	mostra str_time
    goto_xy 2, 5
    mostra score_str

    goto_xy curPOSx, curPOSy    ;posição inicial do cursor
    mov ah, 08h ;Preparação dos registos para o int
    mov bh, 0
    int 10h     ;Int para guardar caracter e cor do espaço atual
    mov Cor, ah ;Guardar o caracter e cor atual nas variaveis
    mov Car, al

    mov ah, 09h ;Preparação dos registos para escrever um caracter na posiçao
    mov al, '('
    mov bh, 0
    mov bl, Cor
    mov cx, 1
    int 10h

    inc curPOSx
    goto_xy curPOSx, curPOSy
    mov ah, 08h ;Preparação dos registos para o int
    mov bh, 0
    int 10h     ;Int para guardar caracter e cor do espaço atual
    mov Cor2, ah
    mov Car2, al
    mov ah, 09h ;Preparação dos registos para escrever um caracter na posiçao
    mov al, ')'
    mov bh, 0
    mov bl, Cor
    mov cx, 1
    int 10h
    dec curPOSx
	
game_cycle:
    call VerificaJogo
	call Temporizador   ;Chama o proc do temporizador para verificar o tempo restante
    mov bl, decimas     ;Verifica as décimas do tempo,
    cmp bl, 30h         ;se não estiverem a 0 ASCII, o jogo não está perto de acabar
    jne cycle_continue1 ;e salta para a continuação do ciclo de jogo

    mov bl, unidades
    cmp bl, 30h
    jne cycle_continue1
    call GameOver

cycle_continue1:
    mov ah, 01h ;Verifica se existe algum input á espera em STDIN
    int 16h
    jz game_cycle  ;Se a flag de zero estiver ativa, é porque não há input á espera de ser processado e podemos saltar a frente
    call Cursor

;cycle_continue2:
	jmp game_cycle
	
	
;/////////////////////
;///FIM DO PROGRAMA///
;/////////////////////
fim_main:
	mov ah, 4Ch
	int 21h
	
main	endp

;//////////////////////
;///PROCS UTILIZADOS///
;//////////////////////


;////////////////
;///APAGA ECRA///
;////////////////

apaga_ecra proc
	xor bx, bx      ;faz set de BX a 0 para servir de indice no proximo ciclo
    mov cx, 25*80   ;tamanho do ecra a limpar
    
ciclo_ae:
    mov byte ptr es:[bx], 20h   ;move o caracter espaço para a primeira posiçao de es
    mov byte ptr es:[bx+1], 0Fh ;move o valor 00H (static, background preto, foreground branco) para a segunda posiçao de es
    add bx, 2                   ;adiciona 2 a bx para o proximo ciclo
    loop ciclo_ae             ;corre o ciclo novamente
	ret
apaga_ecra endp

;//////////////////
;///MENU DO JOGO///
;//////////////////

GameMenu proc near
    goto_xy 2, 4
    mostra option1
    goto_xy 2, 8
    mostra option2
    goto_xy 2, 12
    mostra option3
    goto_xy 2, 16
    mostra option4
    ret
GameMenu endp

;//////////////////////
;///LEITURA DE TECLA///
;//////////////////////

LeTecla proc
    mov ah, 00h
    int 16h
    ret
LeTecla endp

;////////////
;///CURSOR///
;////////////

Cursor proc near
    goto_xy curPOSx, curPOSy
    call LeTecla
    cmp al, 0
    jne nao_seta
    mov al, curPOSx
    mov POSxa, al
    mov al, curPOSy
    mov POSya, al

Cima:
    cmp ah, 48h
    jne Baixo
    dec curPOSy
    goto_xy curPOSx, curPOSy
    jmp limpa_ant
Baixo:
    cmp ah, 50h
    jne Direita
    inc curPOSy
    goto_xy curPOSx, curPOSy
    jmp limpa_ant
Direita:
    cmp ah, 4dh
    jne Esquerda
    inc curPOSx
    inc curPOSx
    goto_xy curPOSx, curPOSy
    jmp limpa_ant
Esquerda:
    cmp ah, 4bh
    jne tecla_enter
    dec curPOSx
    dec curPOSx
    goto_xy curPOSx, curPOSy
    jmp limpa_ant

tecla_enter:
    cmp ah, 1ch
    jne fim_cursor
    call selFrame
    jmp fim_cursor
    
limpa_ant:
    goto_xy POSxa, POSya
    mov ah, 09h ;Preparação dos registos para escrever um caracter na posiçao
    mov al, Car
    mov bh, 0
    mov bl, Cor
    mov cx, 1
    int 10h
    inc POSxa
    goto_xy POSxa, POSya
    mov ah, 09h ;Preparação dos registos para escrever um caracter na posiçao
    mov al, Car2
    mov bh, 0
    mov bl, Cor2
    mov cx, 1
    int 10h
    dec POSxa
    jmp impressao

impressao:
    goto_xy curPOSx, curPOSy
    mov ah, 08h ;Preparação dos registos para o int
    mov bh, 0
    int 10h     ;Int para guardar caracter e cor do espaço atual
    mov Cor, ah ;Guardar o caracter e cor atual nas variaveis
    mov Car, al

    inc curPOSx
    goto_xy curPOSx, curPOSy
    mov ah, 08h ;Preparação dos registos para o int
    mov bh, 0
    int 10h     ;Int para guardar caracter e cor do espaço atual
    mov Cor2, ah
    mov Car2, al

    dec curPOSx
    goto_xy curPOSx, curPOSy
    mov ah, 09h ;Preparação dos registos para escrever um caracter na posiçao
    mov al, '('
    mov bh, 0
    mov bl, Cor
    mov cx, 1
    int 10h ;Escreve o caracter na posição do cursor

    inc curPOSx
    goto_xy curPOSx, curPOSy
    mov ah, 09h ;Preparação dos registos para escrever um caracter na posiçao
    mov al, ')'
    mov bh, 0
    mov bl, Cor
    mov cx, 1
    int 10h ;Escreve o caracter na posição do cursor
    
    dec curPOSx
    goto_xy curPOSx, curPOSy

    jmp fim_cursor

nao_seta:
    cmp al, 27
    je game_over
	cmp al, 32
	call selFrame
    
fim_cursor:    
    ret

game_over:
    mov ah, 4ch
    int 21h

Cursor endp

;//////////////////////
;///SELEÇÃO DA FRAME///
;//////////////////////

selFrame proc near
    goto_xy curPOSx, curPOSy
    getcor
    cmp ah, 0fh
    je fim_sel
    mov selCor, ah
    mov ah, curPOSx
    mov al, curPOSy
    mov selx[0], ah
    mov sely[0], al
    call CoordReset
    call snd
    mov xaux, 0
    mov hunt, 0
    mov flagh, 0
    call sweep
    call preenche

fim_sel:
    ret
selframe endp

;//////////////////////////
;///PREENCHE ESPAÇO NOVO///
;//////////////////////////

preenche proc near
    mov selx[0], 30
    mov sely[0], 14
ciclo:
    goto_xy selx[0], sely[0]
    getcor
    cmp al, 'x'
    jne next_coord

novacor:	
	call CalcAleat	; Calcula próximo aleatório que é colocado na pinha 
	pop	ax			; Vai buscar 'a pilha o número aleatório
	and al, 01110000b	; posição do ecran com cor de fundo aleatório e caracter a preto
	cmp	al, 0		; Se o fundo de ecran é preto
	je	novacor		; vai buscar outra cor 
    mov antCor, al    

    goto_xy selx[0], sely[0]
	mov al, ' '
    mov bl, antCor
    setcor

    inc selx[0]
    goto_xy selx[0], sely[0]
    mov al, ' '
    mov bl, antCor
    setcor
    dec selx[0]

next_coord:
    mov ah, selx[0]
    add ah, 2
    cmp ah, 48
    ja oob_x
    mov selx[0], ah
    jmp ciclo

oob_x:
    dec sely[0]
    cmp sely[0], 8
    jb  fim_preenche
    mov selx[0], 30
	mov	di, 1 ;delay de 1 centesimo de segundo
	call delay
	jmp ciclo

fim_preenche:
    goto_xy curPOSx, curPOSy
    getcor
    mov Cor, ah
    mov Car, al
    inc curPOSx
    goto_xy curPOSx, curPOSy
    getcor
    mov Cor2, ah
    mov Car2, al
    dec curPOSx
    ret
preenche endp

;////////////////////////
;///SEARCH AND DESTROY///
;////////////////////////

snd proc near

busca_cima:
    call CoordReset
    dec sely[1]
    goto_xy selx[1], sely[1]
    getcor
    cmp ah, selCor
    jne busca_esq
    explode
    inc selx[1]
    goto_xy selx[1], sely[1]
    explode
    call GetScore
    cmp hunt, 1
    jne exploded_cima
    mov flagh, 1
exploded_cima:
    mov xaux, 1
    
busca_esq:
    call CoordReset
    dec selx[1]
    dec selx[1]
    goto_xy selx[1], sely[1]
    getcor
    cmp ah, selCor
    jne busca_baixo
    explode
    inc selx[1]
    goto_xy selx[1], sely[1]
    explode
    call GetScore
    cmp hunt, 1
    jne exploded_esq
    mov flagh, 1
exploded_esq:
    mov xaux, 1

busca_baixo:
    call CoordReset
    inc sely[1]
    goto_xy selx[1], sely[1]
    getcor
    cmp ah, selCor
    jne busca_dir
    explode
    inc selx[1]
    goto_xy selx[1], sely[1]
    explode
    call GetScore
    cmp hunt, 1
    jne exploded_baixo
    mov flagh, 1
exploded_baixo:
    mov xaux, 1

busca_dir:
    call CoordReset
    inc selx[1]
    inc selx[1]
    goto_xy selx[1], sely[1]
    getcor
    cmp ah, selCor
    jne busca_fim
    explode
    inc selx[1]
    goto_xy selx[1], sely[1]
    explode
    call GetScore
    cmp hunt, 1
    jne exploded_dir
    mov flagh, 1
exploded_dir:
    mov xaux, 1

busca_fim:
    cmp xaux, 0
    je fim_select
    goto_xy selx[0], sely[0]
    cmp al, 'x'
    je fim_select
    explode
    inc selx[0]
    goto_xy selx[0], sely[0]
    explode
    dec selx[0]
    call GetScore
    
fim_select:
    call HuntX
	ret
snd endp

;/////////////////////
;///X-FRAMES HUNTER///
;/////////////////////

HuntX proc near

check_status:
    cmp xaux, 0
    je x_end
    cmp hunt, 1
    je coord_inc

coord_init:
    mov selx[0], 30 ;TabX vai de 30 a 47
    mov sely[0], 14 ;TabY vai de 9 a 14
    mov xaux, 0
    jmp hunt_init

coord_inc:
    inc selx[0]
    inc selx[0]
    jmp hunt_init

hunt_init:
    goto_xy selx[0], sely[0]
    getcor
    cmp al, 'x'
    je x_found
    mov ah, selx[0]
    add ah, 2
    cmp ah, 48
    ja oob_x
    mov selx[0], ah
    jmp hunt_init

x_found:
    mov hunt, 1
    call snd
    jmp x_end

oob_x:
    dec sely[0]
    cmp sely[0], 8
    jb oob_y
    mov selx[0], 30
    jmp hunt_init

oob_y:
    dec hunt
    cmp hunt, 0
    jne coord_init

x_end:
    cmp hunt, 0
    jne coord_inc
    ret
HuntX endp

;////////////////////
;///SWEEP THE LEG!///
;////////////////////

sweep proc near
coord_init:
    mov modf, 0
    mov selx[0], 30 ;TabX vai de 30 a 47
    mov sely[0], 14 ;TabY vai de 9 a 14

sweep_init:
    call CoordReset
    dec sely[1]
    goto_xy selx[0], sely[0]
    cmp sely[1], 9  ;verifica se está na penultima linha da tabela
    jb sweep_end    ;se sim, salta para o fim
    getcor
    cmp al, 'x'
    jne next_coord  ;se na posição atual o caracter não for 'x', segue para a próxima coordenada
    goto_xy selx[1], sely[1]
    getcor      ;vai buscar a cor do espaço acima do atual
    cmp al, 'x' ;se o espaço acima também tiver um 'x', segue para a próxima coordenada
    je next_coord
    mov antCor, ah  ;move a cor do espaço acima para a var global
    mov bl, 0fh     ;prepara os triggers do int 10h contido em setcor
    mov al, 'x'
    setcor          ;int 10h/ah=09h mas com falta de parametros
    goto_xy selx[0], sely[0]
    mov bl, antCor
    mov al, ' '
    setcor
    mov modf, 1 ;como fez uma modificação, faz set a modf
    
next_coord:
    inc selx[0]
    cmp selx[0], 48
    ja oob_x    ;caso a posição atual exceda os limites do tabuleiro em x, salta para oob_x (Out of Bounds: x)
    jmp sweep_init

oob_x:
    dec sely[0] ;Move o curso para a linha acima da atual
    cmp sely[0], 8 ;Verifica se não excede o limite do tabuleiro em y
    jb  sweep_end   ;se sim, salta para o fim
    mov selx[0], 30 ;repõe o cursor no limite minimo em x do tabuleiro
    mov di, 1   ;delay de 1 centesimo de segundo para dar aparencia da gravidade nos blocos
    call delay
    jmp sweep_init

sweep_end:
    cmp modf, 1 ;caso o tabuleiro tenha sido modificado alguma vez, vai repetir o ciclo inteiro do inicio a procura de mais modificações
    je coord_init
    goto_xy curPOSx, curPOSy
    getcor
    mov Cor, ah
    mov Car, al
    inc curPOSx
    goto_xy curPOSx, curPOSy
    getcor
    mov Cor2, ah
    mov Car2, al
    dec curPOSx
    ret
sweep endp

;///////////////////////
;///RESET COORDENADAS///
;///////////////////////

CoordReset proc near
    mov ah, selx[0]
    mov al, sely[0]
    mov selx[1], ah
    mov sely[1], al
    ret
CoordReset endp

;///////////////////////
;///TABULEIRO DO JOGO///
;///////////////////////

tabela proc near

	mov	cx, 10		; Faz o ciclo 10 vezes

	mov	tablinha, 14	; O Tabuleiro vai começar a ser desenhado na linha 14, de baixo para cima
	mov	tabnlinhas, 6	; O Tabuleiro vai ter 6 linhas
	
ciclo2:	
	mov	al, 160		
	mov	ah, tablinha
	mul	ah
	add	ax, 60
	mov bx, ax		; Determina Endereço onde começa a "linha". bx = 160*linha + 60

	mov	cx, 9		; São 9 colunas 

ciclo:	
	mov dh,	tabcar	; vai imprimir o caracter "SPACE"
	mov	es:[bx], dh

novacor:	
	call CalcAleat	; Calcula próximo aleatório que é colocado na pinha 
	pop	ax			; Vai buscar 'a pilha o número aleatório
	and al, 01110000b	; posição do ecran com cor de fundo aleatório e caracter a preto
	cmp	al, 0		; Se o fundo de ecran é preto
	je	novacor		; vai buscar outra cor 

	mov dh, tabcar	; Repete mais uma vez porque cada peça do tabuleiro ocupa dois carecteres de ecran
	mov	es:[bx], dh		
	mov	es:[bx+1], al	; Coloca as características de cor da posição atual 
	add bx, 2		; próxima posição e ecran dois bytes à frente 

	mov dh, tabcar	; Repete mais uma vez porque cada peça do tabuleiro ocupa dois carecteres de ecran
	mov	es:[bx], dh
	mov	es:[bx+1], al
	add bx, 2

	mov	di, 1 ;delay de 1 centesimo de segundo
	call delay
	loop ciclo		; continua até fazer as 9 colunas que correspondem a uma liha completa
decrementa:	
	dec	tablinha		; Vai desenhar a próxima linha
	dec	tabnlinhas		; contador de linhas
	mov	al, tabnlinhas
	cmp	al, 0		; verifica se já desenhou todas as linhas 
	jne	ciclo2		; se ainda há linhas a desenhar continua
    ret
	
tabela endp

;/////////////////////////////////
;///CALCULO DE NUMERO ALEATORIO///
;/////////////////////////////////

CalcAleat proc near
	sub	sp, 2			; subtrai 2 ao ponteiro?
	push bp				; coloca o valor de bp na pilha
	mov	bp, sp			; mover o valor do ponteiro para bp
	push ax				; coloca o valor de ax na pilha 
	push cx				; coloca o valor de cx na pilha 
	push dx				; coloca o valor de dx na pilha 
	mov	ax, [bp+4]		; mover para ax o valor que esta na memoria bp+4
	mov	[bp+2], ax		; mover o endereço de memória bp+2 o valor de ax*cx

	mov	ah, 00h			; le o tempo do pc
	int	1ah				; interrupção

	add	dx, tabultimo_num_aleat	; vai buscar o aleatório anterior
	add	cx, dx			; adiciona dx a cx
	mov	ax, 65521		; 
	push dx				; guarda valor na pilha
	mul	cx			 	; multiplica ax*cx
	pop	dx			 	; vai buscar o valor à pilha
	xchg dl, dh			; 
	add	dx, 32749		; 
	add	dx, ax			; adiciona ax a dx

	mov	tabultimo_num_aleat, dx	; guarda o novo numero aleatório  

	mov	[bp+4], dx		; o aleatório é passado por pilha

	pop	dx				; vai buscar o valor à pilha
	pop	cx				; vai buscar o valor à pilha
	pop	ax				; vai buscar o valor à pilha
	pop	bp				; vai buscar o valor à pilha
	ret					; (nao sei)
CalcAleat endp

;///////////////////////////////////
;///ATRASO NA IMPRESSÃO DAS CORES///
;///////////////////////////////////

delay proc near
	pushf
	push ax				; guarda o valor de ax na pilha
	push cx				; guarda o valor de cx na pilha
	push dx				; guarda o valor de dx na pilha
	push si				; guarda o valor de si na pilha
	
	mov	ah, 2Ch			; vai buscar o tempo do sistema
	int	21h
	mov	al, 100			; mover 100 para al
	mul	dh				; multiplicar ah*dh
	xor	dh, dh			; limpar dh
	add	ax, dx			; 
	mov	si, ax			; 


ciclo:
	mov	ah, 2Ch
	int	21h
	mov	al, 100
	mul	dh
	xor	dh, dh
	add	ax, dx

	cmp	ax, si 
	jnb	naoajusta
	add	ax, 6000 ; 60 segundos
	
naoajusta:
	sub	ax, si
	cmp	ax, di
	jb ciclo

	pop	si
	pop	dx
	pop	cx
	pop	ax
	popf
	ret
delay endp

;//////////////////////////
;///TEMPORIZADOR DE JOGO///
;//////////////////////////

Temporizador proc near
    push ax
	call GetTime
    xor ax, ax
    mov ah, decimas
    mov al, unidades
    mov show_time[0], ah
    mov show_time[1], al
	mov show_time[3], 's'
	mov show_time[4], '$'
	goto_xy 70, 6
	mostra show_time
    goto_xy curPOSx, curPOSy
    pop ax
	ret
Temporizador endp

;///////////////////////////////
;///BUSCAR O TEMPO DO SISTEMA///
;///////////////////////////////

GetTime proc near
	mov ah, 2Ch	;Vai buscar a hora ao sistema
	int 21h		;ch=Horas  cl=Minutos  dh=Segundos  dl=centesima de segundo
	mov cl, oldSeg	;não me interessam os minutos, portanto posso fazer override
	cmp dh, cl  ;Se os segundos antigos forem iguais aos novos segundo, termina o proc
	je fim_tempo
	mov ch, unidades	;Não me interessam as horas, portanto posso fazer override
    cmp ch, 30h ;comparo os segundos ao caracter ascii do 0, se for diferente, salta para tag1
    jne tag1
    add ch, 10  ;adiciono 10 ao valor de ascii dos segundos, fica com o caracter ':'
    mov dl, decimas ;Não me interessam as decimas de segundos
    dec dl  ;decremento as decimas dos segundos
    mov decimas, dl ;atualizo a variavel com o novo valor
tag1:
	dec ch			;Decremento o tempo de jogo. Se o caracter era ':', fica agora a '9'
	mov unidades, ch	;Atualizo a variavel do tempo de jogo
	mov oldSeg, dh	;Atualizo a variavel do segundo antigo
fim_tempo:
	ret
GetTime endp

;//////////////////////
;///MOSTRA PONTUAÇÃO///
;//////////////////////

GetScore proc near
    inc show_score[3]
    cmp show_score[3], 3ah
    jne fim_score
    mov show_score[3], 30h

    inc show_score[2]
    cmp show_score[2], 3ah
    jne fim_score
    mov show_score[2], 30h

    inc show_score[1]
    cmp show_score[1], 3ah
    jne fim_score
    mov show_score[1], 30h

    inc show_score[0]
    cmp show_score[0], 3ah
    jne fim_score
    mov show_score[0], 0
    mov show_score[1], 0
    mov show_score[2], 0
    mov show_score[3], 0

fim_score:
    goto_xy 3, 6
    mostra show_score
    ret
GetScore endp

;//////////////////////////////////////
;///VERIFICAÇÃO DO TABULEIRO DE JOGO///
;//////////////////////////////////////

VerificaJogo proc near
    mov selx[0], 30 ;TabX vai de 30 a 47
    mov sely[0], 14 ;TabY vai de 9 a 14

verf_init:
    goto_xy selx[0], sely[0]
    getcor
    mov antCor, ah

verf_baixo:
    call CoordReset
    inc sely[1]
    goto_xy selx[1], sely[1]
    getcor
    cmp antCor, ah
    jne verf_esq
    mov flagv, 1

verf_esq:
    call CoordReset
    dec selx[1]
    dec selx[1]
    goto_xy selx[1], sely[1]
    getcor
    cmp antCor, ah
    jne verf_cima
    mov flagv, 1

verf_cima:
    call CoordReset
    dec sely[1]
    goto_xy selx[1], sely[1]
    getcor
    cmp antCor, ah
    jne verf_dir
    mov flagv, 1

verf_dir:
    call CoordReset
    inc selx[1]
    inc selx[1]
    goto_xy selx[1], sely[1]
    getcor
    cmp antCor, ah
    jne check_flag
    mov flagv, 1

check_flag:
    cmp flagv, 1
    je verf_end
    
verf_next_coord:
    inc selx[0]
    cmp selx[0], 48
    ja oob_x
    jmp verf_init

oob_x:
    dec sely[0]
    cmp sely[0], 8
    jb  verf_end
    mov selx[0], 30
    jmp verf_init

verf_end:
    cmp flagv, 0
    jne verf_ret
    call Tabela
verf_ret:
    ret
VerificaJogo endp

;////////////////
;///GAME OVER!///
;////////////////

GameOver proc near
    call apaga_ecra
    goto_xy 38, 12
    mostra score_str
    goto_xy 39, 13
    mostra show_score
    mov di, 300 ;O ecra de GameOver dura por 3 segundos
    call delay
    mov ah, 4ch
    int 21h
    ret
GameOver endp

cseg    ends
end     main
