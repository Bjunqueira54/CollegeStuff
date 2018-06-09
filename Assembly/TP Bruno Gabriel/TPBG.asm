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
	tabultimo_num_aleat	dw	0

	tabstr_num	db	5	dup(?),'$'
	
	tablinha	db	0	; Define o número da linha que está a ser desenhada
	tabnlinhas	db	0
	tabcor	db	0
	tabcar	db	' '	
		
	;VARIAVEIS DO TEMPORIZADOR
	tempSTR12	db	"            "	; String para 12 digitos	
	tempNUMERO	db	"                    $", 	; String destinada a guardar o número lido
	

	tempNUM_SP	db	"                    $" 	; PAra apagar zona de ecran
	tempDDMMAA	db	"                     "

	tempHoras	dw	0				; Vai guardar a HORA actual
	tempMinutos	dw	0				; Vai guardar os minutos actuais
	tempSegundos	dw	0				; Vai guardar os segundos actuais
	tempOld_seg	dw	0				; Guarda os últimos segundos que foram lidos
			

	tempPOSy	db	10	; a linha pode ir de [1 .. 25]
	tempPOSx	db	40	; POSx pode ir [1..80]	
	tempNUMDIG	db	0	; controla o numero de digitos do numero lido
	tempMAXDIG	db	4	; Constante que define o numero MAXIMO de digitos a ser aceite
	
	;VARIAVEIS DO CURSOR
	curstring	db	"Teste prático de T.I",0
	curCar		db	32	; Guarda um caracter do Ecran 
	curCor		db	7	; Guarda os atributos de cor do caracter
	curCar2		db	32	; Guarda um caracter do Ecran 
	curCor2		db	7	; Guarda os atributos de cor do caracter
	curPOSy		db	5	; a linha pode ir de [1 .. 25]
	curPOSx		db	10	; POSx pode ir [1..80]	
	curPOSya	db	5	; Posição anterior de y
	curPOSxa	db	10	; Posição anterior de x
	
	;VARIAVEIS DO FICHEIRO PARTE 1
	fname	db	'score.txt',0
	fhandle dw	0
	buffer	db	'1 5 6 7 8 9 1 5 7 8 9 2 3 7 8 15 16 18 19 20 3',13,10
			db	'+ - / * * + - - + * / * + - - + * / + - - + * ',13,10
			db	'10 12 14 7 9 11 13 5 10 15 7 8 9 10 13 5 10 11',13,10 
			db	'/ * + - - + * / + - / * * + - - + * * + - - + ',13,10
			db	'3 45 23 11 4 7 14 18 31 27 19 9 6 47 19 9 6 51',13,10
			db	'______________________________________________',13,10
	msgErrorCreate	db	"Ocorreu um erro na criacao do ficheiro!$"
	msgErrorWrite	db	"Ocorreu um erro na escrita para ficheiro!$"
	msgErrorClose	db	"Ocorreu um erro no fecho do ficheiro!$"
	
	;VARIAVEIS DO FICHEIRO PARTE 2
	
	fichPOSy	db	4	; a linha pode ir de [ .. ]
	fichPOSx	db	10	; POSx pode ir [ .. ]
	msgErrorOpen	db	"Ocorreu um erro na abertura do ficheiro!$"
	msgErrorRead	db	"Ocorreu um erro na leitura do ficheiro!$"
	car_fich	db	?

dseg	ends

cseg	segment para public 'code'
	assume	cs:cseg,	ds:dseg,	ss:pilha
	
	;PROGRAMA
main	proc

	mov ax, dseg
	mov ds, ax
	
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

le_tecla	proc

		mov		ah,08h
		int		21h
		mov		ah,0
		cmp		al,0
		jne		sai_tecla
		mov		ah, 08h
		int		21h
		mov		ah,1
sai_tecla:	ret

le_tecla	endp

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

	mov	[bp+4], dx		; o aleatório é passado por pilha

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
	mov tempSegundos, ax		; guarda segundos na variavel correspondente
	
	xor ax,ax
	mov al, cl              ; minutos para al
	mov tempMinutos, ax         ; guarda minutos na variavel correspondente
	
	xor ax,ax
	mov al, ch              ; horas para al
	mov tempHoras,ax			; guarda horas na variavel correspondente

	popf
	pop dx
	pop cx
	pop bx
	pop ax
	ret 
