.8086
.model	small
.stack	2048

dseg    segment para public 'data'
 	;Variaveis
	
	ultimo_num_aleat dw 0

	str_num db 5 dup(?),'$'
	
        linha		db	0	; Define o número da linha que está a ser desenhada
        nlinhas		db	0
	cor		db 	0
	car		db	' '	
	
dseg    ends

cseg	segment para public 'code'
	assume  cs:cseg, ds:dseg
main	proc
	;PREPARAÇÃO DO PROGRAMA
	;MACROS
	
	goto_xy	macro		POSx,POSy
		mov		ah,02h
		mov		bh,0		; numero da página
		mov		dl,POSx
		mov		dh,POSy
		int		10h
	endm
	
	
	
	
	
	
	;PROGRAMA
	
	MOV	AX, dseg
	MOV	DS, AX
	
	mov ax, 0b800h
	mov es, ax
	mov dh, car
	mov dl, 0h
	mov cx, 25*80
	
	xor si, si
limpa_ecran:
	mov es:[si], dh
	mov es:[si+2], dl
	add di, 2
	loop limpa_ecran

	mov	cx,10		; Faz o ciclo 10 vezes
ciclo4:
		call	CalcAleat
		pop	ax 		; vai buscar 'a pilha o número aleatório

		mov	dl,cl	
		mov	dh,70
		push	dx		; Passagem de parâmetros a impnum (posição do ecran)
		push	ax		; Passagem de parâmetros a impnum (número a imprimir)
		call	impnum		; imprime 10 aleatórios na parte direita do ecran
		loop	ciclo4		; Ciclo de impressão dos números aleatórios
		
		mov   	ax, 0b800h	; Segmento de memória de vídeo onde vai ser desenhado o tabuleiro
		mov   	es, ax	
		mov	linha, 	8	; O Tabuleiro vai começar a ser desenhado na linha 8 
		mov	nlinhas, 6	; O Tabuleiro vai ter 6 linhas
		
ciclo2:		mov	al, 160		
		mov	ah, linha
		mul	ah
		add	ax, 60
		mov 	bx, ax		; Determina Endereço onde começa a "linha". bx = 160*linha + 60

		mov	cx, 9		; São 9 colunas 
ciclo:  	
		mov 	dh,	car	; vai imprimir o caracter "SPACE"
		mov	es:[bx],dh	;
	
novacor:	
		call	CalcAleat	; Calcula próximo aleatório que é colocado na pilha 
		pop	ax ; 		; Vai buscar 'a pilha o número aleatório
		and 	al,01110000b	; posição do ecran com cor de fundo aleatório e caracter a preto
		cmp	al, 0		; Se o fundo de ecran é preto
		je	novacor		; vai buscar outra cor 

		mov 	dh,	   car	; Repete mais uma vez porque cada peça do tabuleiro ocupa dois carecteres de ecran
		mov	es:[bx],   dh		
		mov	es:[bx+1], al	; Coloca as características de cor da posição atual 
		inc	bx		
		inc	bx		; próxima posição e ecran dois bytes à frente 

		mov 	dh,	   car	; Repete mais uma vez porque cada peça do tabuleiro ocupa dois carecteres de ecran
		mov	es:[bx],   dh
		mov	es:[bx+1], al
		inc	bx
		inc	bx
		
		mov	di,1 ;delay de 1 centesimo de segundo
		call	delay
		loop	ciclo		; continua até fazer as 9 colunas que correspondem a uma liha completa
		
		inc	linha		; Vai desenhar a próxima linha
		dec	nlinhas		; contador de linhas
		mov	al, nlinhas
		cmp	al, 0		; verifica se já desenhou todas as linhas 
		jne	ciclo2		; se ainda há linhas a desenhar continua 
FIM:
	MOV	AH,4Ch
	INT	21h	

main	endp

