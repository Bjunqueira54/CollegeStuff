// TP_SO2_DLL.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Vars.h"

//eu não sei fazer esta merda
DWORD WINAPI LogIn(wchar_t *username)
{
	if (wcscmp(PlayerUsername, L""))
		PlayerUsername = username;
	else
		LogIn(username);
}