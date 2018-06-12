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
    option3 db  "3- Sair...", '$'
	
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
	curPOSy	db	5	; a linha pode ir de [1 .. 25]
	curPOSx	db	10	; POSx pode ir [1..80]	
	POSya	db	5	; Posição anterior de y
	POSxa	db	10	; Posição anterior de x

;///////////////////////////////////////
;///VARIAVEIS PARA A SELEÇÃO DE CORES///
;///////////////////////////////////////

    selCor  db  ?   ;A cor selecionada
    selPreto    db  00h ;A cor que fica depois da explosão
    selx   db  0,0,0,0,0,0   ;Variaveis de auxilio ao algoritmo
    sely   db  0,0,0,0,0,0
	auxhorz	db	0
	auxvert	db	0
	conta	db	0

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
    je fim_main
    cmp al, 27
    je fim_main

game_start:
	call apaga_ecra ;Apaga o ecra do DOS
	call Tabela     ;e cria um novo tabuleiro de jogo
	
	goto_xy 60,5    ;Posição do da string do temporizador
	mostra str_time

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
	call Temporizador   ;Chama o proc do temporizador para verificar o tempo restante
    mov bl, decimas     ;Verifica as décimas do tempo,
    cmp bl, 30h         ;se não estiverem a 0 ASCII, o jogo não está perto de acabar
    jne cycle_continue1 ;e salta para a continuação do ciclo de jogo

    mov bl, unidades
    cmp bl, 30h
    je fim_main

cycle_continue1:
    mov ah, 01h ;Verifica se existe algum input á espera em STDIN
    int 16h
    jz cycle_continue2  ;Se a flag de zero estiver ativa, é porque não há input á espera de ser processado e podemos saltar a frente
    call Cursor

cycle_continue2:
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
    goto_xy 2, 12
    mostra option2
    goto_xy 2, 20
    mostra option3
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

;////////////////////////
;///SELEÇÃO DAS FRAMES///
;////////////////////////

selFrame proc near
	getcor
	mov selCor, ah
	
passo1:					;prepara as coordenadas iniciais 0 e 1
	mov ah, curPOSx
	mov al, curPOSy
	mov selx[0], ah
	mov selx[1], ah
	mov sely[0], al
	mov sely[1], al
	
passo2:					;Anda para cima na tabela até encontrar um quadrado que não seja da cor escolhida
	dec sely[1]
	goto_xy selx[1], sely[1]	;auxilia-se através a var 1 das coordenadas
	getcor
	cmp ah, selCor
	jne passo3
	mov ah, selx[1]
	mov al, sely[1]
	mov selx[0], ah
	mov sely[0], al
	jmp passo2
	
passo3:					;Prepara as coordenadas 1 e 2 para scan horizontal
	mov ah, selx[0]
	mov al, sely[0]
	mov selx[1], ah
	mov selx[2], ah
	mov sely[1], al
	mov sely[2], al
	
passo4:					;Anda para a Esquerda na tabela até encontrar um quadrado com cor diferente a escolhida
	sub ah, 2
	mov selx[1], ah
	goto_xy selx[1], sely[1]
	getcor
	cmp ah, selCor
	jne passo4b
	mov ah, selx[1]
	jmp passo4
	
passo4b:
	mov ah, selx[1]	;Reponho a coordenada que modifiquei no paço anterior
	add ah, 2
	mov selx[1], ah
	
passo5:				;Igual ao passo anterior, mas para a direita
	mov ah, selx[2]
	add ah, 2
	mov selx[2], ah
	goto_xy selx[2], sely[2]
	getcor
	cmp ah, selCor
	jne passo5b
	jmp passo5
	
passo5b:
	mov ah, selx[2]	;Reponho a coordenada que modifiquei no passo anterior
	sub ah, 2
	mov selx[2], ah
	
passo6:
	mov ah, selx[1]
	mov al, sely[1]
	mov selx[3], ah
	mov selx[4], ah
	mov sely[3], al
	mov sely[4], al
	
passo7:
	inc sely[3]
	goto_xy selx[3], sely[3]
	getcor
	cmp ah, selCor
	jne passo7b
	jmp passo7
	
passo7b:
	dec sely[3] ;Repor a coordenada anterior
	
passo8:
	dec sely[4]
	goto_xy selx[4], sely[4]
	getcor
	cmp ah, selCor
	jne passo8b
	jmp passo8
	
passo8b:
	inc sely[4]	;Messy, mas não estava a pensar em mais nenhuma solução
	
passo9:
	goto_xy selx[4], sely[4]
	explode
	inc selx[4]
	goto_xy selx[4], sely[4]
	explode
	dec selx[4]
	dec sely[4]
	mov al, sely[4]
	cmp al, sely[3]
	jne passo9
	
	mov ah, selx[1]
	add ah, 2
	mov selx[1], ah
	cmp ah, selx[2]
	jne passo6
	
	inc sely[0]
	goto_xy selx[0], sely[0]
	getcor
	cmp ah, selCor
	jne fim_select
	jmp passo3

fim_select:
	;call AjustaFrames
	ret
selFrame endp

;///////////////////////
;///TABULEIRO DO JOGO///
;///////////////////////

tabela proc near

	mov	cx, 10		; Faz o ciclo 10 vezes

	mov	tablinha, 8	; O Tabuleiro vai começar a ser desenhado na linha 8 
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
	
	inc	tablinha		; Vai desenhar a próxima linha
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
	ret
Temporizador endp

;///////////////////////////////
;///BUSCAR O TEMPO DO SISTEMA///
;///////////////////////////////

GetTime proc near
	mov ah, 2Ch	;Vai buscar a hora ao sistema
	int 21h		;ch=Horas  cl=Minutos  dh=Segundos  dl=centesima de segundo
	mov cl, oldSeg	;não me interessam os minutos, portanto posso fazer override
	cmp dh, cl
	je fim_tempo
	mov ch, unidades	;Não me interessam as horas, portanto posso fazer override
    cmp ch, 30h
    jne tag1
    add ch, 10
    mov dl, decimas ;Não me interessam as decimas de segundos
    dec dl
    mov decimas, dl
tag1:
	dec ch			;Decremento o tempo de jogo
	mov unidades, ch	;Atualizo a variavel do tempo de jogo
	mov oldSeg, dh	;Atualizo a variavel do segundo antigo
fim_tempo:
	ret
GetTime endp

cseg    ends
end     main
