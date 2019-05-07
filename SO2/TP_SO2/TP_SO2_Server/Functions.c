#include "Server_Functions.h"


DWORD WINAPI GetUsernameThreadLoop()
{
	while (exitthreadstatus != 1)
	{
		if (_tcscmp(getPlayerUsername(), TEXT("")) == 0)
			continue;
		else
		{
			_tcscpy_s(currentUsers, sizeof(TCHAR) * 12, getPlayerUsername());
			ClearUsernameString();
			_tprintf(TEXT("New User connected: %s\n"), currentUsers);
		}
	}

	return 0;
}

void initDllFuncs()
{
	ClearUsernameString = (void(*)()) GetProcAddress(hDll, "ClearUsernameString");

	getPlayerUsername = (TCHAR* (*)()) GetProcAddress(hDll, "getPlayerUsername");
}

Ball newBall()
{
	Ball ball;

	ball.speed = 0;
	ball.x = 1;
	ball.y = 3;
	ball.ascending = 1;
	ball.right = 1;

	return ball;
}

DWORD WINAPI BallControlThreadLoop(LPVOID param)
{
	pBall ball  = (pBall) param;

	double nextHor = 0.01, nextVer = 0.01;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cConsole;

	while (exitthreadstatus != 1)
	{
		if (ball->x + nextHor >= maxx)
		{
			ball->right = 0;
			nextHor = -0.01;
		}
		else if(ball->x + nextHor <= minx)
		{
			ball->right = 1;
			nextHor = 0.01;
		}

		if (ball->y + nextVer >= maxy)
		{
			ball->ascending = 0;
			nextVer = -0.01;
		}
		else if (ball->y + nextVer <= miny)
		{
			ball->ascending = 1;
			nextVer = 0.01;
		}
		
		ball->x += nextHor;
		ball->y += nextVer;

		cConsole.X = 40;
		cConsole.Y = 5;
		SetConsoleCursorPosition(hConsole, cConsole);
		_tprintf(TEXT("Ball X: %f"), ball->x);
		cConsole.X = 40;
		cConsole.Y = 6;
		SetConsoleCursorPosition(hConsole, cConsole);
		_tprintf(TEXT("Ball Y: %f"), ball->y);

		Sleep(10);
	}

	return 0;
}

void SetHighScores()
{

#define TAM 200
	
		HKEY chave;
		DWORD queAconteceu, tamanho, flag, scoree;
		TCHAR str[TAM], user[TAM], score[TAM];
		LONG result, i;
#ifdef UNICODE
		_setmode(_fileno(stdin), _O_WTEXT);
		_setmode(_fileno(stdout), _O_WTEXT);
		_setmode(_fileno(stderr), _O_WTEXT);
#endif
		//Criar/abrir uma chave em HKEY_CURRENT_USER\Software\TPS02

		if (RegCreateKeyEx(HKEY_CURRENT_USER, TEXT("Software\\TPSO2"), 0, NULL,
			REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &chave, &queAconteceu) !=
			ERROR_SUCCESS) {
			_tprintf(TEXT("Erro ao criar/abrir chave (%d)\n"), GetLastError());
			return -1;
		}
		else {
			//Se a chave foi criada, inicializar os valores
			if (queAconteceu == REG_CREATED_NEW_KEY) {
				_tprintf(TEXT("Chave: HKEY_CURRENT_USER\\Software\\Software\\TPSO2 criada\n"));
				//Criar valor "Username" = "nome"
				scoree = 123;
				RegSetValueEx(chave, TEXT("Top 10"), 0, REG_SZ, (LPBYTE)TEXT("cassandra %d"),
					_tcslen(10) * sizeof(TCHAR), scoree);
				//Criar valor "score" = x;
				//RegSetValueEx(chave, TEXT("Score"), 0, REG_DWORD, (LPBYTE)&score, sizeof(DWORD));


				_tprintf(TEXT("Valores nome e score guardados\n"));
			}
			//Se a chave foi aberta, ler os valores lá guardados
			else if (queAconteceu == REG_OPENED_EXISTING_KEY) {
				_tprintf(TEXT("Chave: HKEY_CURRENT_USER\\Software\\Software\\TPSO2\n"));
				tamanho = 20;
				RegQueryValueEx(chave, TEXT("Username"), NULL, NULL, (LPBYTE)user,
					&tamanho);
				user[tamanho / sizeof(TCHAR)] = '\0';
				tamanho = sizeof(score);
				RegQueryValueEx(chave, TEXT("Score"), NULL, NULL, (LPBYTE)&score,
					&tamanho);
				_stprintf_s(str, TAM, TEXT("\n User:%s \n Score:%d\n"), user, score);
				_tprintf(TEXT("Lido do Registry:%s\n\n"), str);
			}
			RegCloseKey(chave);
		}

		/*
			_tprintf(TEXT("quer apagar a key? (1=s,0=n ) "));
			_tscanf_s(&flag);
			if (flag == 1 ) {
				result = RegDeleteKey(chave,0);
				if (result == ERROR_SUCCESS)
					_tprintf(TEXT("apaguei"));
					return TRUE;
				return FALSE;}
			else
				_tprintf(TEXT("nao apaguei"));
			*/


		_gettchar(); //pra nao fechar logo


		
	

}