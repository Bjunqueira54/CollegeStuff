#include "headers.h"
#include "Functions.h"

using namespace std;

//Draws a neat screen wide box for the main menu.
//Don't forget to give it the a Language object
//or else nothing will show up
void drawMainMenu(const Language lang)
{   
    int y=0, esp, r, extra;
    esp = getVertCenter(stdscr, 4, r, extra);
    
    y+=(esp+r);
    mvwaddstr(stdscr, y, 5, lang.getLine(2));
    y+=esp;
    mvwaddstr(stdscr, y, 5, lang.getLine(3));
    y+=esp;
    mvwaddstr(stdscr, y, 5, lang.getLine(4));
    y+=esp;
    mvwaddstr(stdscr, y, 5, lang.getLine(5));
    refresh();
}

void drawMap(WINDOW *win)
{
    wclear(win);
    
    init_color(COLOR_LBROWN, 255, 222, 173);
    init_color(COLOR_DBROWN, 139, 69, 19);

    /*Fazer init_color para todas as combinações
     de cores a serem usadas pelo jogo. Exemplos:
     Foreground BRANCO e Background AZUL ESCURO
     Foreground VERMELHO e Background AZUL CLARO
     Foreground VERDE e Background CASTANHO ESCURO*/
    
    wattron(win, COLOR_PAIR(4));
    mvwaddch(win, 1, 1, ' ');
    wattron(win, COLOR_PAIR(5));
    mvwaddch(win, 2, 2, ' ');
    wrefresh(win);
}

//Recieves a string with spaces and the full command
//to be separated into single words for command processing.
//Also recieves a Language class object to check the parsed
//commands against.
bool parseCmd(string cmd, const Language lang, WINDOW *win)
{
    string parse;
    istringstream is;

    is.str(cmd);

    for(int i=0; i<lang.getCmdvec().size(); i++)
    {
        if(parse.compare(lang.getCmd(i)) == 0)
        {
            switch(i)
            {
                case 0: //config <filename>
                {
                    string filename;
                    is >> filename;
                    /*open file with filename*/
                    break;
                }
                case 1: //exec <filename>
                {
                    string filename;
                    is >> filename;
                    /*open file with filename*/
                    break;
                }
                case 3: //buyship <T>
                {
                    int type;
                    is >> type;
                    /*Create addNewShip(int type) method to Player class*/
                    break;
                }
                case 4: //sellship <N>
                {
                    int number;
                    is >> number;
                    /*Create delShip(int id) method to Player class*/
                    break;
                }
                case 5: //list
                {
                    /*Create listPrices() method to Harbor class*/
                    break;
                }
                case 6: //buy <M> <N>
                {
                    int m, n;
                    is >> m;
                    is >> n;
                    /*Create buyCargo(int m, int n) method to Ship class*/
                    break;
                }
                case 7: //move <N> <X>
                {
                    int n;
                    char x;
                    is >> n;
                    is >> x;
                    /*Create move(int x, char x) method to Ship Class*/
                    break;
                }
                case 8: //auto <N>
                {
                    int n;
                    is >> n;
                    /*Create setAuto() method to Ship class and autoShip(int n) to Player class*/
                    break;
                }
                case 9: //stop <N>
                {
                    int n;
                    is >> n;
                    /*Create stopShip(int n) method to Player Class and stop() to Ship class*/
                    break;
                }
                case 10: //pirate <x> <y> <T>
                {
                    int x, y, t;
                    is >> x;
                    is >> y;
                    is >> t;
                    /*Create overloaded method addNewShip(int x, int y, int t) to Player Class*/
                    break;
                }
                case 11: //evpos <E> <x> <y>
                {
                    int event, x, y;
                    is >> event;
                    is >> x;
                    is >> y;
                    /*Create function eventPosition(int type, int x, int y)*/
                    break;
                }
                case 12: //evship <E> <N>
                {
                    int event, id;
                    is >> event;
                    is >> id;
                    /*Create function eventShip(int type, int id) that interacts with class Player*/
                    break;
                }
                case 13: //coins <N>
                {
                    int n;
                    is >> n;
                    //player.addMoney(n);
                    break;
                }
                case 14: //moveto <N> <x> <y> OR moveto <N> <P>
                {
                    /*No idea. Move N to (x,y) or move N to Harbor P*/
                    break;
                }
                case 15: //buycrew <N> <S>
                {
                    int id, n;
                    is >> id;
                    is >> n;
                    /*buySoldier(int id, int n) to Player class*/
                    break;
                }
                case 16: //saveg <filename>
                {
                    string filename;
                    is >> filename;
                    /*Create save game function*/
                    break;
                }
                case 17: //loadg <filename>
                {
                    string filename;
                    is >> filename;
                    /*create load game function*/
                    break;
                }
                case 18:    //delg <filename>
                {
                    string filename;
                    is >> filename;
                    /*create delete saved game function*/
                    break;
                }
                default:
                    mvwaddstr(win, getmaxy(win)-2, 1, "How did you get here?!");
            }
            return true;
        }
    }

        return false;

}

//Recieves a const char* string and tries to horizontally
//center it on the given screen. TO-DO: Change all current
//getCenter function calls to (WINDOW *win, const char*(OR)string a)
int getCenter(const char* a)
{
    int x;
    
    if(strcmp(a,"") == 0)
        return 0;
    
    string str(a);
    
    x = (getmaxx(stdscr)-strlen(str.c_str()))/2;
    
    return x;
}

//Recieves a string object and tries to horizontally
//center it on the given screen. TO-DO: Change all current
//getCenter function calls to (WINDOW *win, const char*(OR)string a)
int getCenter(string a)
{
    int x;
    
    x = (getmaxx(stdscr) - strlen(a.c_str()))/2;
    
    return x;
}

//Sets *esp to whatever value is required to correctly center
//and space out n menus items in window *win. Returns 0 if no 
//more modifications are needed outside of this function, else
//you need to check if &extraflag is 0 or 1. If it's 0, you can
//add whatever is returned from this function to the extremes
//of your menus; if it's 1, it means there's no possible way to
//have consistent spacing with in your menu and you'll have to
//add that 1 extra space wherever.
int getVertCenter(WINDOW *win, int n, int &r, int &extraflag)
{
    int y, esp;
    
    y = getmaxy(win);
    
    esp = (y-(n+2))/(n+1); //rounds down
    
    r = (y-(n+2))%(n+1);
    
    if(r != 0)
    {
        r=r/2;
        if(r%2 == 0)
        {
            extraflag = 0;
            return esp;
        }
        else
        {
            extraflag = 1;
            return esp;
        }
    }
    else
    {
        extraflag = 0;
        return esp;
    }
}

void drawBox(WINDOW *win)
{
    wclear(win);
    int y, x;
    
    getmaxyx(win, y, x);
    
    for(int i=1; i<y; i++)
    {
        mvwaddch(win, i, 0, '|');
        mvwaddch(win, i, x-1, '|');
    }
    for(int i=1; i<x; i++)
    {
        mvwaddch(win, 0, i, '-');
        mvwaddch(win, y-1, i, '-');
    }
    
    mvwaddch(win, 0, 0, '*');
    mvwaddch(win, 0, x-1, '*');
    mvwaddch(win, y-1, 0, '*');
    mvwaddch(win, y-1, x-1, '*');
    
    wrefresh(win);
}