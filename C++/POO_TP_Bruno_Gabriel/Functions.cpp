#include "headers.h"
#include "Functions.h"

using namespace std;

Settings settings;
Map map;

vector <string> userDrawCustomMap(const Language lang)
{
    WINDOW *cmap;
    cmap = subwin(stdscr, 12, 22, 0, 0);
    wclear(wmap);
    wrefresh(wmap);
    delwin(wmap);
    drawBox(cmap);
    
    int opt;
    int y=1, x=1;
    int w=0, l=0;
    int spaces=0;
    vector<string>Map;
    
    mvwaddstr(wlog, 3, 1, lang.getLine(43));
    mvwaddstr(wlog, 4, 1, lang.getLine(45));
    wrefresh(wlog);
    
    keypad(stdscr, TRUE);
    curs_set(TRUE);
    wmove(cmap, y, x);
    wrefresh(cmap);
    
    do
    {
        opt = getch();
        
        if(opt == '.' || opt == '+')
        {
            mvwaddch(cmap, y, x, opt);
            wmove(cmap, y, x);
        }
        else if((opt >='A' && opt <='Z') || (opt >= 'a' && opt <= 'z'))
        {
            int cury, curx;
            vector<char> pos;
            
            getyx(cmap, cury, curx);
            
            pos.push_back(mvwinch(cmap, cury-1, curx-1));
            pos.push_back(mvwinch(cmap, cury-1, curx));
            pos.push_back(mvwinch(cmap, cury-1, curx+1));
            pos.push_back(mvwinch(cmap, cury, curx-1));
            pos.push_back(mvwinch(cmap, cury, curx+1));
            pos.push_back(mvwinch(cmap, cury+1, curx-1));
            pos.push_back(mvwinch(cmap, cury+1, curx));
            pos.push_back(mvwinch(cmap, cury+1, curx+1));
            
            for(int i=0; i<pos.size(); i++)
            {
                if(pos[i] == '.')
                    w=1;
                else if(pos[i] == '+')
                    l=1;
            }
            
            if(w==1 && l==1)
                mvwaddch(cmap, cury, curx, opt);
            wmove(cmap, cury, curx);
            w=l=0;
        }
        else if(opt>=KEY_DOWN && opt<=KEY_RIGHT)
        {
            int begy=1, begx=1, maxy, maxx;
            maxy = getmaxy(cmap)-2;
            maxx = getmaxx(cmap)-2;
            switch(opt)
            {
                case KEY_RIGHT:
                    if(x<maxx)
                        x++;
                    break;
                    
                case KEY_DOWN:
                    if(y<maxy)
                        y++;
                    break;
                    
                case KEY_UP:
                    if(y>begy)
                        y--;
                    break;
                    
                case KEY_LEFT:
                    if(x>begx)
                        x--;
                    break;
                    
                default:
                    break;
            }
            wmove(cmap, y, x);
        }
        wrefresh(cmap);
    }
    while(opt != 10);
    
    for(int i=1; i<getmaxy(cmap)-1; i++)
    {
        char line[20];
        mvwinnstr(cmap, i, 1, line, 20);
        
        for(int j=0; j<20; j++)
        {
            if(line[j] == ' ')
            {
                spaces = 1;
                break;
            }
        }
        
        Map.push_back(line);
    }
    
    //Detect empty spaces here
    if(spaces == 1)
    {
        for(int i=0; i<Map.size(); i++)
            for(int j=0; j<Map[i].size(); j++)
                if(Map[i][j] == ' ')
                    Map[i][j] = '.';
    }
    
    curs_set(FALSE);
    keypad(stdscr, FALSE);
    wclear(cmap);
    wrefresh(cmap);
    delwin(cmap);
    
    wmap = subwin(stdscr, 20, 40, 0, 0);
    drawBox(wmap);
    
    return Map;
}

