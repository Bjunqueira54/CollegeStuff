#include "client.h"

int edModeLoop()
{
    int c, x, y;
    getyx(stdscr, y, x);
    c = getch();
    
    switch(c)
    {
        case KEY_RIGHT:
            if(x<48)
            {
                x++;
                move(y,x);
            }
            return 1;
            
        case KEY_LEFT:
            if(x>4)
            {
                x--;
                move(y,x);
            }
            return 1;
            
        case 10:
            move(y, 4);
            return 0;
            break;
            
        case KEY_ENTER:
            move(y, 4);
            return 0;
            break;
            
        case 27:
            return 2;
            break;
            
        case 8:
            break;
            
        default:
            if(c >= 32 && c <= 126)
            {
                return c;
            }
            return 1;
            
    }
}

int mvModeLoop()
{
    int c, x, y;
    getyx(stdscr, y, x);
    c = getch();
    
    switch(c)
    {
        case KEY_UP:
            if(y>0)
            {
                y--;
                move(y,x);
            }
            return 0;
            
        case KEY_DOWN:
            if(y<14)
            {
                y++;
                move(y,x);
            }
            return 0;
            
        case 10:
            return 1;
            break;
            
        case KEY_ENTER:
            return 1;
            break;
            
        case 27:
            return 2;
            break;
            
        default:
            return 0;
    }
}