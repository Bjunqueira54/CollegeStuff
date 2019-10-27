#include "Functions.h"

void TestPopUpNotification()
{
    notification = subwin(stdscr, 5, 15, 0, 0);
    
    wclear(notification);
    int y, x;
    
    getmaxyx(notification, y, x);
    
    for(int i=0; i<y; i++)
    {
        mvwaddch(notification, i, 0, '|');
        mvwaddch(notification, i, x-1, '|');
    }
    for(int i=0; i<x; i++)
    {
        mvwaddch(notification, 0, i, '=');
        mvwaddch(notification, y-1, i, '=');
    }
    
    mvwaddch(notification, 0, 0, 'x');
    mvwaddch(notification, 0, x-1, 'x');
    mvwaddch(notification, y-1, 0, 'x');
    mvwaddch(notification, y-1, x-1, 'x');
    
    mvwaddstr(notification, 1, 1, "I'm a");
    mvwaddstr(notification, 2, 1, "notification");

    wrefresh(notification);
}

void ClearTestPopUp()
{
    wclear(notification);
    wrefresh(notification);
}