string getInput(WINDOW *win = stdscr, int str_size=20)
{
    string input;
    char opt;
    int y, x;
    
    getyx(win, y, x);
    x-=1;
    
    do
    {
        opt = getch();

        if((opt == ' ') || (opt == '.')|| (opt >= '0' && opt <= '9') || (opt >= 'A' && opt <= 'Z') || (opt >= 'a' && opt <= 'z'))
        {
            if(input.size() < str_size)
            {
                if(!(input.empty() && opt == ' '))
                {
                    input.push_back(opt);
                    mvwaddstr(win, y, x, input.c_str());
                    mvwaddch(win, y, x + strlen(input.c_str()), '_');
                    wrefresh(win);
                }
            }
        }
        else if(opt == 8 || opt == 127)
        {
            if(!(input.empty()))
            {
                input.pop_back();
                mvwaddstr(win, y, x, input.c_str());
                wclrtoeol(win);
                mvwaddch(win, y, getmaxx(win)-1, '|');
                mvwaddch(win, y, x + strlen(input.c_str()), '_');
                wrefresh(win);
            }
        }
    }
    while(opt != 10);   //Key Enter
    
    return input;
}

string getNumInput(WINDOW *win=stdscr, int str_size=5)
{
    string input;
    char opt;
    int y, x;
    
    getyx(win, y, x);
    x-=1;
    
    do
    {
        opt = getch();
        
        if(opt >= '0' && opt <= '9')
        {
            if(input.size() <= str_size)
            {
                input.push_back(opt);
                mvwaddstr(win, y, x, input.c_str());
                mvwaddch(win, y, x + strlen(input.c_str()), '_');
                wrefresh(win);
            }
        }
        else if(opt == 8 || opt == 127)
        {
            if(!(input.empty()))
            {
                input.pop_back();
                mvwaddstr(win, y, x, input.c_str());
                wclrtoeol(win);
                mvwaddch(win, y, getmaxx(win)-1, '|');
                mvwaddch(win, y, x + strlen(input.c_str()), '_');
                wrefresh(win);
            }
        }
    }
    while(opt != 10);
    
    return input;
}

