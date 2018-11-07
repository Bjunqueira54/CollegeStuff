#ifndef TESTHEADER_H
#define TESTHEADER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <stdio.h>

void Sum(int a, int b)
{
	printf("The sum of %i and %i is %i\n", a, b, a+b);
}

#ifdef __cplusplus
}
#endif

#endif
