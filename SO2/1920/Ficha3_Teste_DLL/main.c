#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>

#define TAM 256

double getUserInput()
{
	double valor = 0;
	TCHAR buffer[TAM] = _TEXT("");
	fflush(stdin);

	_fgetts(buffer, TAM, stdin);

	buffer[_tcslen(buffer) - 1] = '\0';

	valor = _tstoi(buffer);

	return valor;
}

int _tmain(int argc, TCHAR** argv)
{
	HINSTANCE hLib = NULL;

	double a = 0, b = 0;
	int sair = 0;

	TCHAR DLLpath[TAM] = _TEXT(".\\SO2_F3_DLL.dll");

	double (*ptrVar) = NULL;
	double (*ptrFunc)(double) = NULL;

#ifdef UNICODE

	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);
	_setmode(_fileno(stderr), _O_WTEXT);

#endif

	hLib = LoadLibrary(DLLpath);

	if (hLib == NULL)
		return -1;

	ptrFunc = (double (*) (double)) GetProcAddress(hLib, "applyFactor");
	ptrVar = (double*) GetProcAddress(hLib, "factor");

	if (ptrFunc == NULL || ptrVar == NULL)
		return -2;

	_tprintf("\nValor inicial da variavel factor: %f\n", *(double*) ptrVar);

	do
	{
		_tprintf("Variavel a: ");
		a = getUserInput();

		_tprintf("\n");
		_tprintf("A tua variavel a: %f\n", a);

		if (a == -1)
		{
			sair = 1;
			continue;
		}

		*(double*) ptrVar = a;

		_tprintf("Variavel b: ");
		b = getUserInput();

		_tprintf("A tua variavel b: %f\n", b);

		if (b == -1)
		{
			sair = 1;
			continue;
		}

		_tprintf("Resultado da funcao applyFactor: %f\n", ptrFunc(b));
	}
	while (sair != 1);

	FreeLibrary(hLib);

	_gettchar();

	return 0;
}