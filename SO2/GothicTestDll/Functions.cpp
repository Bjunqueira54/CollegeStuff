#include "stdafx.h"
#include <utility>
#include <limits.h>
#include <stdlib.h>
#include <time.h>
#include "Header.h"

GOTHICTESTDLL_API void SayHello()
{
	printf("Hello World\n");
}

GOTHICTESTDLL_API int GiveRandom()
{
	srand(time(NULL));

	return rand() % 100 + 1;
}

GOTHICTESTDLL_API void SayGoodBye()
{
	printf("Good bye sir\n");
}