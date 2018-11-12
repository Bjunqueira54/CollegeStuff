#include "headers.h"
#include "Functions.h"

using namespace std;

//Draws a neat screen wide box for the main menu.
//Don't forget to give it the a Language object
//or else nothing will show up
void drawMainMenu(const Language lang)
{   
    int y=0, esp, r, extra;
    esp = getVertCenter(stdscr, 4, r, extra);
    
    y+=(esp+r);
    mvwaddstr(stdscr, y, 5, lang.getLine(2));
    y+=esp;
    mvwaddstr(stdscr, y, 5, lang.getLine(3));
    y+=esp;
    mvwaddstr(stdscr, y, 5, lang.getLine(4));
    y+=esp;
    mvwaddstr(stdscr, y, 5, lang.getLine(5));
    refresh();
}

void drawMap(const Language lang)
{
    move(0,0);
}

//Recieves a string with spaces and the full command
//to be separated into single words for command processing.
//Also recieves a Language class object to check the parsed
//commands against.
void parseCmd(string cmd, const Language lang)
{
    string parse;
    istringstream is;
    
    is.str(cmd);
    
    while(is >> parse)
    {
        for(int i=0; i<lang.getCmdvec().size(); i++)
        {
            if(parse.compare(lang.getCmd(i)) == 0)
            {
                mvwaddstr(stdscr, 4, 0, lang.getLine(14));
                return;
            }
        }
        
        mvwaddstr(stdscr, 4, 0, "Command doesn't Exist");
        return;
    }
}

//Recieves a const char* string and tries to horizontally
//center it on the given screen. TO-DO: Change all current
//getCenter function calls to (WINDOW *win, const char*(OR)string a)
int getCenter(const char* a)
{
    int x;
    
    if(strcmp(a,"") == 0)
        return 0;
    
    string str(a);
    
    x = (getmaxx(stdscr)-strlen(str.c_str()))/2;
    
    return x;
}

//Recieves a string object and tries to horizontally
//center it on the given screen. TO-DO: Change all current
//getCenter function calls to (WINDOW *win, const char*(OR)string a)
int getCenter(string a)
{
    int x;
    
    x = (getmaxx(stdscr) - strlen(a.c_str()))/2;
    
    return x;
}

//Sets *esp to whatever value is required to correctly center
//and space out n menus items in window *win. Returns 0 if no 
//more modifications are needed outside of this function, else
//you need to check if &extraflag is 0 or 1. If it's 0, you can
//add whatever is returned from this function to the extremes
//of your menus; if it's 1, it means there's no possible way to
//have consistent spacing with in your menu and you'll have to
//add that 1 extra space wherever.
int getVertCenter(WINDOW *win, int n, int &r, int &extraflag)
{
    int y, esp;
    
    y = getmaxy(win);
    
    esp = (y-(n+2))/(n+1); //rounds down
    
    r = (y-(n+2))%(n+1);
    
    if(r != 0)
    {
        r=r/2;
        if(r%2 == 0)
        {
            extraflag = 0;
            return esp;
        }
        else
        {
            extraflag = 1;
            return esp;
        }
    }
    else
    {
        extraflag = 0;
        return esp;
    }
}

void drawBox(WINDOW *win)
{
    wclear(win);
    int y, x;
    
    getmaxyx(win, y, x);
    
    for(int i=1; i<y; i++)
    {
        mvwaddch(win, i, 0, '|');
        mvwaddch(win, i, x-1, '|');
    }
    for(int i=1; i<x; i++)
    {
        mvwaddch(win, 0, i, '-');
        mvwaddch(win, y-1, i, '-');
    }
    
    mvwaddch(win, 0, 0, '*');
    mvwaddch(win, 0, x-1, '*');
    mvwaddch(win, y-1, 0, '*');
    mvwaddch(win, y-1, x-1, '*');
    
    wrefresh(win);
}