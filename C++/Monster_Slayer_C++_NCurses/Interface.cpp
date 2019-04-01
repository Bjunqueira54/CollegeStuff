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
    ColorInitializer();
    getchar();
    DrawScene(stdscr);
    clear();
    DrawBorder(stdscr);
    mvwaddstr(stdscr, 5, 10, "1 - Start Game");
    mvwaddstr(stdscr, 6, 10, "2 - Exit Game");
    refresh();
}

void Interface::DrawScene(WINDOW *win)
{
    wclear(win);
    int y = getmaxy(win);
    y--;
    
    int x = getmaxx(win);
    
    wattron(win, COLOR_PAIR(SKY_COLOR));
    
    for(int i = 0; i < y/2; i++)
    {
        for (int j = 0; j < x; j++)
        {
            mvwaddch(win, i, j, ' ');
        }

    }
    
    wattron(win, COLOR_PAIR(GROUND_COLOR));
    
    for (int i = y/2; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            mvwaddch(win, i, j, ' ');
        }
    }
    
    wrefresh(win);
    getchar();
    wattron(win, COLOR_PAIR(TERM_COLOR_DEFAULT));
    wclear(win);
    wrefresh(win);
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

void Interface::DrawRenderModel(WINDOW *win, vector<int> coord)
{
    wattron(win, COLOR_PAIR(RENDER_CHAR_DEFAULT));
    
    for (int i = 0; i < coord.size(); i++)
    {
        mvwaddch(win, coord[i][1], coord[i][0], ' ');
    }

    wattron(win, COLOR_PAIR(TERM_COLOR_DEFAULT));
    wrefresh(win);
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

void Interface::ColorInitializer()
{
    init_pair(TERM_COLOR_DEFAULT, COLOR_WHITE, COLOR_BLACK);
    init_pair(SKY_COLOR, COLOR_WHITE, COLOR_CYAN);
    
    short COLOR_GRAY;
    
    init_color(COLOR_GRAY, COLOR_CONVERTER(220), COLOR_CONVERTER(220), COLOR_CONVERTER(220));
    
    init_pair(GROUND_COLOR, COLOR_BLACK, COLOR_GRAY);
    init_pair(RENDER_CHAR_DEFAULT, COLOR_WHITE, COLOR_WHITE);
}

Interface::~Interface()
{
    endwin();
}