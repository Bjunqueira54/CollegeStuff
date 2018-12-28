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
    vector<string> log;
    vector<string> turncmd;
    
public:
    
    Interface(const Interface& orig);
    Interface(char lang);

    const char* getCmd(int i);
    const char* getLine(int i);
    string getInput(WINDOW *win, int lim);
    int getNumber(WINDOW *win, int lim);
    
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
    
    //Creates all the necessary ncurses windows needed for the game
    //to be played, like the map window or the command entering window.
    void drawGameArea();
    
    //Processes the string <c> to find if the command is valid with
    //commands given in the "cmd" vector. <exec> tells the parser
    //if you just wish to verify if <c> exists or if you wish to
    //execute it.
    //Note: Some commands will always execute regardless of
    //<exec>, for example, commands 1, 2 and 20 (in english that's
    //"exec", "next" and "exit" respectivelly).
    int parseCmd(string c, bool exec);
    
    //Reads through the <file>, extrating line-by-line and feeding
    //them to parseCmd() for verification. If a command is found
    //valid, it'll push them to the "turncmd" vector for
    //processing when the player moves to the next turn.
    int openExecFile(ifstream& file);
    
    //Calling this function will automatically draw the map window
    //with all the necessary game information, like ocean/harbor/land
    //tiles and any player/pirate ship floating in the water.
    //(Requires WINDOW *wmap to be created and functioning, or else 
    //a memory access violation (Segmentation Fault) will ensue)
    int drawMap();
    
    //Step-by-Step configuration file creating assistant.
    //The player has the freedom to create his own configuration
    //file or have the game create one for him.
    string createDefaultConfig();
    
    //Interactive on-screen map drawing. Let's the player create his
    //own game map within set dimensional limits.
    //Easier and more intuitive than to manually write '+'/'.'/'A-Za-z'
    //in a text file, where the risk of mismatched dimension is greater.
    vector<string> userDrawCustomMap();
    
    //Forces the player to pick a configuration file (or create 1 of his own)
    //before jumping into the game.
    //Warning: Do not let the player reach the game without first going through
    //this phase.
    int configPhase();
    
    //Prints multiple starts to the "wstats" window, like player name, money,
    //number of ships in his fleet, etc.
    void printStats();
};

#endif