void createDefaultConfig(char opt, string &filename, const Language lang)
{
    ofstream file;
        
    if(opt == 'D' || opt == 'd')
    {
        filename = DEFAULT_CONFIG;
        file.open(filename, ios::out | ios::trunc);
        file << "...............+++++" << endl;
        file << "..........++++++++++" << endl;
        file << "..........A+++++++++" << endl;
        file << ".............+++++++" << endl;
        file << "..............++++++" << endl;
        file << "....+a...........B++" << endl;
        file << "...++++..........+++" << endl;
        file << "....++............++" << endl;
        file << "...................b" << endl;
        file << "...................." << endl;
        file << "" << endl;
        file << "money 1000" << endl;
        file << "pirateprob 20" << endl;
        file << "shipprice 100" << endl;
        file << "crewprice 1" << endl;
        file << "fishprice 1" << endl;
        file << "cargobuy 2" << endl;
        file << "cargosell 3" << endl;
        file << "harborcrew 100" << endl;
        file << "eventprob 30" << endl;
        file << "stormprob 30" << endl;
        file << "sirenprob 30" << endl;
        file << "calmprob 20" << endl;
        file << "riotprob 20" << endl;
    }
    else
    {
        string input;
        filename.clear();
        mvwaddstr(wlog, 1, 1, lang.getLine(28));
        wrefresh(wlog);
        do
        {
            filename = getInput(wlog, 15);
        }
        while(filename.empty());
        mvwaddch(wlog, getcury(wlog), getcurx(wlog)-1, ' ');
        file.open(filename, ios::out | ios::trunc);

        mvwaddstr(wlog, 2, 1, lang.getLine(29));
        mvwaddstr(wlog, 3, 1, lang.getLine(43));
        wrefresh(wlog);

        char opt;

        do
        {
            opt = getch();
        }
        while(opt!='Y' && opt!='y' && opt!='N' && opt!='n');

        if(opt=='Y' || opt=='y')
        {
            vector<string> Map;
            Map = userDrawCustomMap(lang);
            
            for(int i=0; i<=Map.size(); i++)
                file << Map[i] << endl;
        }
        else
        {
            file << "...............+++++" << endl;
            file << "..........++++++++++" << endl;
            file << "..........A+++++++++" << endl;
            file << ".............+++++++" << endl;
            file << "..............++++++" << endl;
            file << "....+a...........B++" << endl;
            file << "...++++..........+++" << endl;
            file << "....++............++" << endl;
            file << "...................b" << endl;
            file << "...................." << endl;
            file << "" << endl;
        }

        wmove(wlog, 4, 1);
        wclrtoeol(wlog);
        mvwaddch(wlog, 4, getmaxx(wlog)-1, '|');
        mvwaddstr(wlog, 4, 1, lang.getLine(30));
        wrefresh(wlog);
        do
        {
            input = getNumInput(wlog, 10);
        }
        while(input.empty());
        mvwaddch(wlog, getcury(wlog), getcurx(wlog)-1, ' ');
        file << "money " << input << endl;
        
        mvwaddstr(wlog, 5, 1, lang.getLine(31));
        wrefresh(wlog);
        do
        {
            input = getNumInput(wlog, 3);
        }
        while(input.empty());
        mvwaddch(wlog, getcury(wlog), getcurx(wlog)-1, ' ');
        file << "pirateprob  " << input << endl;
        
        mvwaddstr(wlog, 6, 1, lang.getLine(32));
        wrefresh(wlog);
        do
        {
            input = getNumInput(wlog, 5);
        }
        while(input.empty());
        mvwaddch(wlog, getcury(wlog), getcurx(wlog)-1, ' ');
        file << "shipprice " << input << endl;
        
        mvwaddstr(wlog, 7, 1, lang.getLine(33));
        wrefresh(wlog);
        do
        {
            input = getNumInput(wlog, 5);
        }
        while(input.empty());
        mvwaddch(wlog, getcury(wlog), getcurx(wlog)-1, ' ');
        file << "crewprice " << input << endl;
        
        mvwaddstr(wlog, 8, 1, lang.getLine(34));
        wrefresh(wlog);
        do
        {
            input = getNumInput(wlog, 10);
        }
        while(input.empty());
        mvwaddch(wlog, getcury(wlog), getcurx(wlog)-1, ' ');
        file << "fishprice " << input << endl;
        
        mvwaddstr(wlog, 9, 1, lang.getLine(35));
        wrefresh(wlog);
        do
        {
            input = getNumInput(wlog, 10);
        }
        while(input.empty());
        mvwaddch(wlog, getcury(wlog), getcurx(wlog)-1, ' ');
        file << "cargobuy " << input << endl;
        
        mvwaddstr(wlog, 10, 1, lang.getLine(36));
        wrefresh(wlog);
        do
        {
            input = getNumInput(wlog, 10);
        }
        while(input.empty());
        mvwaddch(wlog, getcury(wlog), getcurx(wlog)-1, ' ');
        file << "cargosell " << endl;
        
        mvwaddstr(wlog, 11, 1, lang.getLine(37));
        wrefresh(wlog);
        do
        {
            input = getNumInput(wlog, 10);
        }
        while(input.empty());
        mvwaddch(wlog, getcury(wlog), getcurx(wlog)-1, ' ');
        file << "harborcrew " << input << endl;
        
        mvwaddstr(wlog, 12, 1, lang.getLine(38));
        wrefresh(wlog);
        do
        {
            input = getNumInput(wlog, 10);
        }
        while(input.empty());
        mvwaddch(wlog, getcury(wlog), getcurx(wlog)-1, ' ');
        file << "eventprob " << input << endl;
        
        mvwaddstr(wlog, 13, 1, lang.getLine(39));
        wrefresh(wlog);
        do
        {
            input = getNumInput(wlog, 10);
        }
        while(input.empty());
        mvwaddch(wlog, getcury(wlog), getcurx(wlog)-1, ' ');
        file << "stormprob " << input << endl;
        
        mvwaddstr(wlog, 14, 1, lang.getLine(40));
        wrefresh(wlog);
        do
        {
            input = getNumInput(wlog, 10);
        }
        while(input.empty());
        mvwaddch(wlog, getcury(wlog), getcurx(wlog)-1, ' ');
        file << "sirenprob " << input << endl;
        
        mvwaddstr(wlog, 15, 1, lang.getLine(41));
        wrefresh(wlog);
        do
        {
            input = getNumInput(wlog, 10);
        }
        while(input.empty());
        mvwaddch(wlog, getcury(wlog), getcurx(wlog)-1, ' ');
        file << "calmprob " << input << endl;
        
        mvwaddstr(wlog, 16, 1, lang.getLine(42));
        wrefresh(wlog);
        do
        {
            input = getNumInput(wlog, 10);
        }
        while(input.empty());
        mvwaddch(wlog, getcury(wlog), getcurx(wlog)-1, ' ');
        file << "riotprob " << input << endl;
    }
    
    file.close();
}