CalcAleat proc near

	sub	sp,2		; 
	push	bp
	mov	bp,sp
	push	ax
	push	cx
	push	dx	
	mov	ax,[bp+4]
	mov	[bp+2],ax

	mov	ah,00h
	int	1ah

	add	dx,ultimo_num_aleat	; vai buscar o aleatório anterior
	add	cx,dx	
	mov	ax,65521
	push	dx
	mul	cx			
	pop	dx			 
	xchg	dl,dh
	add	dx,32749
	add	dx,ax

	mov	ultimo_num_aleat,dx	; guarda o novo numero aleatório  

	mov	[BP+4],dx		; o aleatório é passado por pilha

	pop	dx
	pop	cx
	pop	ax
	pop	bp
	ret
CalcAleat endp

impnum proc near
	push	bp
	mov	bp,sp
	push	ax
	push	bx
	push	cx
	push	dx
	push	di
	mov	ax,[bp+4] ;param3
	lea	di,[str_num+5]
	mov	cx,5
prox_dig:
	xor	dx,dx
	mov	bx,10
	div	bx
	add	dl,'0' ; dh e' sempre 0
	dec	di
	mov	[di],dl
	loop	prox_dig

	mov	ah,02h
	mov	bh,00h
	mov	dl,[bp+7] ;param1
	mov	dh,[bp+6] ;param2
	int	10h
	mov	dx,di
	mov	ah,09h
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
	push	ax
	push	cx
	push	dx
	push	si
	
	mov	ah,2Ch
	int	21h
	mov	al,100
	mul	dh
	xor	dh,dh
	add	ax,dx
	mov	si,ax


ciclo:	mov	ah,2Ch
	int	21h
	mov	al,100
	mul	dh
	xor	dh,dh
	add	ax,dx

	cmp	ax,si 
	jnb	naoajusta
	add	ax,6000 ; 60 segundos
naoajusta:
	sub	ax,si
	cmp	ax,di
	jb	ciclo

	pop	si
	pop	dx
	pop	cx
	pop	ax
	popf
	ret
delay endp

cseg    ends
end     main.8086
.model	small
.stack	2048

dseg    segment para public 'data'
 	;Variaveis
	
	ultimo_num_aleat dw 0

	str_num db 5 dup(?),'$'
	
        linha		db	0	; Define o número da linha que está a ser desenhada
        nlinhas		db	0
	cor		db 	0
	car		db	' '	
	
dseg    ends

cseg	segment para public 'code'
	assume  cs:cseg, ds:dseg
main	proc
	;PREPARAÇÃO DO PROGRAMA
	;MACROS
	
	goto_xy	macro		POSx,POSy
		mov		ah,02h
		mov		bh,0		; numero da página
		mov		dl,POSx
		mov		dh,POSy
		int		10h
	endm
	
	
	
	
	
	
	;PROGRAMA
	
	MOV	AX, dseg
	MOV	DS, AX
	
	mov ax, 0b800h
	mov es, ax
	mov dh, car
	mov dl, 0h
	mov cx, 25*80
	
	xor si, si
limpa_ecran:
	mov es[si], dh
	mov es[si+2], dl
	add di, 2
	loop limpa_ecran

	mov	cx,10		; Faz o ciclo 10 vezes
ciclo4:
		call	CalcAleat
		pop	ax 		; vai buscar 'a pilha o número aleatório

		mov	dl,cl	
		mov	dh,70
		push	dx		; Passagem de parâmetros a impnum (posição do ecran)
		push	ax		; Passagem de parâmetros a impnum (número a imprimir)
		call	impnum		; imprime 10 aleatórios na parte direita do ecran
		loop	ciclo4		; Ciclo de impressão dos números aleatórios
		
		mov   	ax, 0b800h	; Segmento de memória de vídeo onde vai ser desenhado o tabuleiro
		mov   	es, ax	
		mov	linha, 	8	; O Tabuleiro vai começar a ser desenhado na linha 8 
		mov	nlinhas, 6	; O Tabuleiro vai ter 6 linhas
		
ciclo2:		mov	al, 160		
		mov	ah, linha
		mul	ah
		add	ax, 60
		mov 	bx, ax		; Determina Endereço onde começa a "linha". bx = 160*linha + 60

		mov	cx, 9		; São 9 colunas 
ciclo:  	
		mov 	dh,	car	; vai imprimir o caracter "SPACE"
		mov	es:[bx],dh	;
	
