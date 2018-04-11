.8086
.model	small
.stack	2048

dseg    segment para public 'data'
 	var1b           db	0ADH// ad(16)
	string          db	'PATA',0//----> "p"=50 a=41 t=54 a=41
	var1w           dw	173 //----> 173(10)---->AD (16)
	var1dw          dd	10101101b //---->10101101(2)---> AD(16)
	var2w           word	-28// converter para binario puro e depois para complementos de 2
	var3w           sword	-28
	var2b           byte	-28
	var3b           sbyte	-28
	var2dw          dword	-28
	var3dw         	sdword	-28
	CharArray	dw      3 dup (0CCh)
	Square         	byte	0, 1, 4,9,16 
	ThreeD          db      2 dup (4 dup (2 dup (052h)))// 2*4*2=16 elementos com valor 52
	TwoD            db      2 dup (2 dup (12h))// 2*2 =4 --> com valor 12
	IntArray        word    4 dup (0BCh) // 4 elementos 00bc
	var1f		fword	65535 // base (16)=ffff
	var1q		qword   65534// base (16)=fffe
	var1t		tbyte	65533// base (16)=fffd
	X               REAL4	4.0// passar para formato iee754
	Y               REAL8   2.75e-2
	Z               REAL10  4.875
dseg    ends

cseg	segment para public 'code'
	assume  cs:cseg, ds:dseg
main	proc
	mov     ax, dseg
	mov     ds, ax
	mov     al,5
	mov     var1b,al
	mov     al,6
	mov     var2b,al
	mov     al,7
	mov     var3b,al
	mov     ax, var3w
	mov     word ptr CharArray[si],ax
fim:	mov     ah,4ch
	int     21h
main	endp
cseg    ends
end     Main