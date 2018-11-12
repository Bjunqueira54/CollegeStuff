#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Language.h"

#define MAP_MAXY 40     //Merchants and Pirates Max Height
#define MAP_MAXX 120    //Merchants and Pirates Max Width

//Prototipos de funcoes

//Funcoes de desenho

void drawMainMenu(const Language lang);

void drawBox(WINDOW *win);

int getCenter(const char* a);

int getCenter(string a);

int getVertCenter(WINDOW *win, int n, int &rest, int &extraflag);

//Funcoes do Menu

void MainGameLoop(Language lang);

//Funcoes dos Comandos

void parseCmd(string cmd, const Language lang, WINDOW *win);


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

