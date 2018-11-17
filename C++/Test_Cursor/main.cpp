#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <ncurses.h>
#include <curses.h>

using namespace std;

int main(int argc, char** argv)
{
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    
    int opt;
    int y=0, x=0, maxy, maxx;
    int value;
    
    getmaxyx(stdscr, maxy, maxx);
    maxy--;
    maxx--;
    
    move(y,x);
    refresh();
    
    /*while(1)
    {
        ostringstream con;
        int value;
        
        opt = getch();
        
        value = opt;
        con << value;
        mvwaddstr(stdscr, 1, 1, con.str().c_str());
        refresh();
        clear();
    }*/
    
    do
    {
        opt = getch();
        
        switch(opt)
        {
            case KEY_UP:
                if(y>0)
                    y--;
                else if(y==0)
                    y=maxy;
                break;
            case KEY_DOWN:
                if(y<maxy)
                    y++;
                else if(y==maxy)
                    y=0;
                break;
            case KEY_RIGHT:
                if(x<maxx)
                    x++;
                else if(x==maxx)
                    x=0;
                break;
            case KEY_LEFT:
                if(x>0)
                    x--;
                else if(x==0)
                    x=maxx;
                break;
            default:    //do nothing
                break;
        }
        
        move(y,x);
        refresh();
    }
    while(opt != 10);
    
    endwin();
    
    return 0;
}

