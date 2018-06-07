;MACROS
goto_xy	macro POSx,POSy
	mov	ah, 02h
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

pilha	SEGMENT PARA STACK 'STACK'
		db 2048 dup(?)
pilha	ENDS

dseg    segment para public 'data'
	;VARIAVEIS DO TABULEIRO DE JOGO
	tabultimo_num_aleat dw 0

	tabstr_num db 5 dup(?),'$'
	
	tablinha db 0	; Define o número da linha que está a ser desenhada
	tabnlinhas	db 0
	tabcor	db  0
	tabcar	db ' '	
		
	;VARIAVEIS DO TEMPORIZADOR
	STR12	db 		"            "	; String para 12 digitos	
	NUMERO	db		"                    $", 	; String destinada a guardar o número lido
	

	NUM_SP	db		"                    $" 	; PAra apagar zona de ecran
	DDMMAAAA db		"                     "

	Horas	dw		0				; Vai guardar a HORA actual
	Minutos		dw		0				; Vai guardar os minutos actuais
	Segundos	dw		0				; Vai guardar os segundos actuais
	Old_seg		dw		0				; Guarda os últimos segundos que foram lidos
			

	POSy	db	10	; a linha pode ir de [1 .. 25]
	POSx	db	40	; POSx pode ir [1..80]	
	NUMDIG	db	0	; controla o numero de digitos do numero lido
	MAXDIG	db	4	; Constante que define o numero MAXIMO de digitos a ser aceite


dseg    ends

cseg	segment para public 'code'
	assume  cs:cseg, ds:dseg, ss:pilha
	
	;PROGRAMA
main	proc

	mov AX, dseg
	mov DS, AX
	
	mov ah, 4Ch
	int 21h
main endp
;/////////
;//PROCS//
;/////////
	
apaga_ecran	proc
	xor		bx, bx
	mov		cx, 25*80
		
apaga:
	mov	byte ptr es:[bx],' '
	mov	byte ptr es:[bx+1],7
	inc	bx
	inc bx
	loop apaga
	ret
apaga_ecran	endp

tabela proc
	mov	cx, 10		; Faz o ciclo 10 vezes
ciclo4:
	call CalcAleat
	pop	ax 		; vai buscar 'a pilha o número aleatório

	mov	dl, cl	
	mov	dh, 70
	push dx		; Passagem de parâmetros a impnum (posição do ecran)
	push ax		; Passagem de parâmetros a impnum (número a imprimir)
	call impnum		; imprime 10 aleatórios na parte direita do ecran
	loop ciclo4		; Ciclo de impressão dos números aleatórios
		
	mov ax, 0b800h	; Segmento de memória de vídeo onde vai ser desenhado o tabuleiro
	mov es, ax	
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
		mov dh,	tabcar	; vai imprimir o caracter "SAPCE"
		mov	es:[bx], dh
	
novacor:	
		call CalcAleat	; Calcula próximo aleatório que é colocado na pinha 
		pop	ax ; 		; Vai buscar 'a pilha o número aleatório
		and al, 01110000b	; posição do ecran com cor de fundo aleatório e caracter a preto
		cmp	al, 0		; Se o fundo de ecran é preto
		je	novacor		; vai buscar outra cor 

		mov dh, tabcar	; Repete mais uma vez porque cada peça do tabuleiro ocupa dois carecteres de ecran
		mov	es:[bx],   dh		
		mov	es:[bx+1], al	; Coloca as características de cor da posição atual 
		inc	bx		
		inc	bx		; próxima posição e ecran dois bytes à frente 

		mov dh, tabcar	; Repete mais uma vez porque cada peça do tabuleiro ocupa dois carecteres de ecran
		mov	es:[bx], dh
		mov	es:[bx+1], al
		inc	bx
		inc	bx
		
		mov	di, 1 ;delay de 1 centesimo de segundo
		call delay
		loop ciclo		; continua até fazer as 9 colunas que correspondem a uma liha completa
		
		inc	tablinha		; Vai desenhar a próxima linha
		dec	tabnlinhas		; contador de linhas
		mov	al, tabnlinhas
		cmp	al, 0		; verifica se já desenhou todas as linhas 
		jne	ciclo2		; se ainda há linhas a desenhar continua 
tabela endp

