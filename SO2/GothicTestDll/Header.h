#pragma once

#ifdef GOTHICTESTDLL_EXPORTS
#define GOTHICTESTDLL_API __declspec(dllexport)
#else
#define GOTHICTESTDLL_API __declspec(dllimport)
#endif

extern "C" GOTHICTESTDLL_API void SayHello();

extern "C" GOTHICTESTDLL_API int GiveRandom();

extern "C" GOTHICTESTDLL_API void SayGoodBye();