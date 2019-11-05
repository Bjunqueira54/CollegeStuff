#include <stdio.h>

int conta(int size)
{
	int contador = 0;

	for(int i = 0; i < size; i++)
		for(int j = 0; j < i; j++)
			contador++;

	for(int i = 0; i < size; i++)
		contador++;

	return contador;
}

int main(void)
{
	printf("Contador: %d\n", conta(100));

	return 0;
}