CalcAleat proc
	sub	sp, 2
	push bp
	mov	bp, sp
	push ax
	push cx
	push dx	
	mov	ax, [bp+4]
	mov	[bp+2], ax

	mov	ah, 00h
	int	1ah

	add	dx, tabultimo_num_aleat	; vai buscar o aleatório anterior
	add	cx, dx	
	mov	ax, 65521
	push dx
	mul	cx			
	pop	dx			 
	xchg dl, dh
	add	dx, 32749
	add	dx, ax

	mov	tabultimo_num_aleat, dx	; guarda o novo numero aleatório  

	mov	[BP+4], dx		; o aleatório é passado por pilha

	pop	dx
	pop	cx
	pop	ax
	pop	bp
	ret
CalcAleat endp

impnum proc

	push bp
	mov	bp, sp
	push ax
	push bx
	push cx
	push dx
	push di
	mov	ax, [bp+4] ;param3
	lea	di, [tabstr_num+5]
	mov	cx, 5
	
prox_dig:
	xor	dx, dx
	mov	bx, 10
	div	bx
	add	dl, '0' ; dh e' sempre 0
	dec	di
	mov	[di], dl
	loop prox_dig

	mov	ah, 02h
	mov	bh, 00h
	mov	dl, [bp+7] ;param1
	mov	dh, [bp+6] ;param2
	int	10h
	mov	dx, di
	mov	ah, 09h
	int	21h
	pop	di
	pop	dx
	pop	cx
	pop	bx
	pop	ax
	pop	bp
	ret	4 ;limpa parametros (4 bytes) colocados na pilha
	
impnum endp

delay proc
	pushf
	push ax
	push cx
	push dx
	push si
	
	mov	ah, 2Ch
	int	21h
	mov	al, 100
	mul	dh
	xor	dh, dh
	add	ax, dx
	mov	si, ax


ciclo:
	mov	ah, 2Ch
	int	21h
	mov	al, 100
	mul	dh
	xor	dh, dh
	add	ax, dx

;MACROS
goto_xy	macro POSx,POSy
	mov	ah, 02h
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

pilha	SEGMENT PARA STACK 'STACK'
		db 2048 dup(?)
pilha	ENDS

dseg    segment para public 'data'
	;VARIAVEIS DO TABULEIRO DE JOGO
	tabultimo_num_aleat dw 0

	tabstr_num db 5 dup(?),'$'
	
	tablinha db 0	; Define o número da linha que está a ser desenhada
	tabnlinhas	db 0
	tabcor	db  0
	tabcar	db ' '	
		
	;VARIAVEIS DO TEMPORIZADOR
	STR12	db 		"            "	; String para 12 digitos	
	NUMERO	db		"                    $", 	; String destinada a guardar o número lido
	

	NUM_SP	db		"                    $" 	; PAra apagar zona de ecran
	DDMMAAAA db		"                     "

	Horas	dw		0				; Vai guardar a HORA actual
	Minutos		dw		0				; Vai guardar os minutos actuais
	Segundos	dw		0				; Vai guardar os segundos actuais
	Old_seg		dw		0				; Guarda os últimos segundos que foram lidos
			

	POSy	db	10	; a linha pode ir de [1 .. 25]
	POSx	db	40	; POSx pode ir [1..80]	
	NUMDIG	db	0	; controla o numero de digitos do numero lido
	MAXDIG	db	4	; Constante que define o numero MAXIMO de digitos a ser aceite


dseg    ends

cseg	segment para public 'code'
	assume  cs:cseg, ds:dseg, ss:pilha
	
	;PROGRAMA
main	proc

	mov AX, dseg
	mov DS, AX
	
	mov ah, 4Ch
	int 21h
main endp
;/////////
;//PROCS//
;/////////
	
apaga_ecran	proc
	xor		bx, bx
	mov		cx, 25*80
		
apaga:
	mov	byte ptr es:[bx],' '
	mov	byte ptr es:[bx+1],7
	inc	bx
	inc bx
	loop apaga
	ret
apaga_ecran	endp

tabela proc
	mov	cx, 10		; Faz o ciclo 10 vezes
ciclo4:
	call CalcAleat
	pop	ax 		; vai buscar 'a pilha o número aleatório

	mov	dl, cl	
	mov	dh, 70
	push dx		; Passagem de parâmetros a impnum (posição do ecran)
	push ax		; Passagem de parâmetros a impnum (número a imprimir)
	call impnum		; imprime 10 aleatórios na parte direita do ecran
	loop ciclo4		; Ciclo de impressão dos números aleatórios
		
	mov ax, 0b800h	; Segmento de memória de vídeo onde vai ser desenhado o tabuleiro
	mov es, ax	
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
		mov dh,	tabcar	; vai imprimir o caracter "SAPCE"
		mov	es:[bx], dh
	
