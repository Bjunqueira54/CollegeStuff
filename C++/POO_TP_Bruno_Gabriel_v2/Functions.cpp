#include "Functions.h"

#define TERM_DEFAULT 11
#define OCEAN_STORM 12
#define OCEAN_CALM 13
#define LAND_DARK 14
#define LAND_LIGHT 15
#define FRIENDLY 16
#define UNFRIENDLY 17

using namespace std;

Settings *settings;
Map *map;

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
    vector<string>g_map;
    
    mvwaddstr(wlog, 3, 1, lang.getLine(43));
    mvwaddstr(wlog, 4, 1, lang.getLine(45));
    wrefresh(wlog);
    
    keypad(stdscr, TRUE);
    curs_set(TRUE);
    wmove(cmap, 1, 1);
    mvwaddch(cmap, 1, 1, ' ');
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
        g_map.push_back(line);
    }
    
    //Detect empty spaces here
    if(spaces == 1)
    {
        for(int i=0; i<g_map.size(); i++)
            for(int j=0; j<g_map[i].size(); j++)
                if(g_map[i][j] == ' ')
                    g_map[i][j] = '.';
    }
    
    curs_set(FALSE);
    keypad(stdscr, FALSE);
    wclear(cmap);
    wrefresh(cmap);
    delwin(cmap);
    
    wmap = subwin(stdscr, 22, 42, 0, 0);
    drawBox(wmap);
    
    return g_map;
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
    
    mvwaddch(win, y, x + strlen(input.c_str()), ' ');
    
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
    
    mvwaddch(win, y, x + strlen(input.c_str()), ' ');
    
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
        while(opt!='Y' && opt!='y' && opt!='S' && opt!='s' && opt!='N' && opt!='n');

        if(opt=='Y' || opt=='y' || opt=='S' || opt=='s')
        {
            vector<string> g_map;
            g_map = userDrawCustomMap(lang);
            
            for(int i=0; i<=g_map.size(); i++)
                file << g_map[i] << endl;
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

void drawMainMenu()
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
    //Color Initialization
    init_color(LAND_DARK, 545, 270, 75);
    init_color(LAND_LIGHT, 870, 720, 530);
    
    init_color(FRIENDLY, 100, 750, 100);
    init_color(UNFRIENDLY, 1000, 0, 0);
    
    //Pair creation
    
    //Dark Ocean Tiles
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    init_pair(2, COLOR_GREEN, COLOR_BLUE);
    init_pair(3, COLOR_RED, COLOR_BLUE);
    //Light Ocean Tiles
    init_pair(4, COLOR_WHITE, COLOR_CYAN);
    init_pair(5, COLOR_GREEN, COLOR_CYAN);
    init_pair(6, COLOR_RED, COLOR_CYAN);
    
    //Land Tiles
    init_pair(7, COLOR_WHITE, LAND_DARK);
    init_pair(8, COLOR_WHITE, LAND_LIGHT);
    
    //Harbor Tiles
    init_pair(9, COLOR_BLACK, FRIENDLY);
    init_pair(10, COLOR_BLACK, UNFRIENDLY);
    
    init_pair(TERM_DEFAULT, COLOR_WHITE, COLOR_BLACK);
    
    wattron(wmap, COLOR_PAIR(TERM_DEFAULT));

    wclear(wmap);
    drawBox(wmap);
    
    if(phase == 1)
        return;
    
    bool cc=true;
    char tl, tr, bl, br;
    string line;
    
    for(int y=0; y<map->getMap().size(); y++)
    {
        cc = !cc;
        line = map->getMap()[y];
        
        for(int x=0; x<line.size(); x++)
        {
            tl = bl = tr = br = ' ';
            switch(line[x])
            {
                case'.':    //Water
                    if(cc == true)
                        wattron(wmap, COLOR_PAIR(1));
                    else
                        wattron(wmap, COLOR_PAIR(4));
                    cc = !cc;
                    break;
                case'+':    //Land
                    if(cc == true)
                        wattron(wmap, COLOR_PAIR(7));
                    else
                        wattron(wmap, COLOR_PAIR(8));
                    cc = !cc;
                    break;
                case '^':   //Player Ship
                {
                    if(cc == true)
                        wattron(wmap, COLOR_PAIR(2));
                    else
                        wattron(wmap, COLOR_PAIR(5));
                    //set characters here
                    ostringstream ct;
                    ct << "0" << map->getShipId(y, x);
                    tr = ct.str()[ct.str().size()-1];
                    tl = ct.str()[ct.str().size()-2];
                    br = map->getShipType(y, x);
                    bl = '<';
                    cc = !cc;
                    break;
                }
                case '*':   //Pirate Ship
                    if(cc == true)
                        wattron(wmap, COLOR_PAIR(3));
                    else
                        wattron(wmap, COLOR_PAIR(6));
                    //set characters here
                    //Placeholder characters
                    tl = tr = bl = br = '*';
                    cc = !cc;
                    break;
                case '?':      //Lost Ship
                    if(cc == true)
                        wattron(wmap, COLOR_PAIR(1));
                    else
                        wattron(wmap, COLOR_PAIR(4));
                    //set characters here
                    tl = tr = bl = br = '@';
                    cc = !cc;
                    break;
                default:    //Default == Harbors
                    tr = map->getHarborId(y, x);
                    if(map->getHarborState(y, x) == true)
                    {
                        wattron(wmap, COLOR_PAIR(9));
                        bl = 'F';
                        br = 'R';
                    }
                    else
                    {
                        wattron(wmap, COLOR_PAIR(10));
                        bl = 'U';
                        br = 'N';
                    }
                    cc = !cc;
                    break;
            }
            
            mvwaddch(wmap, ((y+1)*2)-1, ((x+1)*2)-1, tl);
            mvwaddch(wmap, ((y+1)*2)-1, ((x+1)*2), tr);
            mvwaddch(wmap, ((y+1)*2), ((x+1)*2)-1, bl);
            mvwaddch(wmap, ((y+1)*2), ((x+1)*2), br);
        }
    }
    wrefresh(wmap);
}

