;--------------------------------------------------------------
; Abre ficheio de texto e envia para o ecran 
;
;--------------------------------------------------------------

.8086
.model small
.stack 2048

dseg	segment para public 'data'
;						texto		db	10 dup (10 dup (' '))

;						num		db	1
	
	POSy		db	4	; a linha pode ir de [ .. ]
	POSx		db	10	; POSx pode ir [ .. ]	

        Erro_Open       db      'Erro ao tentar abrir o ficheiro$'
        Erro_Ler_Msg    db      'Erro ao tentar ler do ficheiro$'
        Erro_Close      db      'Erro ao tentar fechar o ficheiro$'
        Fich         	db      'ABC.TXT',0
        HandleFich      dw      0
        car_fich        db      ?
	
	
dseg	ends

cseg	segment para public 'code'
assume	cs:cseg, ds:dseg



;########################################################################
goto_xy	macro	POSx,POSy
		mov	ah,02h
		mov	bh,0
		mov	dl,POSx
		mov	dh,POSy
		int	10h
endm

;########################################################################
;ROTINA PARA APAGAR ECRAN

apaga_ecran	proc
		xor	bx,bx
		mov	cx,25*80
		
apaga:		mov	byte ptr es:[bx],' '
		mov	byte ptr es:[bx+1],7
		inc	bx
		inc 	bx
		loop	apaga
		ret
apaga_ecran	endp



Imp_Fich	PROC

;abre ficheiro

        mov     ah,3dh			; vamos abrir ficheiro para leitura 
        mov     al,0			; tipo de ficheiro	
        lea     dx,Fich			; nome do ficheiro
        int     21h			; abre para leitura 
        jc      erro_abrir		; pode aconter erro a abrir o ficheiro 
        mov     HandleFich,ax		; ax devolve o Handle para o ficheiro 
        jmp     ler_ciclo		; depois de abero vamos ler o ficheiro 

erro_abrir:
        mov     ah,09h
        lea     dx,Erro_Open
        int     21h
        jmp     sai

ler_ciclo:
        mov     ah,3fh			; indica que vai ser lido um ficheiro 
        mov     bx,HandleFich		; bx deve conter o Handle do ficheiro previamente aberto 
        mov     cx,1			; numero de bytes a ler 
        lea     dx,car_fich		; vai ler para o local de memoria apontado por dx (car_fich)
        int     21h				; faz efectivamente a leitura
	jc	    erro_ler		; se carry é porque aconteceu um erro
	cmp	    ax,0			;EOF?	verifica se já estamos no fim do ficheiro 
	je	    fecha_ficheiro	; se EOF fecha o ficheiro 
        mov     ah,02h			; coloca o caracter no ecran
	  mov	    dl,car_fich		; este é o caracter a enviar para o ecran
	  int	    21h				; imprime no ecran
	  jmp	    ler_ciclo		; continua a ler o ficheiro

erro_ler:
        mov     ah,09h
        lea     dx,Erro_Ler_Msg
        int     21h

fecha_ficheiro:					; vamos fechar o ficheiro 
        mov     ah,3eh
        mov     bx,HandleFich
        int     21h
        jnc     sai

        mov     ah,09h			; o ficheiro pode não fechar correctamente
        lea     dx,Erro_Close
        Int     21h
sai:	  RET
Imp_Fich	endp


;########################################################################

	Main  proc
		mov	ax, dseg
		mov	ds,ax
		mov	ax,0B800h
		mov	es,ax

		
		call	apaga_ecran
		goto_xy	1,1
		call	Imp_Fich

			goto_xy	2,22
			mov	ah,4CH
			INT	21H
Main	endp
Cseg	ends
end	Main