novacor:	
		call	CalcAleat	; Calcula próximo aleatório que é colocado na pilha 
		pop	ax ; 		; Vai buscar 'a pilha o número aleatório
		and 	al,01110000b	; posição do ecran com cor de fundo aleatório e caracter a preto
		cmp	al, 0		; Se o fundo de ecran é preto
		je	novacor		; vai buscar outra cor 

		mov 	dh,	   car	; Repete mais uma vez porque cada peça do tabuleiro ocupa dois carecteres de ecran
		mov	es:[bx],   dh		
		mov	es:[bx+1], al	; Coloca as características de cor da posição atual 
		inc	bx		
		inc	bx		; próxima posição e ecran dois bytes à frente 

		mov 	dh,	   car	; Repete mais uma vez porque cada peça do tabuleiro ocupa dois carecteres de ecran
		mov	es:[bx],   dh
		mov	es:[bx+1], al
		inc	bx
		inc	bx
		
		mov	di,1 ;delay de 1 centesimo de segundo
		call	delay
		loop	ciclo		; continua até fazer as 9 colunas que correspondem a uma liha completa
		
		inc	linha		; Vai desenhar a próxima linha
		dec	nlinhas		; contador de linhas
		mov	al, nlinhas
		cmp	al, 0		; verifica se já desenhou todas as linhas 
		jne	ciclo2		; se ainda há linhas a desenhar continua 
.8086
.model	small
.stack	2048

dseg    segment para public 'data'
 	;Variaveis
	
	ultimo_num_aleat dw 0

	str_num db 5 dup(?),'$'
	
        linha		db	0	; Define o número da linha que está a ser desenhada
        nlinhas		db	0
	cor		db 	0
	car		db	' '	
	
dseg    ends

cseg	segment para public 'code'
	assume  cs:cseg, ds:dseg
main	proc
	;PREPARAÇÃO DO PROGRAMA
	;MACROS
	
	goto_xy	macro		POSx,POSy
		mov		ah,02h
		mov		bh,0		; numero da página
		mov		dl,POSx
		mov		dh,POSy
		int		10h
	endm
	
	
	
	
	
	
	;PROGRAMA
	
	MOV	AX, dseg
	MOV	DS, AX
	
	mov ax, 0b800h
	mov es, ax
	mov dh, car
	mov dl, 0h
	mov cx, 25*80
	
	xor si, si
limpa_ecran:
	mov es:[si], dh
	mov es:[si+2], dl
	add di, 2
	loop limpa_ecran

	mov	cx,10		; Faz o ciclo 10 vezes
ciclo4:
		call	CalcAleat
		pop	ax 		; vai buscar 'a pilha o número aleatório

		mov	dl,cl	
		mov	dh,70
		push	dx		; Passagem de parâmetros a impnum (posição do ecran)
		push	ax		; Passagem de parâmetros a impnum (número a imprimir)
		call	impnum		; imprime 10 aleatórios na parte direita do ecran
		loop	ciclo4		; Ciclo de impressão dos números aleatórios
		
		mov   	ax, 0b800h	; Segmento de memória de vídeo onde vai ser desenhado o tabuleiro
		mov   	es, ax	
		mov	linha, 	8	; O Tabuleiro vai começar a ser desenhado na linha 8 
		mov	nlinhas, 6	; O Tabuleiro vai ter 6 linhas
		
ciclo2:		mov	al, 160		
		mov	ah, linha
		mul	ah
		add	ax, 60
		mov 	bx, ax		; Determina Endereço onde começa a "linha". bx = 160*linha + 60

		mov	cx, 9		; São 9 colunas 
ciclo:  	
		mov 	dh,	car	; vai imprimir o caracter "SPACE"
		mov	es:[bx],dh	;
	
