#include "Interface.h"

Interface::Interface()
{
    initscr();
    start_color();
    noecho();
    curs_set(0);
    
    mvwaddstr(stdscr, 0, 5, "Welcome to Monster Slayer");
    refresh();
}

void Interface::DrawMainMenu()
{
    clear();
    mvwaddstr(stdscr, 5, 10, "1 - Start Game");
    mvwaddstr(stdscr, 5, 20, "2 - Exit Game");
}

Interface::~Interface()
{
    endwin();
}