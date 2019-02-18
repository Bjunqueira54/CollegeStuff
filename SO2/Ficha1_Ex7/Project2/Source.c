#include <windows.h>
#include <tchar.h>
#include <io.h>
#include <fcntl.h>
#include <stdio.h>

#define TAM 200

int _tmain(int argc, TCHAR *argv[])
{
	HKEY chave;
	DWORD queAconteceu, versao, tamanho;
	TCHAR str[TAM], autor[TAM];

#ifdef UNICODE 
	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);
	_setmode(_fileno(stderr), _O_WTEXT);
#endif

	//Criar/abrir uma chave em HKEY_CURRENT_USER\Software\MinhaAplicacao
	if (RegCreateKeyEx(HKEY_LOCAL_MACHINE, TEXT("Software\\MinhaAplica��o"), 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &chave, &queAconteceu) != ERROR_SUCCESS)
	{
		_tprintf(TEXT("Erro ao criar/abrir chave (%d)\n"), GetLastError());
		return -1;
	}
	else
	{
		//Se a chave foi criada, inicializar os valores
		if (queAconteceu == REG_CREATED_NEW_KEY)
		{
			_tprintf(TEXT("Chave: HKEY_LOCAL_MACHINE\\Software\\MinhaAplica��o criada\n"));
			//Criar valor "Autor" = "Meu nome"
			RegSetValueEx(chave, TEXT("Autor"), 0, REG_SZ, (LPBYTE)TEXT("Meu Nome"), _tcslen(TEXT("Meu Nome")) * sizeof(TCHAR));
			//Criar valor "Versao" = 1 
			versao = 1;
			RegSetValueEx(chave, TEXT("Versao"), 0, REG_DWORD, (LPBYTE)&versao, sizeof(DWORD));
			_tprintf(TEXT("Valores Autor e Vers�o guardados\n"));
		}

		//Se a chave foi aberta, ler os valores l� guardados
		else if (queAconteceu == REG_OPENED_EXISTING_KEY)
		{
			_tprintf(TEXT("Chave: HKEY_LOCAL_MACHINE\\Software\\MinhaAplicacao aberta\n"));
			tamanho = 20;
			RegQueryValueEx(chave, TEXT("Autor"), NULL, NULL, (LPBYTE)autor, &tamanho);
			autor[tamanho / sizeof(TCHAR)] = '\0';
			tamanho = sizeof(versao);
			RegQueryValueEx(chave, TEXT("Versao"), NULL, NULL, (LPBYTE)&versao, &tamanho);
			versao++;
			RegSetValueEx(chave, TEXT("Versao"), 0, REG_DWORD, (LPBYTE)&versao, sizeof(DWORD));
			_stprintf_s(str, TAM, TEXT("Autor:%s \nVers�o:%d\n"), autor, versao);
			_tprintf(TEXT("Lido do Registry:%s\n"), str);
		}
		RegCloseKey(chave);
	}
	_gettchar();
	return 0;
}