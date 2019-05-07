#include "stdafx.h"
#include "includes.h"

void LogIn(TCHAR *username)
{
	do {}
	while (_tcscmp(PlayerUsername, TEXT("")) != 0);	//Just waiting for the server to clear the string

	if (_tcscmp(PlayerUsername, TEXT("") ) == 0)
	{
		for (int i = 0; i < _tcslen(username) || i < UNLEN; i++)
		{
			PlayerUsername[i] = username[i];
		}
	}
}

void ClearUsernameString()
{
	_tcscpy_s(PlayerUsername, UNLEN, TEXT(""));
}

TCHAR *getPlayerUsername()
{
	return PlayerUsername;
}