//Draws a neat screen wide box for the main menu.
//Don't forget to give it the a Language object
//or else nothing will show up
void drawMainMenu(const Language lang)
{   
    int y=0, esp, r, extra, i=10;
    esp = getVertCenter(stdscr, 4, r, extra);
    
    y+=(esp+r);
    mvwaddstr(stdscr, ++y, i, lang.getLine(2));
    y+=esp;
    mvwaddstr(stdscr, ++y, i, lang.getLine(3));
    y+=esp;
    mvwaddstr(stdscr, ++y, i, lang.getLine(4));
    y+=esp;
    mvwaddstr(stdscr, ++y, i, lang.getLine(5));
    
    //just for fun  //Don't forget to increment 1 centesimal case on the version define every time you push to git
    ostringstream con;
    con << "Beta: " << GAME_VERSION_MAJOR << "." << GAME_VERSION_MINOR;
    mvwaddstr(stdscr, getmaxy(stdscr) - 2, getmaxx(stdscr) - strlen(con.str().c_str()) - 1, con.str().c_str());
    refresh();
}

void drawMap()
{
    wclear(wmap);
    drawBox(wmap);
    
    /*init_color usa a seguinte syntax
    
     init_pair(nº desejado para identificar a cor (Pode usar-se um #define NOME Nº),
                montante de vermelho (1-1000),
                montante de verde (1-1000),
                montante de azul (1-1000));
     
     como na internet calcula-se valores para RGB em 1-255, tem-se de calcular
     os montantes para init_pair() com (valor RGB)*3.9216 (arrendondado para baixo nas unidades)*/
    
    /*init_color(COLOR_LBROWN, 255, 222, 173);  //Isto está a usar valores 1-255, e esta errado
    init_color(COLOR_DBROWN, 139, 69, 19);*/
    
    init_color(COLOR_DBROWN, 102*3.9216, 51*3.9216, 0);
    init_color(COLOR_LBROWN, 1000, 153*3.9216, 51*3.9216);

    /*Fazer init_pair para todas as combinações
     de cores a serem usadas pelo jogo. Exemplos:
     Foreground BRANCO e Background AZUL ESCURO
     Foreground VERMELHO e Background AZUL CLARO
     Foreground VERDE e Background CASTANHO ESCURO*/
    
    //Exemplo
    
    /*init_pair(4, COLOR_WHITE, COLOR_LBROWN);
    init_pair(5, COLOR_WHITE, COLOR_DBROWN);
    
    wattron(wmap, COLOR_PAIR(4));
    mvwaddch(wmap, 1, 1, ' ');
    mvwaddch(wmap, 1, 2, ' ');
    mvwaddch(wmap, 2, 1, ' ');
    mvwaddch(wmap, 2, 2, ' ');
    wattron(wmap, COLOR_PAIR(5));
    mvwaddch(wmap, 1, 3, ' ');
    mvwaddch(wmap, 1, 4, ' ');
    mvwaddch(wmap, 2, 3, ' ');
    mvwaddch(wmap, 2, 4, ' ');*/
    wrefresh(wmap);
}

