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
            
        case 10: //keyboard enter
            move(y, 4);
            return 0;
            break;
            
        case KEY_ENTER: //keypad enter
            move(y, 4);
            return 0;
            break;
            
        case 27: //keyboard escape
            move(y, 4);
            return 5;
            break;
            
        case KEY_BACKSPACE: //keyboard backspace
            if(x>4)
            {
                return 3;
            }
            return 1;
            break;
            
        case KEY_DC: //keyboard del
            if(x>4)
            {
                return 3;
            }
            return 1;
            break;
            
        default:
            if(c >= 32 && c <= 126)
            {
                if(x<48)
                    return c;
                else
                    return 1;
            }
            /*else
            {
                int newx, newy;
                getyx(stdscr, y, x);
                newx=x;
                newy=y;
                char whatis[25];
                sprintf(whatis, "%i", c);
                mvwaddstr(stdscr, 17, 2, whatis);
                move(newy, newx);
            }*/
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
            
        case 10:    //Keyboard Enter
            return 4;
            break;
            
        case KEY_ENTER: //Keypad Enter
            return 4;
            break;
            
        case 27:    //Escape
            return 2;
            break;
            
        default:
            return 0;
    }
}
