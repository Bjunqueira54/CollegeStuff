#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <tchar.h>
#include <fcntl.h>
#include <time.h>

#define LIM 1000
#define TAM 100

typedef struct
{
	int inicio;
	int limite;
	int resultado;
} PARAM;

DWORD WINAPI ThreadPares(LPVOID param);
DWORD WINAPI ThreadPrimos(LPVOID param);

int _tmain(int argc, TCHAR* argv)
{
	PARAM pPares[2], pPrimos[2];
	DWORD threadParesId[2] = {0, 0}, threadPrimosId[2] = { 0, 0 };
	HANDLE htPares[2], htPrimos[2];
	TCHAR strMainId[TAM] = TEXT("");

	pPares[0].inicio = 0;
	pPares[0].limite = (int) LIM / 2;
	pPares[0].resultado = 0;
	htPares[0] = NULL;

	pPares[1].inicio = ((int)LIM / 2) + 1;
	pPares[1].limite = LIM;
	pPares[1].resultado = 0;
	htPares[1] = NULL;

	pPrimos[0].inicio = 2;
	pPrimos[0].limite = (int)LIM / 2;
	pPrimos[0].resultado = 0;
	htPrimos[0] = NULL;

	pPrimos[1].inicio = ((int)LIM / 2) + 1;
	pPrimos[1].limite = LIM;
	pPrimos[1].resultado = 0;
	htPrimos[1] = NULL;

#ifdef UNICODE

	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);

#endif

	_stprintf_s(strMainId, TAM, _TEXT("[Thread Main c/ ID: %d]\n"), GetCurrentThreadId());
	_tprintf(_TEXT("%s vou começar a trabalhar\n"), strMainId);

	_tprintf(_TEXT("%s vou lançar a thread de pares\n"), strMainId);

	htPares[0] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) ThreadPares, (LPVOID) &pPares[0], 0, &threadParesId[0]);
	htPares[1] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) ThreadPares, (LPVOID) &pPares[1], 0, &threadParesId[1]);
	htPrimos[0] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) ThreadPrimos, (LPVOID) &pPrimos[0], 0, &threadPrimosId[0]);
	htPrimos[1] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) ThreadPrimos, (LPVOID) &pPrimos[1], 0, &threadPrimosId[1]);

	if (htPares[0] == NULL || htPares[1] == NULL || htPrimos[0] == NULL || htPrimos[1] == NULL)
	{
		_tprintf(_TEXT("Erro a criar a thread\n"));
		return -1;
	}

	_tprintf(_TEXT("%s lancei a thread (%d) para calcular o somatório dos numeros pares\n"), strMainId, threadParesId[0]);
	_tprintf(_TEXT("%s lancei a thread (%d) para calcular o somatório dos numeros pares\n"), strMainId, threadParesId[1]);
	_tprintf(_TEXT("%s lancei a thread (%d) para calcular o somatório dos numeros pares\n"), strMainId, threadPrimosId[0]);
	_tprintf(_TEXT("%s lancei a thread (%d) para calcular o somatório dos numeros pares\n"), strMainId, threadPrimosId[1]);

	HANDLE ghEvents[4];

	ghEvents[0] = htPares[0];
	ghEvents[1] = htPares[1];
	ghEvents[2] = htPrimos[0];
	ghEvents[3] = htPrimos[1];

	WaitForMultipleObjects(4, ghEvents, TRUE, INFINITE);

	_tprintf(_TEXT("Resultado do somatorio dos pares: %d\n\n"), (pPares[0].resultado + pPares[1].resultado));
	_tprintf(_TEXT("Resultado do somatorio dos primos: %d\n\n"), (pPrimos[0].resultado + pPrimos[1].resultado));

	CloseHandle(htPares[0]);
	CloseHandle(htPares[1]);
	CloseHandle(htPrimos[0]);
	CloseHandle(htPrimos[1]);

	return 0;
}

DWORD WINAPI ThreadPares(LPVOID param)
{
	PARAM *p = (PARAM*)param;

	_tprintf(_TEXT("Sou a thread %d para calcular o somatorio dos numeros pares\n"), GetCurrentThreadId());

	for (int i = p->inicio; i <= p->limite; i++)
	{
		if (i % 2 == 0)
			p->resultado += i;

		if (i % 200 == 0)
		{
			Sleep(1000);
		}
	}

	_tprintf(_TEXT("Thread %d Terminei o meu trabalho. Resultado: %d\n\n"), GetCurrentThreadId(), p->resultado);

	ExitThread(0);
}

DWORD WINAPI ThreadPrimos(LPVOID param)
{
	PARAM *p = (PARAM*)param;
	int primo = 1;

	for (int i = p->inicio; i <= p->limite; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if ((i % j == 0) && (j > 1 && j < i))
			{
				primo = 0;
				break;
			}
		}

		if (primo == 1)
		{
			p->resultado += i;
		}
		else
			primo = 1;

		if (i % 15 == 0)
		{
			Sleep(1000);
		}
	}

	_tprintf(_TEXT("Thread %d Terminei o meu trabalho. Resultado: %d\n\n"), GetCurrentThreadId(), p->resultado);

	ExitThread(0);
}