//Recieves a string with spaces and the full command
//to be separated into single words for command processing.
//Also recieves a Language class object to check the parsed
//commands against.
bool parseCmd(string cmd, int &phase, const Language lang)
{
    string parse;
    istringstream is;

    is.str(cmd);
    
    is >> parse;

    for(int i=0; i<lang.getCmdvec().size(); i++)
    {
        if(parse.compare(lang.getCmd(i)) == 0)
        {
            switch(i)
            {
                case 0: //config <filename>
                {
                    if(phase != 1)
                    {
                        return false;
                    }
                    
                    string filename;
                    is >> filename;
                    ifstream file;
                    file.open(filename, ios::in);
                    
                    if(!file.is_open())
                    {
                        mvwaddstr(wcmd, getmaxy(wcmd)-2, 1, lang.getLine(21));
                        wclrtoeol(wcmd);
                        mvwaddch(wcmd, getmaxy(wcmd)-2, getmaxx(wcmd)-1, '|');
                        wrefresh(wcmd);
                        getch();
                        mvwaddstr(wcmd, getmaxy(wcmd)-2, 1, lang.getLine(22));
                        wclrtoeol(wcmd);
                        mvwaddch(wcmd, getmaxy(wcmd)-2, getmaxx(wcmd)-1, '|');
                        wrefresh(wcmd);
                        
                        char opt;
                        
                        do
                        {
                            opt = getch();
                        }
                        while(opt!='Y' && opt!='y' && opt!='S' && opt!='s' && opt!='N' && opt!='n');
                        
                        if(opt == 'Y' || opt == 'y' || opt == 'S' || opt == 's')
                        {
                            filename = DEFAULT_CONFIG;
                            file.open(filename, ios::in);
                            
                            if(!file.is_open())
                            {
                                mvwaddstr(wcmd, getmaxy(wcmd)-2, 1, lang.getLine(21));
                                wclrtoeol(wcmd);
                                mvwaddch(wcmd, getmaxy(wcmd)-2, getmaxx(wcmd)-1, '|');
                                wrefresh(wcmd);
                                getch();
                                mvwaddstr(wcmd, getmaxy(wcmd)-2, 1, lang.getLine(23));
                                wclrtoeol(wcmd);
                                mvwaddch(wcmd, getmaxy(wcmd)-2, getmaxx(wcmd)-1, '|');
                                wrefresh(wcmd);
                                
                                do
                                {
                                    opt = getch();
                                }
                                while(opt!='Y' && opt!='y' && opt!='S' && opt!='s' && opt!='N' && opt!='n');
                                
                                if(opt == 'Y' || opt == 'y' || opt == 'S' || opt == 's')
                                {
                                    mvwaddstr(wcmd, getmaxy(wcmd)-2, 1, lang.getLine(24));
                                    wclrtoeol(wcmd);
                                    mvwaddch(wcmd, getmaxy(wcmd)-2, getmaxx(wcmd)-1, '|');
                                    wrefresh(wcmd);
                                    
                                    do
                                    {
                                        opt = getch();
                                    }
                                    while(opt != 'D' && opt != 'd' && opt != 'C' && opt != 'c');
                                    
                                    createDefaultConfig(opt, filename, lang);
                                    
                                    file.open(filename, ios::in);
                                }
                                else
                                    return false;
                            }
                        }
                        else
                        {
                            mvwaddstr(wcmd, getmaxy(wcmd)-2, 1, lang.getLine(23));
                            wclrtoeol(wcmd);
                            mvwaddch(wcmd, getmaxy(wcmd)-2, getmaxx(wcmd)-1, '|');
                            wrefresh(wcmd);
                            
                            do
                            {
                                opt = getch();
                            }
                            while(opt!='Y' && opt!='y' && opt!='S' && opt!='s' && opt!='N' && opt!='n');
                            
                            if(opt == 'Y' || opt == 'y' || opt == 'S' || opt == 's')
                            {
                                mvwaddstr(wcmd, getmaxy(wcmd)-2, 1, lang.getLine(24));
                                wclrtoeol(wcmd);
                                mvwaddch(wcmd, getmaxy(wcmd)-2, getmaxx(wcmd)-1, '|');
                                wrefresh(wcmd);

                                do
                                {
                                    opt = getch();
                                }
                                while(opt != 'D' && opt != 'd' && opt != 'C' && opt != 'c');

                                createDefaultConfig(opt, filename, lang);

                                file.open(filename, ios::in);
                            }
                            else
                                return false;
                        }
                    }

                    string success;
                    success += lang.getLine(26) + filename;
                    mvwaddstr(wcmd, getmaxy(wcmd)-2, 1, success.c_str());
                    wclrtoeol(wcmd);
                    mvwaddch(wcmd, getmaxy(wcmd)-2, getmaxx(wcmd)-1, '|');
                    
                    Settings set(file);
                    
                    settings = set;
                    map = Map(file);
                    
                    phase = 2;
                    mvwaddstr(wcmd, 1, 1, lang.getLine(11));
                    wclrtoeol(wcmd);
                    mvwaddch(wcmd, 1, getmaxx(wcmd)-1, '|');
                    mvwaddstr(wcmd, 1, strlen(lang.getLine(11)) + 1, "1");
                    wrefresh(wcmd);
                    drawBox(wlog);
                    drawBox(wmap);
                    drawMap();
                    
                    break;
                }
                case 1: //exec <filename>
                {
                    string filename;
                    is >> filename;
                    ifstream file;
                    file.open(filename, ios::in);
                    if(!file.is_open())
                    {
                        mvwaddstr(wcmd, getmaxy(wcmd)-2, 1, lang.getLine(21));
                        wrefresh(wcmd);
                        getch();
                        return false;
                    }
                    string input;
                    
                    do
                    {
                        getline(file, input);
                        parseCmd(input, phase, lang);
                    }
                    while(!file.eof());
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
                case 7: //sell <N>
                {
                    int n;
                    is >> n;
                    /*Create sellCargo(int n) method to Ship class*/
                    break;
                }
                case 8: //move <N> <X>
                {
                    int n;
                    char x;
                    is >> n;
                    is >> x;
                    /*Create move(int x, char x) method to Ship Class*/
                    break;
                }
                case 9: //auto <N>
                {
                    int n;
                    is >> n;
                    /*Create setAuto() method to Ship class and autoShip(int n) to Player class*/
                    break;
                }
                case 10: //stop <N>
                {
                    int n;
                    is >> n;
                    /*Create stopShip(int n) method to Player Class and stop() to Ship class*/
                    break;
                }
                case 11: //pirate <x> <y> <T>
                {
                    int x, y, t;
                    is >> x;
                    is >> y;
                    is >> t;
                    /*Create overloaded method addNewShip(int x, int y, int t) to Player Class*/
                    break;
                }
                case 12: //evpos <E> <x> <y>
                {
                    int event, x, y;
                    is >> event;
                    is >> x;
                    is >> y;
                    /*Create function eventPosition(int type, int x, int y)*/
                    break;
                }
                case 13: //evship <E> <N>
                {
                    int event, id;
                    is >> event;
                    is >> id;
                    /*Create function eventShip(int type, int id) that interacts with class Player*/
                    break;
                }
                case 14: //coins <N>
                {
                    int n;
                    is >> n;
                    //player.addMoney(n);
                    break;
                }
                case 15: //moveto <N> <x> <y> OR moveto <N> <P>
                {
                    /*No idea. Move N to (x,y) or move N to Harbor P*/
                    break;
                }
                case 16: //buycrew <N> <S>
                {
                    int id, n;
                    is >> id;
                    is >> n;
                    /*buySoldier(int id, int n) to Player class*/
                    break;
                }
                case 17: //saveg <filename>
                {
                    string filename;
                    is >> filename;
                    /*Create save game function*/
                    break;
                }
                case 18: //loadg <filename>
                {
                    string filename;
                    is >> filename;
                    /*create load game function*/
                    break;
                }
                case 19:    //delg <filename>
                {
                    string filename;
                    is >> filename;
                    /*create delete saved game function*/
                    break;
                }
                default:
                    break;
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

//Draws a default box around a chosen window
//Works as a clear screen
void drawBox(WINDOW *win)
{
    wclear(win);
    int y, x;
    
    getmaxyx(win, y, x);
    
    for(int i=0; i<y; i++)
    {
        mvwaddch(win, i, 0, '|');
        mvwaddch(win, i, x-1, '|');
    }
    for(int i=0; i<x; i++)
    {
        mvwaddch(win, 0, i, '=');
        mvwaddch(win, y-1, i, '=');
    }
    
    mvwaddch(win, 0, 0, 'x');
    mvwaddch(win, 0, x-1, 'x');
    mvwaddch(win, y-1, 0, 'x');
    mvwaddch(win, y-1, x-1, 'x');

    wrefresh(win);
}