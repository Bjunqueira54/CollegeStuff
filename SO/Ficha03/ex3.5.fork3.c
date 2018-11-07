#include <stdio.h>
#include <unistd.h>   /* fork() */

int main(int argc, char** argv) {
	int a = 10;
	char buffer [20] ="";
	int pid = 0;
	
	if ((pid=fork()) == 0) {		
		a++;
		printf("\nChild: a = %d\n",a);
		scanf("%18s", buffer);
		printf("\nChild: buffer = %s\n",buffer);
	}
	else {
		a--;
		printf("\nParent. Child PID=%d, a = %d\n",pid, a);
		scanf("%18s", buffer);
		printf("\nParent: buffer = %s\n",buffer);
	}
	
	return (0);
}