novacor:	
		call	CalcAleat	; Calcula próximo aleatório que é colocado na pilha 
		pop	ax ; 		; Vai buscar 'a pilha o número aleatório
		and 	al,01110000b	; posição do ecran com cor de fundo aleatório e caracter a preto
		cmp	al, 0		; Se o fundo de ecran é preto
		je	novacor		; vai buscar outra cor 

		mov 	dh,	   car	; Repete mais uma vez porque cada peça do tabuleiro ocupa dois carecteres de ecran
		mov	es:[bx],   dh		
		mov	es:[bx+1], al	; Coloca as características de cor da posição atual 
		inc	bx		
		inc	bx		; próxima posição e ecran dois bytes à frente 

		mov 	dh,	   car	; Repete mais uma vez porque cada peça do tabuleiro ocupa dois carecteres de ecran
		mov	es:[bx],   dh
		mov	es:[bx+1], al
		inc	bx
		inc	bx
		
		mov	di,1 ;delay de 1 centesimo de segundo
		call	delay
		loop	ciclo		; continua até fazer as 9 colunas que correspondem a uma liha completa
		
		inc	linha		; Vai desenhar a próxima linha
		dec	nlinhas		; contador de linhas
		mov	al, nlinhas
		cmp	al, 0		; verifica se já desenhou todas as linhas 
		jne	ciclo2		; se ainda há linhas a desenhar continua 
FIM:
	MOV	AH,4Ch
	INT	21h	

main	endp

CalcAleat proc near

	sub	sp,2		; 
	push	bp
	mov	bp,sp
	push	ax
	push	cx
	push	dx	
	mov	ax,[bp+4]
	mov	[bp+2],ax

	mov	ah,00h
	int	1ah

	add	dx,ultimo_num_aleat	; vai buscar o aleatório anterior
	add	cx,dx	
	mov	ax,65521
	push	dx
	mul	cx			
	pop	dx			 
	xchg	dl,dh
	add	dx,32749
	add	dx,ax

	mov	ultimo_num_aleat,dx	; guarda o novo numero aleatório  

	mov	[BP+4],dx		; o aleatório é passado por pilha

	pop	dx
	pop	cx
	pop	ax
	pop	bp
	ret
CalcAleat endp

impnum proc near
	push	bp
	mov	bp,sp
	push	ax
	push	bx
	push	cx
	push	dx
	push	di
	mov	ax,[bp+4] ;param3
	lea	di,[str_num+5]
	mov	cx,5
prox_dig:
	xor	dx,dx
	mov	bx,10
	div	bx
	add	dl,'0' ; dh e' sempre 0
	dec	di
	mov	[di],dl
	loop	prox_dig

	mov	ah,02h
	mov	bh,00h
	mov	dl,[bp+7] ;param1
	mov	dh,[bp+6] ;param2
	int	10h
	mov	dx,di
	mov	ah,09h
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
	push	ax
	push	cx
	push	dx
	push	si
	
	mov	ah,2Ch
	int	21h
	mov	al,100
	mul	dh
	xor	dh,dh
	add	ax,dx
	mov	si,ax


ciclo:	mov	ah,2Ch
	int	21h
	mov	al,100
	mul	dh
	xor	dh,dh
	add	ax,dx

	cmp	ax,si 
	jnb	naoajusta
	add	ax,6000 ; 60 segundos
naoajusta:
	sub	ax,si
	cmp	ax,di
	jb	ciclo

	pop	si
	pop	dx
	pop	cx
	pop	ax
	popf
	ret
delay endp

cseg    ends
end     main
	mov	ah,02h
	mov	bh,00h
	mov	dl,[bp+7] ;param1
	mov	dh,[bp+6] ;param2
	int	10h
	mov	dx,di
	mov	ah,09h
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
	push	ax
	push	cx
	push	dx
	push	si
	
	mov	ah,2Ch
	int	21h
	mov	al,100
	mul	dh
	xor	dh,dh
	add	ax,dx
	mov	si,ax


ciclo:	mov	ah,2Ch
	int	21h
	mov	al,100
	mul	dh
	xor	dh,dh
	add	ax,dx

	cmp	ax,si 
	jnb	naoajusta
	add	ax,6000 ; 60 segundos
naoajusta:
	sub	ax,si
	cmp	ax,di
	jb	ciclo

	pop	si
	pop	dx
	pop	cx
	pop	ax
	popf
	ret
delay endp

cseg    ends
end     main
	mov es[di], dh
	mov es[di+2], dl
	add di, 2
	loop limpa_ecran

	mov	cx,10		; Faz o ciclo 10 vezes
