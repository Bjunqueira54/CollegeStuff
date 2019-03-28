#include "Interface.h"

Interface::Interface()
{
    SetScreenSize(35, 150);
    initscr();
    resizeterm(35, 150);
    start_color();
    noecho();
    curs_set(0);
    
    mvwaddstr(stdscr, 0, 5, "Welcome to Monster Slayer");
    refresh();
}

void Interface::DrawMainMenu()
{
    DrawScene(stdscr);
    clear();
    DrawBorder(stdscr);
    mvwaddstr(stdscr, 5, 10, "1 - Start Game");
    mvwaddstr(stdscr, 6, 10, "2 - Exit Game");
    refresh();
}

void Interface::DrawBorder(WINDOW* win)
{
    int x, y;
    x = getmaxx(win);
    y = getmaxy(win);
    
    mvwaddch(win, 0, 0, '+');
    mvwaddch(win, 0, x-1, '+');
    mvwaddch(win, y-1, 0, '+');
    mvwaddch(win, y-1, x-1, '+');
    
    for(int i = 1; i < x-1; i++)
    {
        mvwaddch(win, 0, i, '-');
        mvwaddch(win, 35-1, i, '-');
    }
    
    for(int i = 1; i < y-1; i++)
    {
        mvwaddch(win, i, 0, '|');
        mvwaddch(win, i, 150-1, '|');
    }
}

void Interface::SetScreenSize(int lines, int columns)
{
#if (defined (__linux__) || defined (__unix__)) && !defined (_WIN32)

    std::ostringstream syscmd;
    syscmd << "\e[8;" << lines << ";" << columns << "t";
    std::cout << syscmd.str();

#elif defined (_WIN32) && (!defined (__linux__) || !defined (__unix__))

#include <windows.h>
    
    HANDLE hconsola = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD tam;
    SMALL_RECT DisplayArea;

    tam.X = columns;
    tam.Y = lines;
    SetConsoleScreenBufferSize(hconsola, tam);

    DisplayArea.Top = 0;
    DisplayArea.Left = 0;
    DisplayArea.Bottom = lines - 1;
    DisplayArea.Right = columns - 1;
    SetConsoleWindowInfo(hconsola, TRUE, &DisplayArea);

    #endif
}

void Interface::DrawScene(WINDOW* win)
{
    getchar();
    
    wclear(win);
    wrefresh(win);
    
    int SKY_COLOR = 11;
    int SKY_BACKGROUND;
    int SKY_FOREGROUND;
    int x, y;
    x = getmaxx(win);
    y = getmaxy(win);
    
    init_color(SKY_FOREGROUND, 1000, 1000, 1000);
    init_color(SKY_BACKGROUND, 1000, 1000, 1000);
    
    init_pair(1, SKY_FOREGROUND, SKY_BACKGROUND);
    
    wattron(win, COLOR_PAIR(1));
    
    for(int i = 0; i < y; i++)
    {
        for(int j = 0; j < x; j++)
        {
            mvwaddch(win, i, j, ' ');
        }
    }
    wrefresh(win);
    
    getchar();
}

Interface::~Interface()
{
    endwin();
}