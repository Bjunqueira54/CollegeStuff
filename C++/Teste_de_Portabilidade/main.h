#ifndef MAIN_H
#define MAIN_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>

#ifdef _WIN32

#include <windows.h>

    static HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
    static HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    static HWND hwnd = GetConsoleWindow();

    static void setScreenSize(int lines, int columns)
    {
        COORD tam;
        SMALL_RECT DisplayArea;
        
        tam.X = columns;
        tam.Y = lines;
        
        SetConsoleScreenBufferSize(hconsole, tam);
        
        DisplayArea.Top = 0;
	DisplayArea.Left = 0;
	DisplayArea.Bottom = lines - 1;
	DisplayArea.Right = columns - 1;
	SetConsoleWindowInfo(hconsole, TRUE, &DisplayArea);
    }


#elif __linux__

static void setScreenSize(int lines, int columns)
{
    std::ostringstream syscmd;
    syscmd << "\e[8;" << lines << ";" << columns << "t";
    std::cout << syscmd.str();
}

#elif __unix__

static void setScreenSize(int lines, int columns)
{
    
}

#endif


#endif /* MAIN_H */

