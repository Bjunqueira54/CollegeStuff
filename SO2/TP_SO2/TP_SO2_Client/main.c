#include "includes.h"

int _tmain(int argc, LPTSTR argv[])
{
	_tprintf(TEXT("Hello I'm the Client\n"));

	_gettch();

	HMODULE hDll = LoadLibraryEx("../Debug/TP_SO2_DLL.dll", NULL, NULL);

	if (hDll == NULL)
		return -1;

	void(*login)(TCHAR*) =(void (*)) GetProcAddress(hDll, "LogIn");

	if (login == NULL)
	{
		FreeLibrary(hDll);
		return -1;
	}

	_tprintf(TEXT("What's your username(12 characters): "));
	TCHAR username[12];
	fflush(stdin);
	_fgetts(username, 12, stdin);

	login(username);

	_gettch();

	FreeLibrary(hDll);
	
	return 0;
}