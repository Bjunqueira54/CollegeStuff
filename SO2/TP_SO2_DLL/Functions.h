#pragma once

#include "stdafx.h"

#ifdef TPSO2DLL_EXPORTS
#define TPSO2DLL_API __declspec(dllexport);
#else
#define TPSO2DLL_API __declspec(dllimport);
#endif

#define MAX 256

TPSO2DLL_API void LogIn();

extern TPSO2DLL_API TCHAR PlayerUsername[MAX];