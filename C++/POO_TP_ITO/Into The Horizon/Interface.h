#ifndef INTERFACE_H
#define INTERFACE_H

#include "headers.h"

#define MAX_X 120
#define MAX_Y 40

class Interface
{
    static vector <string> cmd;
    static vector <string> line;
    static vector <string> tutorial;
    
public:
    
    Interface(char lang);
    Interface(const Interface& orig);
    
    const char* getCmd(int i);
    const char* getLine(int i);
    static void tutPage();
    static void credPage();
    
    virtual ~Interface();
};

int getCenter(const char* a);
int getCenter(string a);
int getVertCenter(WINDOW *win, int n, int &r, int &flag);
void SetScreenSize(int lines, int columns);

#endif