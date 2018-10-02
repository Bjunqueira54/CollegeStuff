#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		fprintf(stderr,"Syntax: %s <ENVIROMENT VARIABLE>", argv[1]);
		return -1;
	}

	char* env_var = getenv(argv[1]);
	if(env_var == NULL)
	{
		fprintf(stderr,"Env. Variable %s doesn't exist!", argv[1]);
		return -2;
	}
	else
	{
		printf("%s = %s\n", argv[1], env_var);
	}

	return 0;
}
