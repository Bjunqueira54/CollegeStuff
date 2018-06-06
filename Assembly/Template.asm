.8086
.model	small
.stack	2048

dseg    segment para public 'data'
 	;Variaveis
dseg    ends

cseg	segment para public 'code'
	assume  cs:cseg, ds:dseg
main	proc
	mov     ax, dseg
	mov     ds, ax
	; Código
	
main	endp
cseg    ends
end     main