ler_tempo   endp

hoje proc	

		push ax
		push bx
		push cx
		push dx
		push si
		pushf
		
		mov ah, 2ah             ; buscar a data
		int 21h                 
		push cx                 ; ano-> pilha
		xor cx,cx              	; limpa cx
		mov cl, dh              ; mes para cl
		push cx                 ; mes-> pilha
		mov cl, dl				; dia para cl
		push cx                 ; dia -> pilha
		xor dh,dh                    
		xor	si,si
		
; dia ------------------ 
; dx=dx/ax --- resto dx   

		xor dx,dx               ; limpa dx
		pop ax                  ; tira dia da pilha
		mov cx, 0               ; cx = 0 
		mov bx, 10              ; divisor
		mov	cx,2
dd_div:                         
		div bx                  ; divide por 10
		push dx                 ; resto para pilha
		mov dx, 0               ; limpa resto
		loop dd_div
		mov	cx,2
dd_resto:
		pop dx                  ; resto da divisao
		add dl, 30h             ; add 30h (2) to dl
		mov tempDDMMAA[si],dl
		inc	si
		loop dd_resto            
		mov dl, '/'             ; separador
		mov tempDDMMAA[si],dl
		inc si
; mes -------------------
; dx=dx/ax --- resto dx

		mov dx, 0               ; limpar dx
		pop ax                  ; tira mes da pilha
		xor cx,cx               
		mov bx, 10				; divisor
		mov cx,2
mm_div:                         
		div bx                  ; divisao or 10
		push dx                 ; resto para pilha
		mov dx, 0               ; limpa resto
		loop mm_div
		mov cx,2 
mm_resto:
		pop dx                  ; resto
		add dl, 30h             ; soma 30h
		mov tempDDMMAA[si],dl
		inc si		
		loop mm_resto
		
		mov dl, '/'             ; character to display goes in dl
		mov tempDDMMAA[si],dl
		inc si
 
;  ano ----------------------

		mov dx, 0               
		pop ax                  ; mes para ax
		mov cx, 0               ; 
		mov bx, 10              ; 
 aa_div:                         
		div bx                   
		push dx                 ; guarda resto
		add cx, 1               ; soma 1 contador
		mov dx, 0               ; limpa resto
		cmp ax, 0               ; compara quotient com zero
		jne aa_div              ; se nao zero
aa_resto:
		pop dx                  
		add dl, 30h             ; add 30h (2) to dl
		mov tempDDMMAA[si],dl
		inc si
		loop aa_resto
		popf
		pop si
		pop dx
		pop cx
		pop bx
		pop ax
 		ret
		
hoje   endp 

tempLe_tecla	proc

sem_tecla:
	call Trata_Horas
	mov	ah, 0bh
	int 21h
	cmp AL, 0
	je	sem_tecla
		
	goto_xy	tempPOSx, tempPOSy
	
	call le_tecla
	
tempLe_tecla	endp

