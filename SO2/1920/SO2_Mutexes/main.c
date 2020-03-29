#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <tchar.h>
#include <fcntl.h>

int _tmain(int argc, TCHAR* argv[])
{

#ifdef UNICODE

	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);

#endif

	return 0;
}