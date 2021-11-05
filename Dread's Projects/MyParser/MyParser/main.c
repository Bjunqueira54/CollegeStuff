#include <stdlib.h>
#include <stdio.h>

#include "parser.h"

int main(int argc, char** argv)
{
	fprintf(stdout, "Please input your string\n");
	fprintf(stdout, "-> ");

	char s_input[1024 * 4]; //4KB buffer should be enough for any string unless specifically trying to bust it.

	fgets(s_input, sizeof(char) * 1024 * 4, stdin);

	fprintf(stdout, "One moment...");

	char** parsed_input = stringParser(s_input);

	int i = 0;

	while (1)
	{
		if (parsed_input[i] == NULL)
			break;
		i++;
	}

	fprintf(stdout, "Your string has %d words\n", i);

	return 0;
}