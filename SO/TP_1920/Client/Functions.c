#include "Functions.h"

WINDOW* notification;

void createNotificationWin()
{
    notification = subwin(stdscr, 5, 15, getmaxy(stdscr) - 5, getmaxx(stdscr) - 15);
    wclear(notification);
    
    int y, x;
    
    getmaxyx(notification, y, x);
    
    for(int i=0; i<y; i++)
    {
        mvwaddch(notification, i, 0, '*');
        mvwaddch(notification, i, x-1, '*');
    }
    for(int i=0; i<x; i++)
    {
        mvwaddch(notification, 0, i, '*');
        mvwaddch(notification, y-1, i, '*');
    }
    
    wrefresh(notification);
}

void ClearTestPopUp()
{
    wclear(notification);
    delwin(notification);
    wrefresh(stdscr);
}

void setWindowColour1();
void setWindowColour2();

void newNotification(const char* notice_str)
{
    createNotificationWin();
    
    /*int rep = 0;
    
    while(rep < 4)
    {
        
        mvwaddstr(notification, 1, 1, "New Message!");
        mvwaddstr(notification, 2, 1, "Topic:");
        mvwaddstr(notification, 3, 1, notice_str);
        wrefresh(notification);
        usleep(250*1000);
        rep++;
    }*/
    
    mvwaddstr(notification, 1, 1, "New Message!");
    mvwaddstr(notification, 2, 1, "Topic:");
    mvwaddstr(notification, 3, 1, notice_str);
    wrefresh(notification);
}