ciclo4:
		call	CalcAleat
		pop	ax 		; vai buscar 'a pilha o número aleatório

		mov	dl,cl	
		mov	dh,70
		push	dx		; Passagem de parâmetros a impnum (posição do ecran)
		push	ax		; Passagem de parâmetros a impnum (número a imprimir)
		call	impnum		; imprime 10 aleatórios na parte direita do ecran
		loop	ciclo4		; Ciclo de impressão dos números aleatórios
		
		mov   	ax, 0b800h	; Segmento de memória de vídeo onde vai ser desenhado o tabuleiro
		mov   	es, ax	
		mov	linha, 	8	; O Tabuleiro vai começar a ser desenhado na linha 8 
		mov	nlinhas, 6	; O Tabuleiro vai ter 6 linhas
		
ciclo2:		mov	al, 160		
		mov	ah, linha
		mul	ah
		add	ax, 60
		mov 	bx, ax		; Determina Endereço onde começa a "linha". bx = 160*linha + 60

		mov	cx, 9		; São 9 colunas 
ciclo:  	
		mov 	dh,	car	; vai imprimir o caracter "SPACE"
		mov	es:[bx],dh	;
	
novacor:	
		call	CalcAleat	; Calcula próximo aleatório que é colocado na pilha 
		pop	ax ; 		; Vai buscar 'a pilha o número aleatório
		and 	al,01110000b	; posição do ecran com cor de fundo aleatório e caracter a preto
		cmp	al, 0		; Se o fundo de ecran é preto
		je	novacor		; vai buscar outra cor 

		mov 	dh,	   car	; Repete mais uma vez porque cada peça do tabuleiro ocupa dois carecteres de ecran
		mov	es:[bx],   dh		
		mov	es:[bx+1], al	; Coloca as características de cor da posição atual 
		inc	bx		
		inc	bx		; próxima posição e ecran dois bytes à frente 

		mov 	dh,	   car	; Repete mais uma vez porque cada peça do tabuleiro ocupa dois carecteres de ecran
		mov	es:[bx],   dh
		mov	es:[bx+1], al
		inc	bx
		inc	bx
		
		mov	di,1 ;delay de 1 centesimo de segundo
		call	delay
		loop	ciclo		; continua até fazer as 9 colunas que correspondem a uma liha completa
		
		inc	linha		; Vai desenhar a próxima linha
		dec	nlinhas		; contador de linhas
		mov	al, nlinhas
		cmp	al, 0		; verifica se já desenhou todas as linhas 
		jne	ciclo2		; se ainda há linhas a desenhar continua 
FIM:
	MOV	AH,4Ch
	INT	21h	

main	endp

CalcAleat proc near

	sub	sp,2		; 
	push	bp
	mov	bp,sp
	push	ax
	push	cx
	push	dx	
	mov	ax,[bp+4]
	mov	[bp+2],ax

	mov	ah,00h
	int	1ah

	add	dx,ultimo_num_aleat	; vai buscar o aleatório anterior
	add	cx,dx	
	mov	ax,65521
	push	dx
	mul	cx			
	pop	dx			 
	xchg	dl,dh
	add	dx,32749
	add	dx,ax

	mov	ultimo_num_aleat,dx	; guarda o novo numero aleatório  

	mov	[BP+4],dx		; o aleatório é passado por pilha

	pop	dx
	pop	cx
	pop	ax
	pop	bp
	ret
CalcAleat endp

impnum proc near
	push	bp
	mov	bp,sp
	push	ax
	push	bx
	push	cx
	push	dx
	push	di
	mov	ax,[bp+4] ;param3
	lea	di,[str_num+5]
	mov	cx,5
prox_dig:
	xor	dx,dx
	mov	bx,10
	div	bx
	add	dl,'0' ; dh e' sempre 0
	dec	di
	mov	[di],dl
	loop	prox_dig

	mov	ah,02h
	mov	bh,00h
	mov	dl,[bp+7] ;param1
	mov	dh,[bp+6] ;param2
	int	10h
	mov	dx,di
	mov	ah,09h
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
	push	ax
	push	cx
	push	dx
	push	si
	
	mov	ah,2Ch
	int	21h
	mov	al,100
	mul	dh
	xor	dh,dh
	add	ax,dx
	mov	si,ax