novacor:	
		call CalcAleat	; Calcula próximo aleatório que é colocado na pinha 
		pop	ax ; 		; Vai buscar 'a pilha o número aleatório
		and al, 01110000b	; posição do ecran com cor de fundo aleatório e caracter a preto
		cmp	al, 0		; Se o fundo de ecran é preto
		je	novacor		; vai buscar outra cor 

		mov dh, tabcar	; Repete mais uma vez porque cada peça do tabuleiro ocupa dois carecteres de ecran
		mov	es:[bx],   dh		
		mov	es:[bx+1], al	; Coloca as características de cor da posição atual 
		inc	bx		
		inc	bx		; próxima posição e ecran dois bytes à frente 

		mov dh, tabcar	; Repete mais uma vez porque cada peça do tabuleiro ocupa dois carecteres de ecran
		mov	es:[bx], dh
		mov	es:[bx+1], al
		inc	bx
		inc	bx
		
		mov	di, 1 ;delay de 1 centesimo de segundo
		call delay
		loop ciclo		; continua até fazer as 9 colunas que correspondem a uma liha completa
		
		inc	tablinha		; Vai desenhar a próxima linha
		dec	tabnlinhas		; contador de linhas
		mov	al, tabnlinhas
		cmp	al, 0		; verifica se já desenhou todas as linhas 
		jne	ciclo2		; se ainda há linhas a desenhar continua 
tabela endp

CalcAleat proc
	sub	sp, 2
	push bp
	mov	bp, sp
	push ax
	push cx
	push dx	
	mov	ax, [bp+4]
	mov	[bp+2], ax

	mov	ah, 00h
	int	1ah

	add	dx, tabultimo_num_aleat	; vai buscar o aleatório anterior
	add	cx, dx	
	mov	ax, 65521
	push dx
	mul	cx			
	pop	dx			 
	xchg dl, dh
	add	dx, 32749
	add	dx, ax

	mov	tabultimo_num_aleat, dx	; guarda o novo numero aleatório  

	mov	[BP+4], dx		; o aleatório é passado por pilha

	pop	dx
	pop	cx
	pop	ax
	pop	bp
	ret
CalcAleat endp

impnum proc

	push bp
	mov	bp, sp
	push ax
	push bx
	push cx
	push dx
	push di
	mov	ax, [bp+4] ;param3
	lea	di, [tabstr_num+5]
	mov	cx, 5
	
prox_dig:
	xor	dx, dx
	mov	bx, 10
	div	bx
	add	dl, '0' ; dh e' sempre 0
	dec	di
	mov	[di], dl
	loop prox_dig

	mov	ah, 02h
	mov	bh, 00h
	mov	dl, [bp+7] ;param1
	mov	dh, [bp+6] ;param2
	int	10h
	mov	dx, di
	mov	ah, 09h
	int	21h
	pop	di
	pop	dx
	pop	cx
	pop	bx
	pop	ax
	pop	bp
	ret	4 ;limpa parametros (4 bytes) colocados na pilha
	
impnum endp

delay proc
	pushf
	push ax
	push cx
	push dx
	push si
	
	mov	ah, 2Ch
	int	21h
	mov	al, 100
	mul	dh
	xor	dh, dh
	add	ax, dx
	mov	si, ax


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

ler_tempo proc	
 
	push ax
	push bx
	push cx
	push dx
	
	pushf
	
	mov ah, 2ch             ; buscar a horas
	int 21h                 
	
	xor ax,ax
	mov al, dh              ; segundos para al
	mov Segundos, ax		; guarda segundos na variavel correspondente
	
	xor ax,ax
	mov al, cl              ; minutos para al
	mov Minutos, ax         ; guarda minutos na variavel correspondente
	
	xor ax,ax
	mov al, ch              ; horas para al
	mov Horas,ax			; guarda horas na variavel correspondente

	popf
	pop dx
	pop cx
	pop bx
	pop ax
	ret 
ler_tempo   endp 
	
