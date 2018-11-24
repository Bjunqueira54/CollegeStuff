#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "headers.h"
#include "Language.h"
#include "Settings.h"

#define GAME_VERSION_MAJOR "0"
#define GAME_VERSION_MINOR "17"

#define MAP_MAXY 40     //Merchants and Pirates Max Height
#define MAP_MAXX 120    //Merchants and Pirates Max Width

#define DEFAULT_CONFIG "config.ini"

extern WINDOW *wmap, *wcmd, *wlog;
extern int phase;

extern Language lang;
extern Settings *settings;

///Prototipos de funcoes

///////////////////////
///Drawing Functions///
///////////////////////

//Writes and centers all needed menu strings to stdscr and
//draws a neat box for it.
void drawMainMenu();

//Draws and colors the map to wmap
//(don't send any other WINDOW* to this function).
void drawMap();

//Sends the user into map drawing mode
vector <string> userDrawCustomMap();   //This won't be the final version prototype, it's just here as a reminder of wtf am I doing with my life

//Clears the given window, prints a neat box
//around it's edge and refreshes the window.
//Works as a clear screen
void drawBox(WINDOW *win);


//Recieves a const char* string and tries to horizontally
//center it on the given screen.
int getCenter(const char* a);
int getCenter(string a);

//Sets *esp to whatever value is required to correctly center
//and space out n menus items in window *win. Returns 0 if no 
//more modifications are needed outside of this function, else
//you need to check if &extraflag is 0 or 1. If it's 0, you can
//add whatever is returned from this function to the extremes
//of your menus; if it's 1, it means there's no possible way to
//have consistent spacing with in your menu and you'll have to
//add that 1 extra space wherever.
int getVertCenter(WINDOW *win, int n, int &rest, int &extraflag);

////////////////////
///Menu Functions///
////////////////////

void MainGameLoop();

///////////////////////
///Command Functions///
///////////////////////

//Recieves a string with spaces and the full command
//to be separated into single words for command processing.
int parseCmd(string cmd);
void createDefaultConfig(char opt);
string getInput(WINDOW *win, int str_size);
string getNumInput(WINDOW *win, int str_size);

/////////////////////
///My Special Baby///
/////////////////////

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