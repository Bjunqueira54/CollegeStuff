#include "headers.h"
#include "Functions.h"

using namespace std;

//Draws a neat screen wide box for the main menu.
//Don't forget to give it the a Language object
//or else nothing will show up
void drawMainMenu(const Language lang)
{
    clear();
    for(int y = 0; y<getmaxy(stdscr); y++)
    {
        for(int x=0; x<getmaxx(stdscr); x++)
        {
            if(y==0 || y==(getmaxy(stdscr) - 1))
                mvwaddch(stdscr, y, x, '*');
            else
            {
                if(x==0 || x==(getmaxx(stdscr) - 1))
                    mvwaddch(stdscr, y, x, '*');
                else
                    mvwaddch(stdscr, y, x, ' ');
            }
        }
    }
    mvwaddstr(stdscr, 5, getCenter(lang.getLine(2)), lang.getLine(2));
    mvwaddstr(stdscr, 5, getCenter(lang.getLine(3)), lang.getLine(3));
    mvwaddstr(stdscr, 5, getCenter(lang.getLine(4)), lang.getLine(4));
    mvwaddstr(stdscr, 5, getCenter(lang.getLine(5)), lang.getLine(5));
    refresh();
}

void drawMap(const Language lang)
{
    move(0,0);
}

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

int getCenter(const char* a)
{
    int x;
    
    if(a == "")
        return 0;
    
    string str(a);
    
    x = (getmaxx(stdscr)-strlen(str.c_str()))/2;
    
    return x;
}

int getCenter(string a)
{
    int x;
    
    x = (getmaxx(stdscr) - strlen(a.c_str()))/2;
    
    return x;
}

int getVertCenter(WINDOW *win, int n, int *esp)
{
    int y, r;
    
    y = getmaxy(win);
    
    *esp = (y-(n+2))/(n+1); //rounds down
    
    r = (y-(n+2))%(n+1);
    
    if(r%2 == 0)
    {}
    else
    {}
    
    return r;
}

void tutorial()
{
    clear();
    mvwaddstr(stdscr, 1, 1, "Tutorial");
    refresh();
    getch();
}

void credits()
{
    clear();
    mvwaddstr(stdscr, 1, 1, "Credits");
    refresh();
    getch();
}