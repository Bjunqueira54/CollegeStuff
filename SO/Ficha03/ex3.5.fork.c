#include <stdio.h>
#include <unistd.h>   /* fork() */

int main(int argc, char** argv) {
	int a = 10;
	
	if (fork() == 0)
		a++;
	else
		a--;
	printf("\na = %d\n",a);
	return (0);
}