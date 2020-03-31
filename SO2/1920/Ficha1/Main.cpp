//� o exercicio 4, mas o Ex1 a 3 � igual a este, excepto que este est� em C++. O Ex1 � C b�sico "Ol� Mundo". O Ex2 � C B�sico. O Ex3 � C WinAPI.

#include <Windows.h>
#include <tchar.h>
#include <fcntl.h>
#include <io.h>
#include <iostream>
#include <string>

using namespace std;

#ifdef UNICODE
#define tcout wcout
#define tcin wcin
#define tstring wstring
#else
#define tcout cout
#define tcin cin
#define tstring string
#endif 

int _tmain(int argc, LPSTR argv[])
{
	tstring str = TEXT("Ol�! Este programa � para aceitar UNICODE. Insira \'fim\' para sair\n");

	unsigned int i;

#ifdef UNICODE

	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);

#endif

	tcout << str;

	do
	{
		getline(tcin, str);

		for (i = 0; i < str.length(); i++)
			str[i] = _totupper(str[i]);

		tcout << TEXT("Frase: ") << str << TEXT(" Tamanho: ") << str.length() << endl;
	}
	while(str != TEXT("FIM"));

	return 0;
}