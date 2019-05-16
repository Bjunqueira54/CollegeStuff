#include "includes.h"
#include "Server_Functions.h"
#include "Ball.h"

int exitthreadstatus = 0;
int maxx = 20;
int maxy = 10;
int minx = 0;
int miny = 0;

int _tmain(int argc, LPTSTR *argv[])
{
	_tprintf(TEXT("Hello I'm the Server\n"));

	_gettch();

	_tprintf(TEXT("Phase 2\n"));

	_tcscpy_s(currentUsers, sizeof(TCHAR) * 12, TEXT(""));

	hDll = LoadLibraryEx("../Debug/TP_SO2_DLL.dll", NULL, NULL);

	if (!hDll)
		return -1;

	initDllFuncs();

	HANDLE hUsername1 = CreateThread(NULL, NULL, GetUsernameThreadLoop, NULL, NULL, NULL);

	Ball ball;
	ball.speed = 0;
	ball.x = 1;
	ball.y = 3;
	ball.ascending = 1;
	ball.right = 1;

	HANDLE hBall = CreateThread(NULL, NULL, BallControlThreadLoop, (LPVOID) &ball, NULL, NULL);

	fflush(stdin);
	_gettch();

	exitthreadstatus = 1;

	SetHighScores();

	return 0;
}