int parseCmd(string cmd)
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
                case 0: //config <filename> //Should be working as intended. READY FOR BETA TEST
                {
                    if(phase != 1)
                    {
                        mvwaddstr(wcmd, getmaxy(wcmd)-2, 1, lang.getLine(25));
                        wclrtoeol(wcmd);
                        mvwaddch(wcmd, getmaxy(wcmd)-2, getmaxx(wcmd)-1, '|');
                        wrefresh(wcmd);
                        return -1;
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
                                    return -1;
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
                                return -1;
                        }
                    }

                    string success;
                    success = lang.getLine(26) + filename;
                    mvwaddstr(wcmd, getmaxy(wcmd)-2, 1, success.c_str());
                    wclrtoeol(wcmd);
                    mvwaddch(wcmd, getmaxy(wcmd)-2, getmaxx(wcmd)-1, '|');
                    
                    string input;
                    vector<string> mapvals, setvals;
                    
                    do
                    {
                        getline(file, input);
                        mapvals.push_back(input);
                    }
                    while(file.peek() != '\n');
                    
                    do
                    {
                        getline(file, input);
                        setvals.push_back(input);
                    }
                    while(!file.eof());
                    
                    settings = new Settings(setvals);
                    player->SetMoney(settings->GetStartmoney());
                    map = new Map(mapvals);
                    map->setMainHarbors();
                    
                    phase = 2;
                    mvwaddstr(wcmd, 1, 1, lang.getLine(11));
                    wclrtoeol(wcmd);
                    mvwaddch(wcmd, 1, getmaxx(wcmd)-1, '|');
                    mvwaddstr(wcmd, 1, strlen(lang.getLine(11)) + 1, "1");
                    wrefresh(wcmd);
                    drawBox(wlog);
                    drawMap();
                    break;
                }
                case 1: //exec <filename>   //Should be working as intended. READY FOR BETA TEST
                {
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
                        return -1;
                    }
                    
                    string input;
                    int status;
                    
                    do
                    {
                        getline(file, input);
                        status = parseCmd(input);
                        
                        if(status == 2 || status == 20)
                        {
                            return status;
                        }
                    }
                    while(!file.eof());
                    
                    break;
                }
                case 2: //next              //It's working as inteded. NO MORE TESTING REQUIRED
                {
                    return 2;
                    break;
                }
                case 3: //buyship <T>       //Should be working as intended. REQUIRES STRINGS AND TESTING
                {
                    if(settings->GetShipprice() > player->GetMoney())
                        return -1;
                    
                    char type;
                    bool status;
                    is >> type;

                    if(type != 'E' && type != 'e' &&
                            type != 'F' && type != 'f' &&
                            type != 'V' && type != 'v' &&
                            type != 'G' && type != 'g' &&
                            type != 'S' && type != 's')
                        return -1;
                    else
                    {
                        map->newShip(type);
                        player->addMoney(0-settings->GetShipprice());
                    }
                    return i;

                    break;
                }
                case 4: //sellship <N>      //Finished first definition. REQUIRES TESTING
                {
                    int id;
                    is >> id;
                    
                    if(map->sellShip(id) == true)
                        player->addMoney(settings->GetShipprice());
                    else
                        return -1;
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
                case 8: //move <N> <X>      //Should be working as intended. READY FOR BETA TEST.
                {
                    int n;
                    string x;
                    is >> n;
                    if(!is.good())
                        return -1;
                    
                    is >> x;
                    
                    map->move(n, x);
                    
                    break;
                }
                case 9: //auto <N>
                {
                    int n;
                    is >> n;
                    /*Create setAuto() method to Ship class and autoShip(int n) to Player class*/
                    break;
                }
                case 10:    //stop <N>
                {
                    int n;
                    is >> n;
                    /*Create stopShip(int n) method to Player Class and stop() to Ship class*/
                    break;
                }
                case 11:    //pirate <x> <y> <T>
                {
                    int x, y, t;
                    is >> x;
                    is >> y;
                    is >> t;
                    /*Create overloaded method addNewShip(int x, int y, int t) to Player Class*/
                    break;
                }
                case 12:    //evpos <E> <x> <y>
                {
                    int event, x, y;
                    is >> event;
                    is >> x;
                    is >> y;
                    /*Create function eventPosition(int type, int x, int y)*/
                    break;
                }
                case 13:    //evship <E> <N>
                {
                    int event, id;
                    is >> event;
                    is >> id;
                    /*Create function eventShip(int type, int id) that interacts with class Player*/
                    break;
                }
                case 14:    //coins <N>     //Should be working as intended. READY FOR BETA TESTING
                {
                    int n;
                    is >> n;
                    if(!is.good())
                        return -1;
                    
                    player->SetMoney(n);
                    break;
                }
                case 15:    //moveto <N> <x> <y> OR moveto <N> <P>
                {
                    /*No idea. Move N to (x,y) or move N to Harbor P*/
                    int id, x, y;
                    char h;
                    
                    is >> id;
                    
                    is >> x;
                    
                    if(!is.good())
                    {
                        is.clear();
                        is >> h;
                        //map->moveto(id, h);
                    }
                    else
                    {
                        is >> y;
                        //map->moveto(id, y, x);
                    }
                    
                    break;
                }
                case 16:    //buycrew <N> <S>
                {
                    int id, n;
                    is >> id;
                    is >> n;
                    
                    //Don't forget to confirm if input is ok
                    //buySoldier(int id, int n) to Player class
                    
                    break;
                }
                case 17:    //saveg <filename>
                {
                    string filename;
                    is >> filename;
                    //Save all classes state to a binary file
                    break;
                }
                case 18:    //loadg <filename>
                {
                    string filename;
                    is >> filename;
                    //Read binary file and create new class pointers. Assign new classes to existing classes
                    break;
                }
                case 19:    //delg <filename>
                {
                    string filename;
                    is >> filename;
                    /*create delete saved game function*/
                    break;
                }
                case 20:    //exit          //It's working as intended. NO MORE TESTING REQUIRED
                {
                    return 20;
                    break;
                }
                default:
                    break;
            }
            return i;
        }
    }
    
    mvwaddstr(wcmd, getmaxy(wcmd)-2, 1, lang.getLine(25));
    wclrtoeol(wcmd);
    mvwaddch(wcmd, getmaxy(wcmd)-2, getmaxx(wcmd)-1, '|');
    wrefresh(wcmd);
    
    return -1;
}

int getCenter(const char* a)
{
    int x;
    
    if(strcmp(a,"") == 0)
        return 0;
    
    string str(a);
    
    x = (getmaxx(stdscr)-strlen(str.c_str()))/2;
    
    return x;
}

int getCenter(string a)
{
    int x;
    
    x = (getmaxx(stdscr) - strlen(a.c_str()))/2;
    
    return x;
}

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