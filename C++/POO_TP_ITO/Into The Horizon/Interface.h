#ifndef INTERFACE_H
#define INTERFACE_H

#include "headers.h"
#include "Game.h"

#define MAX_X 120
#define MAX_Y 40

#define GAME_VERSION_MAJOR 1
#define GAME_VERSION_MINOR 3

#define TERM_DEFAULT 11
#define OCEAN_STORM 12
#define OCEAN_CALM 13
#define LAND_DARK 14
#define LAND_LIGHT 15
#define FRIENDLY 16
#define UNFRIENDLY 17

class Interface
{
    //Consider static?
    WINDOW *wcmd, *wmap, *wlog, *wstats;
    
    static vector <string> cmd;
    static vector <string> line;
    static vector <string> tutorial;
    Game* game;
    
public:
    
    Interface(const Interface& orig);
    Interface(char lang);

    const char* getCmd(int i);
    const char* getLine(int i);
    string getInput(WINDOW *win, int lim);
    int getNumber(WINDOW *win);
    
    void tutPage();
    void credPage();
    void startgame();
    void MainGameLoop();
    void endgame();
    
    //Writes and centers all needed menu strings to stdscr and
    //draws a neat box for it.
    void drawMainMenu();
    
    //Recieves a const char* string and tries to horizontally
    //center it on the given screen.
    static int getCenter(const char* a);
    static int getCenter(string a);
    
    //Sets *r to whatever value is required to correctly center
    //and space out n menus items in window *win. Returns 0 if no 
    //more modifications are needed outside of this function, else
    //you need to check if &extraflag is 0 or 1. If it's 0, you can
    //add whatever is returned from this function to the extremes
    //of your menus; if it's 1, it means there's no possible way to
    //have consistent spacing with in your menu and you'll have to
    //add that 1 extra space wherever.
    static int getVertCenter(WINDOW *win, int n, int &r, int &flag);
    
    //Clears the given window, prints a neat box
    //around it's edge and refreshes the window.
    //Works as a clear screen
    static void drawBox(WINDOW *win);
    
    static void SetScreenSize(int lines, int columns);
    
    virtual ~Interface();
    
private:
    
    void drawGameArea();
    int parseCmd(string c);
    void openExecFile(string filename);
    int drawMap();
    void createDefaultConfig();
    vector<string> userDrawCustomMap();
};

#endif