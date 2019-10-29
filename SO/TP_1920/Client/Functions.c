#include "Functions.h"

#define COR0 0
#define COR1 1
#define COR2 2

WINDOW* notification = NULL;

void createNotificationWin()
{
    notification = subwin(stdscr, 5, 15, getmaxy(stdscr) - 5, getmaxx(stdscr) - 15);
    wclear(notification);
    wrefresh(notification);
}

void drawBox()
{
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
}

void ClearTestPopUp()
{
    wclear(notification);
    delwin(notification);
    wrefresh(stdscr);
}

void setWindowColor(int c)
{
    init_pair(COR0, COLOR_WHITE, COLOR_BLACK);
    init_pair(COR1, COLOR_WHITE, COLOR_RED);
    init_pair(COR2, COLOR_WHITE, COLOR_YELLOW);
    
    if(c == 0)
        wattron(notification, COLOR_PAIR(COR0));
    else if((c % 2) == 0)
        wattron(notification, COLOR_PAIR(COR2));
    else
        wattron(notification, COLOR_PAIR(COR1));
}

void newNotification(const char* notice_str)
{
    createNotificationWin();
    
    int rep = 1;
    
    while(rep < 5)
    {
        setWindowColor(rep);
        drawBox();
        mvwaddstr(notification, 1, 1, "New Message!");
        mvwaddstr(notification, 2, 1, "Topic:");
        mvwaddstr(notification, 3, 1, notice_str);
        wrefresh(notification);
        usleep(250*1000);
        rep++;
    }
    
    ClearTestPopUp();
}