cseg    ends
end     main

	push ax		; Passagem de parâmetros a impnum (número a imprimir)
	call impnum		; imprime 10 aleatórios na parte direita do ecran
	loop ciclo4		; Ciclo de impressão dos números aleatórios
		
	mov ax, 0b800h	; Segmento de memória de vídeo onde vai ser desenhado o tabuleiro
	mov es, ax	
	mov linha, 	8	; O Tabuleiro vai começar a ser desenhado na linha 8 
	mov nlinhas, 6	; O Tabuleiro vai ter 6 linhas
		
ciclo2:	
	mov al, 160		
	mov ah, linha
	mul ah
	add ax, 60
	mov bx, ax		; Determina Endereço onde começa a "linha". bx = 160*linha + 60

	mov cx, 9		; São 9 colunas 
	
ciclo:  	
	mov dh,	tcar	; vai imprimir o caracter "SPACE"
	mov es:[bx], dh	;
	
novacor:	
	call CalcAleat	; Calcula próximo aleatório que é colocado na pilha 
	pop ax ; 		; Vai buscar 'a pilha o número aleatório
	and al, 01110000b	; posição do ecran com cor de fundo aleatório e caracter a preto
	cmp al, 0		; Se o fundo de ecran é preto
	je novacor		; vai buscar outra cor 

	mov dh, tcar	; Repete mais uma vez porque cada peça do tabuleiro ocupa dois carecteres de ecran
	mov es:[bx],   dh		
	mov es:[bx+1], al	; Coloca as características de cor da posição atual 
	inc bx		
	inc bx		; próxima posição e ecran dois bytes à frente 

	mov dh, tcar	; Repete mais uma vez porque cada peça do tabuleiro ocupa dois carecteres de ecran
	mov es:[bx], dh
	mov es:[bx+1], al
	inc bx
	inc bx
		
	mov di, 1 ;delay de 1 centesimo de segundo
	call delay
	loop ciclo		; continua até fazer as 9 colunas que correspondem a uma liha completa
		
	inc linha		; Vai desenhar a próxima linha
	dec nlinhas		; contador de linhas
	mov al, nlinhas
	cmp al, 0		; verifica se já desenhou todas as linhas 
	jne ciclo2		; se ainda há linhas a desenhar continua 
	
FIM:
	MOV AH, 4Ch
	INT 21h	

main	endp

CalcAleat proc near

	sub sp, 2
	push bp
	mov bp, sp
	push ax
	push cx
	push dx	
	mov ax, [bp+4]
	mov [bp+2], ax

	mov ah, 00h
	int 1ah

	add dx, ultimo_num_aleat	; vai buscar o aleatório anterior
	add cx, dx	
	mov ax, 65521
	push dx
	mul cx			
	pop dx			 
	xchg dl, dh
	add dx, 32749
	add dx, ax

	mov ultimo_num_aleat, dx	; guarda o novo numero aleatório  

	mov [BP+4], dx		; o aleatório é passado por pilha

	pop dx
	pop cx
	pop ax
	pop bp
	ret
CalcAleat endp

impnum proc near
	push bp
	mov	bp, sp
	push ax
	push bx
	push cx
	push dx
	push di
	mov ax, [bp+4] ;param3
	lea di, [str_num+5]
	mov cx, 5
	
prox_dig:
	xor dx, dx
	mov bx, 10
	div bx
	add dl, '0' ; dh é sempre 0
	dec di
	mov [di], dl
	loop prox_dig

	mov ah, 02h
	mov bh, 00h
	mov dl, [bp+7] ;param1
	mov dh, [bp+6] ;param2
	int 10h
	mov dx, di
	mov ah, 09h
	int 21h
	pop di
	pop dx
	pop cx
	pop bx
	pop ax
	pop bp
	ret 4 ;limpa parametros (4 bytes) colocados na pilha
	
impnum endp

delay proc
	pushf
	push ax
	push cx
	push dx
	push si
	
	mov ah, 2Ch
	int 21h
	mov al, 100
	mul dh
	xor dh, dh
	add ax, dx
	mov si, ax


ciclo:	mov ah, 2Ch
	int 21h
	mov al, 100
	mul dh
	xor dh, dh
	add ax, dx

	cmp ax, si 
	jnb naoajusta
	add ax, 6000 ; 60 segundos
naoajusta:
	sub ax, si
	cmp ax, di
	jb ciclo

	pop si
	pop dx
	pop cx
	pop ax
	popf
	ret
delay endp

cseg    ends
end     main
