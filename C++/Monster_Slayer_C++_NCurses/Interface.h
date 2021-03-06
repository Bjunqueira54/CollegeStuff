#ifndef INTERFACE_H
#define INTERFACE_H

#include "includes.h"

class Interface
{
#define TERM_COLOR_DEFAULT 1
#define SKY_COLOR 2
#define GROUND_COLOR 3
#define RENDER_CHAR_DEFAULT 4
    
    WINDOW* mainwin;
    
public:
    
    Interface();
    Interface(const Interface& orig) = delete;
    
    //Draws the main menu for the game.
    //Note: for in-game combat options, use DrawCombatMenu()
    void DrawMainMenu();
    
    //Draws the in-game Combat Options Menu
    //Note: use DrawMainMenu() for out-of-game main menu
    void DrawCombatMenu();
    
    //Gets a character from the user and returns the
    //ASCII int value for it
    int getOpt();
    
    //Gets the name for the player while also printing in on screen
    string getName(WINDOW* win);
    
    virtual ~Interface();
    
private:

    void SetScreenSize(int Lines, int Columns);
    void DrawBorder(WINDOW* win);
    
    void DrawScene(WINDOW* win);
    void ColorInitializer();
    short COLOR_CONVERTER(int n) { return (n * (1000/255)); }
};

#endif