Trata_Horas PROC

	pushf
	push ax
	push bx
	push cx
	push dx		

	call 	ler_tempo				; Horas MINUTOS e segundos do Sistema
	
	mov		ax, tempSegundos
	cmp		ax, tempOld_seg			; VErifica se os segundos mudaram desde a ultima leitura
	je		fim_horas			; Se a hora não mudou desde a última leitura sai.
	mov		tempOld_seg, ax			; Se segundos são diferentes actualiza informação do tempo 
	
	mov 	ax, tempHoras
	mov		bl, 10     
	div 	bl
	add 	al, 30h				; Caracter Correspondente às dezenas
	add		ah,	30h				; Caracter Correspondente às unidades
	mov 	tempSTR12[0],al			; 
	mov 	tempSTR12[1],ah
	mov 	tempSTR12[2],'h'		
	mov 	tempSTR12[3],'$'
	goto_xy 2,1
	mostra tempSTR12 		
	
	mov 	ax, tempMinutos
	mov 	bl, 10     
	div 	bl
	add 	al, 30h				; Caracter Correspondente às dezenas
	add		ah,	30h				; Caracter Correspondente às unidades
	mov 	tempSTR12[0],al			; 
	mov 	tempSTR12[1],ah
	mov 	tempSTR12[2],'m'		
	mov 	tempSTR12[3],'$'
	goto_xy	6,1
	mostra	tempSTR12 		
		
	mov 	ax, tempSegundos
	mov 	bl, 10     
	div 	bl
	add 	al, 30h				; Caracter Correspondente às dezenas
	add		ah,	30h				; Caracter Correspondente às unidades
	mov 	tempSTR12[0],al			; 
	mov 	tempSTR12[1],ah
	mov 	tempSTR12[2],'s'		
	mov 	tempSTR12[3],'$'
	goto_xy	10,1
	mostra	tempSTR12 		
        
	call 	hoje				; Data de HOJE
	mov 	al, tempDDMMAA[0]	
	mov 	tempSTR12[0], al	
	mov 	al, tempDDMMAA[1]	
	mov 	tempSTR12[1], al	
	mov 	al, tempDDMMAA[2]	
	mov 	tempSTR12[2], al	
	mov 	al, tempDDMMAA[3]	
	mov 	tempSTR12[3], al	
	mov 	al, tempDDMMAA[4]	
	mov 	tempSTR12[4], al	
	mov 	al, tempDDMMAA[5]	
	mov 	tempSTR12[5], al	
	mov 	al, tempDDMMAA[6]	
	mov 	tempSTR12[6], al	
	mov 	al, tempDDMMAA[7]	
	mov 	tempSTR12[7], al	
	mov 	al, tempDDMMAA[8]	
	mov 	tempSTR12[8], al
	mov 	al, tempDDMMAA[9]	
	mov 	tempSTR12[9], al		
	mov 	tempSTR12[10], '$'
	goto_xy	68,1
	mostra	tempSTR12 	

fim_horas:		
	goto_xy	tempPOSx, tempPOSy			; Volta a colocar o cursor onde estava antes de actualizar as horas
	
	popf
	pop dx		
	pop cx
	pop bx
	pop ax
	ret
Trata_Horas endp

teclanum  proc
	mov	ax, dseg
	mov	ds,ax
	mov	ax, 0b800h
	mov	es, ax		; es é ponteiro para mem video

novon:	
	mov		tempNUMDIG, 0			; inícia leitura de novo número
	mov		cx, 20
	xor		bx, bx
limpa_n: 	
	mov		tempNUMERO[bx], ' '	
	inc		bx
	loop 	limpa_n
	
	mov		al, 20
	mov		tempposx, al
	mov		al, 10
	mov		tempposy, al				; (posx,posy) é posição do cursor
	goto_xy	tempposx, tempposy
	mostra	tempNUM_SP

ciclo:	
	goto_xy	tempposx, tempposy
	call 	tempLe_tecla		; lê uma nova tecla
	cmp		ah, 1			; verifica se é tecla extendida
	je		estend
	cmp 	al, 27			; caso seja tecla escape sai do programa
	je		fim
	cmp 	al, 13			; pressionando enter vai para oknum
	je		oknum		
	cmp 	al, 8			; teste back space <- (apagar digito)
	jne		noback
	mov		bl, tempNUMDIG		; se pressionou back space 
	cmp		bl, 0			; verifica se não tem digitos no numero
	je		noback			; se não tem digitos continua então não apaga e salta para noback

	dec		tempNUMDIG			; retira um digito (back space)
	dec		tempposx			; retira um digito	

	xor		bx,bx
	mov		bl, tempNUMDIG
	mov		tempNUMERO[bx],' '	; retira um digito		
	goto_xy	tempposx, tempposy
	mov		ah, 02h			; imprime space na possicão do cursor
	mov		dl, 32			; que equivale a colocar space 
	int		21h

