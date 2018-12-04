#include <stdio.h>
//#include <bits/libc-header-start.h>

void main()
{
	int var1, var2, res;

	var1 = 5;
	var2 = 10;

	__asm__("movl $var1, %eax \n\t"
		"movl $var2, %ebx \n\t"
		"addl %eax, %ebx \n\t"
		"movl %ebx, $res \n\t");

	printf("Res = %i", res);
}
