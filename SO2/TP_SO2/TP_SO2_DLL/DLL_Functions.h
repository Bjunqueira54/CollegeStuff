#pragma once
#include "includes.h"

#define UNLEN 12

#ifdef __cplusplus
extern "C"
{
#endif

	extern __declspec(dllexport) TCHAR PlayerUsername[UNLEN] = TEXT("");

	__declspec(dllexport) void LogIn(TCHAR *username);

	__declspec(dllexport) void ClearUsernameString();

	__declspec(dllexport) TCHAR *getPlayerUsername();

#ifdef __cplusplus
}
#endif