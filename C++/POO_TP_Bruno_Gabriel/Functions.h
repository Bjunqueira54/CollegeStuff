#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Language.h"

//Prototipos de funcoes

//Funcoes de desenho

void drawMainMenu(const Language lang);

int getCenter(const char* a);

int getCenter(string a);

//Funcoes do Menu

void MainGameLoop(Language lang);

void tutorial();

void credits();

//Funcoes dos Comandos

void parseCmd(string cmd, const Language lang);


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