noback:	
	cmp		al, 30h			; se for menor que tecla do zero
	jb		ciclo
	cmp		al, 39h			; ou se for maior que tecla do nove 
	ja		ciclo			; é rejeitado e vai buscar nova tecla 
	
	mov		bl, tempMAXDIG		; se atigido numero máximo de digitos ?	
	cmp		bl, tempNUMDIG	
	jbe		ciclo			; não aceita mais digitos
	xor		bx, bx			; caso contrario coloca digito na matriz numero
	mov		bl, tempNUMDIG
	mov		tempNUMERO[bx], al		
	mov		ah, 02h			; imprime digito 
	mov		dl, al			; na possicão do cursor
	int		21h

	inc		tempposx			; avança o cursor e
	inc		tempNUMDIG			; incrementa o numero de digitos

estend:	jmp	ciclo			; tecla extendida não é tratada neste programa 

oknum:	
	goto_xy	20, 16
	mostra	tempNUM_SP			
	goto_xy	20, 16		
	xor		bx, bx
	mov		bl, tempNUMDIG
	inc 	bl
	mov		tempNUMERO[bx], '$'			
	mostra	tempNUMERO 
	jmp		novon		; vai ler novo numero

fim:	ret

teclanum endp

Cursor proc

	mov	ax, dseg
	mov	ds,ax
	mov	ax, 0B800h
	mov	es, ax

	goto_xy	curPOSx, curPOSy	; Vai para nova possição
	mov ah, 08h	; Guarda o Caracter que está na posição do Cursor
	mov	bh, 0		; numero da página
	int	10h			
	mov	curCar, al	; Guarda o Caracter que está na posição do Cursor
	mov	curCor, ah	; Guarda a cor que está na posição do Cursor	
	
	inc	curPOSx
	goto_xy	curPOSx, curPOSy	; Vai para nova possição2
	mov 		ah, 08h		; Guarda o Caracter que está na posição do Cursor
	mov		bh,0		; numero da página
	int		10h			
	mov		curCar2, al	; Guarda o Caracter que está na posição do Cursor
	mov		curCor2, ah	; Guarda a cor que está na posição do Cursor	
	dec		curPOSx

ciclo:

	goto_xy	curPOSxa, curPOSya	; Vai para a posição anterior do cursor
	mov	ah, 02h
	mov	dl, curCar	; Repoe Caracter guardado 
	int	21H	

	inc	curPOSxa
	goto_xy	curPOSxa, curPOSya	
	mov	ah, 02h
	mov	dl, curCar2	; Repoe Caracter2 guardado 
	int	21H	
	dec curPOSxa
	
	goto_xy	curPOSx,curPOSy	; Vai para nova possição
	mov ah, 08h
	mov	bh, 0		; numero da página
	int	10h		
	mov	curCar, al	; Guarda o Caracter que está na posição do Cursor
	mov	curCor, ah	; Guarda a cor que está na posição do Cursor
	
	inc	curPOSx
	goto_xy	curPOSx, curPOSy	; Vai para nova possição
	mov ah, 08h
	mov	bh, 0		; numero da página
	int	10h		
	mov	curCar2, al	; Guarda o Caracter2 que está na posição do Cursor2
	mov	curCor2, ah	; Guarda a cor que está na posição do Cursor2
	dec	curPOSx
	
	
	goto_xy	77, 0		; Mostra o caractr que estava na posição do AVATAR
	mov	ah, 02h		; IMPRIME caracter da posição no canto
	mov	dl, curCar	
	int	21H			
	
	goto_xy	78,0		; Mostra o caractr2 que estava na posição do AVATAR
	mov	ah, 02h		; IMPRIME caracter2 da posição no canto
	mov	dl, curCar2	
	int	21H			

	goto_xy	curPOSx, curPOSy	; Vai para posição do cursor
	
imprime:	
	mov	ah, 02h
	mov	dl, '('	; Coloca AVATAR1
	int	21H
	
	inc	curPOSx
	goto_xy	curPOSx,curPOSy		
	mov	ah, 02h
	mov	dl, ')'	; Coloca AVATAR2
	int	21H	
	dec	curPOSx
	
	goto_xy	curPOSx,curPOSy	; Vai para posição do cursor
	
	mov	al, curPOSx	; Guarda a posição do cursor
	mov	curPOSxa, al
	mov	al, curPOSy	; Guarda a posição do cursor
	mov curPOSya, al
		
