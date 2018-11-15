#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Language.h"

#define MAP_MAXY 40     //Merchants and Pirates Max Height
#define MAP_MAXX 120    //Merchants and Pirates Max Width

#define COLOR_DBROWN 8 //Ncurses' colors range from 0-7, so this has to be 8
#define COLOR_LBROWN 9

WINDOW *wmap, *wcmd, *wlog;

///////////////////////////
///Prototipos de funcoes///
///////////////////////////

//Funcoes de desenho

//Writes and centers all needed menu strings to stdscr.
void drawMainMenu(const Language lang);

//Draws and colors the map to wmap
//(don't send any other WINDOW* to this function).
void drawMap();

//Clears the given window, prints a neat box
//around it's edge and refreshes the window.
void drawBox(WINDOW *win);

int getCenter(const char* a);

int getCenter(string a);

int getVertCenter(WINDOW *win, int n, int &rest, int &extraflag);

/////////////////////
///Funcoes do Menu///
/////////////////////

void MainGameLoop(Language lang);

//////////////////////////
///Funcoes dos Comandos///
//////////////////////////

bool parseCmd(string cmd, const Language lang, WINDOW *win, int &phase);
void createDefaultConfig(char opt);


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

#endif