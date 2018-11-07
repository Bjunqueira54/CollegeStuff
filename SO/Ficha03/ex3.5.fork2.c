#include <stdio.h>
#include <unistd.h>   /* fork() */

int main(int argc, char** argv) {
	int a = 10;
	char buffer [20] ="";
	
	if (fork() == 0)
		a++;
	else
		a--;
	scanf("%18s", buffer);
	printf("\na = %d\n",a);
	return (0);
}