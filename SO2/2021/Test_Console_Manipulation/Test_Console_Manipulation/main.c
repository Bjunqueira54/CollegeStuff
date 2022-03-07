#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define MAX 256

DWORD WINAPI ThreadProdutor(LPVOID param);
DWORD WINAPI ThreadConsumidor(LPVOID param);

HANDLE hMutex;
TCHAR frase[MAX];
BOOL nova = 0;

int _tmain(int argc, LPVOID argv[])
{
	TCHAR resp;
	DWORD threadId;
	HANDLE hThreadProd, hThreadCons;

	hMutex = CreateMutex(NULL, FALSE, NULL);

#ifdef UNICODE
	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);
#endif

	_tprintf(TEXT("Lançar threads produtor-consumidor?"));
	_tscanf_s(TEXT("%c"), &resp, 1);

	if (resp == 'S' || resp == 's')
	{
		hThreadProd = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadProdutor, NULL, 0, &threadId);

		if (hThreadProd != NULL)
			_tprintf(TEXT("Lancei uma thread com id %i\n"), threadId);
		else
		{
			_tprintf(TEXT("Não consegui lançar a thread\n"));
			return -1;
		}

		hThreadCons = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadConsumidor, NULL, 0, &threadId);

		if (hThreadCons != NULL)
			tprintf(TEXT("Lancei uma thread com id %d\n"), threadId);
		else
		{
			_tprintf(TEXT("Erro ao criar Thread\n"));
			return -1;
		}

		WaitForSingleObject(hThreadProd, INFINITE);
		WaitForSingleObject(hThreadCons, INFINITE);
	}

	_tprintf(TEXT("Thread principal - Vou terminar!\n"));

	return 0;
}

DWORD WINAPI ThreadProdutor(LPVOID param)
{
	TCHAR strLocal[MAX];

	_tprintf(TEXT("[Produtor] Sou a thread %i e vou começar a trabalhar"), GetCurrentThreadId());

	Sleep(100);

	do
	{
		_fgetts(strLocal, MAX, stdin);
		fflush(stdin);
		WaitForSingleObject(hMutex, INFINITE);
		_tcscpy_s(frase, MAX, strLocal);
		nova = TRUE;
		ReleaseMutex(hMutex);
	} while (_tcsncmp(strLocal, TEXT("fim"), 3));

	return 0;
}

DWORD WINAPI ThreadConsumidor(LPVOID param)
{
	TCHAR strLocal[MAX];
	_tprintf(TEXT("[Consumidor]Sou a thread %d e vou começar a trabalhar ...\n"), GetCurrentThreadId());
	Sleep(100);

	do
	{
		WaitForSingleObject(hMutex, INFINITE);
		if (nova)
		{
			_tcscpy_s(strLocal, MAX, frase);
			nova = FALSE;
			_tprintf(TEXT("[Consumidor]:%s"), strLocal);
		}

		ReleaseMutex(hMutex);
		Sleep(1000);
	} while (_tcsncmp(strLocal, TEXT("fim"), 3));

	return 0;
}