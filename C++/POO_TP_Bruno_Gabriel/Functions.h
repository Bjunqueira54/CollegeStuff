#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Language.h"

//Protótipos de funções

void drawUI(int nL, int nC); //Do not use. Pending nCurses implementation

void drawMainMenu(const Language lang);

void parseCmd(string cmd, const Language lang);

int getCenter(const char* a);

int getCenter(string a);

void tutorial();

void credits();

#ifdef __linux__

static void setScreenSize(int lines, int columns)
{
    std::ostringstream syscmd;
    syscmd << "\e[8;" << lines << ";" << columns << "t";
    std::cout << syscmd.str();
}

#elif _WIN32

#include "Consola.h"

static void setScreenSize(int lines, int columns)
{
    Consola::setScreenSize(lines, columns);
}

#elif __unix__

#include "Consola.h"

static void setScreenSize(int lines, int columns)
{
    Consola::setScreenSize(lines, columns);
}
#endif

#endif /* FUNCTIONS_H */

