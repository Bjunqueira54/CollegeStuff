#include <windows.h>
#include <tchar.h>
#include <fcntl.h>
#include <io.h>
#include <stdio.h>
#define MAX 256

int _tmain(int argc, LPTSTR argv[])
{
	TCHAR str[MAX];
	TCHAR result[MAX] = TEXT("Ol�! Este programa � para aceitar UNICODE. Insira \'fim\' para sair\n");

	unsigned int i;

#ifdef UNICODE
	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);
#endif

	do
	{
		_tprintf(result);
		fflush(stdin);
		_fgetts(str, MAX, stdin);
		str[_tcslen(str) - 1] = '\0';

		for (int i = 0; i < _tcslen(str); i++)
			str[i] = _totupper(str[i]);
		_stprintf_s(result, MAX, TEXT("Frase:%s, Tamanho : %d\n"),str, _tcslen(str));
	}
	while (_tcsicmp(TEXT("FIM"), str));

	return 0;
}