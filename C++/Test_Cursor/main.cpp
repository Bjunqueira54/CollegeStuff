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
    noecho();
    
    char opt;
    int y=0, x=0, maxy, maxx;
    
    getmaxyx(stdscr, maxy, maxx);
    maxy--;
    maxx--;
    
    move(y,x);
    refresh();
    
    do
    {
        opt = getch();
        
        switch(opt)
        {
            case 65:
                if(y>0)
                    y--;
                else if(y==0)
                    y=maxy;
                break;
            case 66:
                if(y<maxy)
                    y++;
                else if(y==maxy)
                    y=0;
                break;
            case 67:
                if(x<maxx)
                    x++;
                else if(x==maxx)
                    x=0;
                break;
            case 68:
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

