#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv, char **envv)
{
	while(*envv != NULL)
	{
		printf("%s\n", *envv++);
	}

	return 0;
}