ciclo:	mov	ah,2Ch
	int	21h
	mov	al,100
	mul	dh
	xor	dh,dh
	add	ax,dx

	cmp	ax,si 
	jnb	naoajusta
	add	ax,6000 ; 60 segundos
naoajusta:
	sub	ax,si
	cmp	ax,di
	jb	ciclo

	pop	si
	pop	dx
	pop	cx
	pop	ax
	popf
	ret
delay endp

cseg    ends
end     main
		mov 	dh,	car	; vai imprimir o caracter "SPACE"
		mov	es:[bx],dh	;
	
novacor:	
		call	CalcAleat	; Calcula próximo aleatório que é colocado na pinha 
		pop	ax ; 		; Vai buscar 'a pilha o número aleatório
		and 	al,01110000b	; posição do ecran com cor de fundo aleatório e caracter a preto
		cmp	al, 0		; Se o fundo de ecran é preto
		je	novacor		; vai buscar outra cor 

		mov 	dh,	   car	; Repete mais uma vez porque cada peça do tabuleiro ocupa dois carecteres de ecran
		mov	es:[bx],   dh		
		mov	es:[bx+1], al	; Coloca as características de cor da posição atual 
		inc	bx		
		inc	bx		; próxima posição e ecran dois bytes à frente 

		mov 	dh,	   car	; Repete mais uma vez porque cada peça do tabuleiro ocupa dois carecteres de ecran
		mov	es:[bx],   dh
		mov	es:[bx+1], al
		inc	bx
		inc	bx
		
		mov	di,1 ;delay de 1 centesimo de segundo
		call	delay
		loop	ciclo		; continua até fazer as 9 colunas que correspondem a uma liha completa
		
		inc	linha		; Vai desenhar a próxima linha
		dec	nlinhas		; contador de linhas
		mov	al, nlinhas
		cmp	al, 0		; verifica se já desenhou todas as linhas 
		jne	ciclo2		; se ainda há linhas a desenhar continua 
FIM:
	MOV	AH,4Ch
	INT	21h	

main	endp

CalcAleat proc near

	sub	sp,2		; 
	push	bp
	mov	bp,sp
	push	ax
	push	cx
	push	dx	
	mov	ax,[bp+4]
	mov	[bp+2],ax

	mov	ah,00h
	int	1ah

	add	dx,ultimo_num_aleat	; vai buscar o aleatório anterior
	add	cx,dx	
	mov	ax,65521
	push	dx
	mul	cx			
	pop	dx			 
	xchg	dl,dh
	add	dx,32749
	add	dx,ax

	mov	ultimo_num_aleat,dx	; guarda o novo numero aleatório  

	mov	[BP+4],dx		; o aleatório é passado por pilha

	pop	dx
	pop	cx
	pop	ax
	pop	bp
	ret
CalcAleat endp

impnum proc near
	push	bp
	mov	bp,sp
	push	ax
	push	bx
	push	cx
	push	dx
	push	di
	mov	ax,[bp+4] ;param3
	lea	di,[str_num+5]
	mov	cx,5
prox_dig:
	xor	dx,dx
	mov	bx,10
	div	bx
	add	dl,'0' ; dh e' sempre 0
	dec	di
	mov	[di],dl
	loop	prox_dig

	mov	ah,02h
	mov	bh,00h
	mov	dl,[bp+7] ;param1
	mov	dh,[bp+6] ;param2
	int	10h
	mov	dx,di
	mov	ah,09h
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
	push	ax
	push	cx
	push	dx
	push	si
	
	mov	ah,2Ch
	int	21h
	mov	al,100
	mul	dh
	xor	dh,dh
	add	ax,dx
	mov	si,ax


ciclo:	mov	ah,2Ch
	int	21h
	mov	al,100
	mul	dh
	xor	dh,dh
	add	ax,dx

	cmp	ax,si 
	jnb	naoajusta
	add	ax,6000 ; 60 segundos
naoajusta:
	sub	ax,si
	cmp	ax,di
	jb	ciclo

	pop	si
	pop	dx
	pop	cx
	pop	ax
	popf
	ret
delay endp

cseg    ends
end     main
