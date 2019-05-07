#pragma once

#include "includes.h"
#include "Ball.h"

extern int exitthreadstatus;

extern int maxx, maxy, minx, miny;

HMODULE hDll;

TCHAR currentUsers[12];

DWORD WINAPI GetUsernameThreadLoop();
DWORD WINAPI BallControlThreadLoop(LPVOID param);

void initDllFuncs();

void SetHighScores();

void(*ClearUsernameString)();

TCHAR* (*getPlayerUsername)();

Ball newBall();