#include <windows.h>
#include <tchar.h>
#include <io.h>
#include <fcntl.h>
#include <stdio.h>

#define MAX 256

#define FILE_PATH TEXT("FicheiroPartilhado.txt")

int _tmain(int argc, LPTSTR argv[])
{
	HANDLE hMutex, hEvento, hFicheiro;
	TCHAR frase[MAX];
	DWORD n, res;

	hFicheiro = CreateFile(FILE_PATH, GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	hMutex = CreateMutex(NULL, FALSE, TEXT("MeuMutex"));

	hEvento = CreateEvent(NULL, TRUE, FALSE, TEXT("MeuEvento"));

	if (hFicheiro == NULL || hMutex == NULL || hEvento == NULL)
	{
		_tprintf(TEXT("Erro a criar recursos de comunicação e/ou sincronização.\n"));
		return -1;
	}

#ifdef UNICODE
	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);
#endif

	_tprintf(TEXT("[Processo Produtor %d] Vou começar a trabalhar...\n Prima \'fim\' para terminar...\n"), GetCurrentProcessId());

	do
	{
		_fgetts(frase, MAX, stdin);
		fflush(stdin);

		WaitForSingleObject(hMutex, INFINITE);

		res = WriteFile(hFicheiro, frase, (_tcslen(frase) + 1) * sizeof(TCHAR), &n, NULL);

		SetEvent(hEvento);

		ReleaseMutex(hMutex);

		ResetEvent(hEvento);
	} while (_tcsncmp(frase, TEXT("fim"), 3) && n > 0 && res != 0);

	_tprintf(TEXT("[Processo Produtor %d] Finalmente vou terminar..."), GetCurrentProcessId());

	CloseHandle(hMutex);
	CloseHandle(hEvento);
	CloseHandle(hFicheiro);

	return 0;
}