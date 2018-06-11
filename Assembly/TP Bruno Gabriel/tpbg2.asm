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
	
	tablinha	db	0	; Define o número da linha que está a ser desenhada
	tabnlinhas	db	0
	tabcor	db	0
	tabcar	db	' '
;///////////////////////////
;///VARIAVEIS PARA O MENU///
;///////////////////////////

    option1 db  "1- Iniciar jogo!",'$'
    option2 db  "2- Ver Pontuacoes!", '$'
    option3 db  "3- Sair...", '$'
	
;///////////////////////////////////
;///VARIAVEIS PARA O TEMPORIZADOR///
;///////////////////////////////////

	time db 60
	str_time db "Tempo Restante", '$'
	show_time db "         "
	oldSeg db ?

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
	cmp ah, 1
	jne tecla_normal
	jmp menu_input
tecla_normal:
	cmp al, '1'
	je game_start
	cmp al, '3'
	je fim_main
	cmp al, 27
	je fim_main
	
	cmp al, 27
	je fim_main
	jmp menu_input

game_start:
	call apaga_ecra
	call Tabela
	
	goto_xy 60,5
	mostra str_time
	
;game_cycle:
;	call Temporizador
;	jmp game_cycle
	
	
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

GameMenu proc near
    goto_xy 2, 10
    mostra option1
    goto_xy 2, 15
    mostra option2
    goto_xy 2, 20
    mostra option3
    ret
GameMenu endp

LeTecla proc
    mov ah, 00h
    int 16h
	mov ah, 00h
	cmp al, 0
	jne fim_letecla
	int 16h
	mov ah, 1
fim_letecla:
    ret
LeTecla endp

tabela proc near

	mov	cx, 10		; Faz o ciclo 10 vezes

ciclo4:
	call CalcAleat
	pop	ax 			; vai buscar 'a pilha o número aleatório

	mov	dl, cl	
	mov	dh, 70
	push dx			; Passagem de parâmetros a impnum (posição do ecran)
	push ax			; Passagem de parâmetros a impnum (número a imprimir)
	;call impnum		; imprime 10 aleatórios na parte direita do ecran
	loop ciclo4		; Ciclo de impressão dos números aleatórios

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

impnum proc

	push bp				; guarda o valor de bp na pilha
	mov	bp, sp			; move o valor de sp para bp
	push ax				; guarda o valor de ax na pilha
	push bx				; guarda o valor de bx na pilha
	push cx				; guarda o valor de cx na pilha
	push dx				; guarda o valor de dx na pilha
	push di				; guarda o endereço de destino na pilha
	mov	ax, [bp+4] 		; param3
	lea	di, [tabstr_num+5]; (nao sei)
	mov	cx, 5			; mover 5 para o cx
	
prox_dig:
	xor	dx, dx			; 
	mov	bx, 10			; 
	div	bx				; ax/bx
	add	dl, '0' 		; dh e' sempre 0
	dec	di				; decrementa o endereço de destino
	mov	[di], dl		; mover o dl para o destination index?
	loop prox_dig		; faz loop do ciclo

	mov	ah, 02h			; move 02(hexadecimal) para ah
	mov	bh, 00h			; move 0 para bh
	mov	dl, [bp+7] 		; param1
	mov	dh, [bp+6] 		; param2
	int	10h				
	mov	dx, di			; move di para dx
	mov	ah, 09h			; escreve string no ecra
	int	21h				; 
	pop	di				; vai buscar o valor à pilha				
	pop	dx				; vai buscar o valor à pilha
	pop	cx				; vai buscar o valor à pilha
	pop	bx				; vai buscar o valor à pilha
	pop	ax				; vai buscar o valor à pilha
	pop	bp				; vai buscar o valor à pilha
	ret	4 				; limpa parametros (4 bytes) colocados na pilha
	
impnum endp

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

Temporizador proc near
	goto_xy 70, 2
	call GetTime
	xor ax, ax
	mov al, time
	mov bl, 10
	mul bl
	mov show_time[0], ah
	mov ah, 0
	div bl
	mov show_time[1], al
	mov show_time[3], 's'
	mov show_time[4], '$'
	mostra show_time
	ret
Temporizador endp

GetTime proc near
	mov ah, 2Ch	;Vai buscar a hora ao sistema
	int 21h		;ch=Horas  cl=Minutos  dh=Segundos  dl=centesima de segundo
	mov cl, oldSeg	;não me interessam os minutos, portanto posso fazer override
	cmp dh, cl
	je fim_tempo
	mov ch, time	;Não me interessam as horas, portanto posso fazer override
	dec ch			;Decremento o tempo de jogo
	mov time, ch	;Atualizo a variavel do tempo de jogo
	mov oldSeg, dh	;Atualizo a variavel do segundo antigo
fim_tempo:
	ret
GetTime endp

cseg    ends
end     main