ler_seta:	
	call le_tecla
	cmp	ah, 1
	je	estend
	cmp AL, 27	; ESCAPE
	je	fim
	jmp	ler_seta

estend:
	cmp al, 48h
	jne	baixo
	dec	curPOSy		;cima
	jmp	ciclo

baixo:
	cmp	al, 50h
	jne	esquerda
	inc curPOSy		;Baixo
	jmp	ciclo

esquerda:
	cmp	al, 4Bh
	jne	direita
	dec	curPOSx		;Esquerda
	dec	curPOSx		;Esquerda

	jmp	ciclo

direita:
	cmp	al, 4Dh
	jne	ler_seta 
	inc	curPOSx		;Direita
	inc	curPOSx		;Direita
	
	jmp	ciclo

Cursor endp

CriaFich proc
	mov	ah, 3ch				; Abrir o ficheiro para escrita
	mov	cx, 00H				; Define o tipo de ficheiro ??
	lea	dx, fname			; DX aponta para o nome do ficheiro 
	int	21h					; Abre efectivamente o ficheiro (AX fica com o Handle do ficheiro)
	jnc	escreve				; Se não existir erro escreve no ficheiro

	mov	ah, 09h
	lea	dx, msgErrorCreate
	int	21h

	jmp	fim

escreve:
	mov	bx, ax				; Coloca em BX o Handle
	mov	ah, 40h				; indica que é para escrever
	
	lea	dx, buffer			; DX aponta para a infromação a escrever
	mov	cx, 240				; CX fica com o numero de bytes a escrever
	int	21h					; Chama a rotina de escrita
	jnc	close				; Se não existir erro na escrita fecha o ficheiro

	mov	ah, 09h
	lea	dx, msgErrorWrite
	int	21h
close:
	mov	ah, 3eh				; fecha o ficheiro
	int	21h
	jnc	fim

	mov	ah, 09h
	lea	dx, msgErrorClose
	int	21h
	
CriaFich endp

Imp_Fich	proc

;abre ficheiro

	mov	ah,3dh			; vamos abrir ficheiro para leitura 
	mov	al,0			; tipo de ficheiro	
	lea	dx, fname			; nome do ficheiro
	int	21h			; abre para leitura 
	jc	erro_abrir		; pode aconter erro a abrir o ficheiro 
	mov	fhandle, ax		; ax devolve o Handle para o ficheiro 
	jmp	ler_ciclo		; depois de abero vamos ler o ficheiro 

erro_abrir:
	mov	ah, 09h
	lea	dx, msgErrorOpen
	int	21h
	jmp	sai

ler_ciclo:
	mov	ah, 3fh			; indica que vai ser lido um ficheiro 
	mov	bx, fhandle		; bx deve conter o Handle do ficheiro previamente aberto 
	mov	cx, 1			; numero de bytes a ler 
	lea	dx, car_fich	; vai ler para o local de memoria apontado por dx (car_fich)
	int	21h				; faz efectivamente a leitura
	jc	erro_ler		; se carry é porque aconteceu um erro
	cmp	ax, 0			;EOF?	verifica se já estamos no fim do ficheiro 
	je	fecha_ficheiro	; se EOF fecha o ficheiro 
	mov	ah, 02h			; coloca o caracter no ecran
	mov	dl, car_fich	; este é o caracter a enviar para o ecran
	int	21h				; imprime no ecran
	jmp	ler_ciclo		; continua a ler o ficheiro

erro_ler:
	mov	ah, 09h
	lea	dx, msgErrorRead
	int	21h

fecha_ficheiro:					; vamos fechar o ficheiro 
	mov	ah, 3eh
	mov	bx, fhandle
	int	21h
	jnc	sai

	mov	ah, 09h			; o ficheiro pode não fechar correctamente
	lea	dx, msgErrorClose
	int	21h
	
sai: RET

Imp_Fich	endp

cseg    ends
end     main
