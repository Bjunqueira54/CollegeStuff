#include "Interface.h"

Interface::Interface()
{
    initscr();
    start_color();
    noecho();
    curs_set(0);
    
    mvwaddstr(stdscr, 0, 5, "Welcome to Monster Slayer");
}

Interface::~Interface()
{
    
}