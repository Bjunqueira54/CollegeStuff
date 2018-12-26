#ifndef INTERFACE_H
#define INTERFACE_H

#include "headers.h"

#define MAX_X 120
#define MAX_Y 40

#define GAME_VERSION_MAJOR 1
#define GAME_VERSION_MINOR 1

class Interface
{
    static vector <string> cmd;
    static vector <string> line;
    static vector <string> tutorial;
    
public:
    
    Interface(const Interface& orig);
    Interface(char lang);
    
    static void drawBox(WINDOW *win);
    static void drawMainMenu();
    
    const char* getCmd(int i);
    const char* getLine(int i);
    
    static void tutPage();
    static void credPage();
    
    static int getCenter(const char* a);
    static int getCenter(string a);
    static int getVertCenter(WINDOW *win, int n, int &r, int &flag);
    
    static void SetScreenSize(int lines, int columns);
    
    virtual ~Interface();
};

#endif