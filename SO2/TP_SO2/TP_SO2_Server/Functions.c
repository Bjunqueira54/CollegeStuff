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

}