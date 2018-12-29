#include "Interface.h"

#if (defined _WIN32 || defined __unix__) && !(defined __linux__)
#include "Consola.h"
#endif

vector <string> Interface::cmd;
vector <string> Interface::line;
vector <string> Interface::tutorial;

Interface::Interface(char lang) 
{
    if(lang == '1')
    {
        //commands
        {
            cmd.push_back("config");    //0
            cmd.push_back("exec");      //1
            cmd.push_back("prox");      //2
            cmd.push_back("compranav"); //3
            cmd.push_back("vendenav");  //4
            cmd.push_back("lista");     //5
            cmd.push_back("compra");    //6
            cmd.push_back("vende");     //7
            cmd.push_back("move");      //8
            cmd.push_back("auto");      //9
            cmd.push_back("stop");      //10
            cmd.push_back("pirata");    //11
            cmd.push_back("evpos");     //12
            cmd.push_back("evnav");     //13
            cmd.push_back("moedas");    //14
            cmd.push_back("vaipara");   //15
            cmd.push_back("comprasold");//16
            cmd.push_back("saveg");     //17
            cmd.push_back("loadg");     //18
            cmd.push_back("delg");      //19
            cmd.push_back("sair");      //20
        }
        
        //lines
        { 
            line.push_back("(Prima qualquer tecla para continuar)");    //0
            line.push_back("Bem vindo a Into the Horizon!");		//1
            line.push_back("1 - Novo Jogo");                            //2
            line.push_back("2 - Tutorial");                             //3
            line.push_back("3 - Creditos");                             //4
            line.push_back("4 - Sair do Jogo");                         //5
            line.push_back("Introduza o seu nome (20 chars.)");		//6
            line.push_back("Nome: ");                                   //7
            line.push_back("Nome invalido!");                           //8
            line.push_back("Bem vindo ");                               //9
            line.push_back("Boa Sorte Capitao ");                       //10
            line.push_back("Turno ");                                   //11
            line.push_back("Comando: ");                                //12
            line.push_back("Comando não especificado");                 //13
            line.push_back("Comando Reconhecido");                      //14
            line.push_back("Tutorial");                                 //15
            line.push_back("Creditos");                                 //16
            line.push_back("Obrigado por jogar!");                      //17
            line.push_back("Programadores:");                           //18
            line.push_back("Equipa de Controlo de Qualidade:");         //19
            line.push_back("Comando não existe");                       //20
            line.push_back("Ficheiro não existe");                      //21
            line.push_back("Abrir o ficheiro de defeito?(S/N)");        //22
            line.push_back("Criar um ficheiro de config?(S/N)");        //23
            line.push_back("Valores por defeito/Seus valores?(D/C)");   //24
            line.push_back("Comando inválido");                         //25
            line.push_back("Ficheiro aberto: ");                        //26
            line.push_back("Fase ");                                    //27
            line.push_back("Nome do ficheiro: ");                       //28
            line.push_back("Deseja desenhar o mapa?(S/N)");             //29
            line.push_back("Moedas iniciais: ");                        //30
            line.push_back("Probabilidade de Piratas por turno: ");     //31
            line.push_back("Preço por Navio: ");                        //32
            line.push_back("Preço por Soldado: ");                      //33
            line.push_back("Preço do peixe: ");                         //34
            line.push_back("Preço de compra da mercadoria: ");          //35
            line.push_back("Preço de venda da mercadoria: ");           //36
            line.push_back("Soldados por porto: ");                     //37
            line.push_back("Probabilidade de evento: ");                //38
            line.push_back("Probabilidade de Tempestade: ");            //39
            line.push_back("Probabilidade de Sereias: ");               //40
            line.push_back("Probabilidade de Calmaria: ");              //41
            line.push_back("Probabilidade de Motim: ");                 //42
            line.push_back("(Se escolher 'N' será criado um por si)");  //43
            line.push_back("Dimensões: 10 Linha / 20 Colunas");         //44
            line.push_back("Janela do mapa. Enter para terminar");      //45
            line.push_back("Obrigado por Jogar!");                      //46
            line.push_back("Nome do Jogador: ");                        //47
            line.push_back("Dinheiro do Jogador: ");                    //48
            line.push_back("Tamanho da frota do Jogador: ");            //49
        }
        
        //tutorial
        { 
            tutorial.push_back("Tutorial"); //0
            tutorial.push_back("Comandos Basicos:"); //1
            tutorial.push_back("Comandos Avançados:"); //2
            tutorial.push_back("Objetivos do Jogo:"); //3
            tutorial.push_back("config <NomeFicheiro> - Le as carateristicas do mapa e paramentros do ficheiro"); //4
            tutorial.push_back("exec <NomeFicheiro> - Le comando do ficheiro e executa-os"); //5
            tutorial.push_back("prox - Avancar um turno"); //6
            tutorial.push_back("compranav <T> - Compra um navio do tipo T especificado"); //7
            tutorial.push_back("vendenav <T> - Vende um navio do tipo T especificado"); //8
            tutorial.push_back("lista - Listar precos em cada porto"); //9
            tutorial.push_back("compra <N> <M> - Compra M toneladas de mercadoria para o navio N"); //10
            tutorial.push_back("vende <N> - Vende toda a carga e mercadoria do navio N"); //11
            tutorial.push_back("move <N> <X> - Move o navio N para a posicao X = (D-Direita, E-Esquerda, C-Cima, B-Baixo)"); //12
            tutorial.push_back("auto <N> - Coloca o navio N em auto-gestao"); //13
            tutorial.push_back("stop <N> - Interrompe o comportamento de auto-gestao do navio N"); //14
            tutorial.push_back("pirata <x> <y> <T> - Cria um navio pirata do tipo T nas coordenadas (x,y)"); //15
            tutorial.push_back("evpos <E> <x> <y> - Cria um evento E = (T-Tempestade, C-Calmaria) na posicao (x,y) "); //16
            tutorial.push_back("evnav <E> <N> - Cria um evento E = (S-Sereias, M-Motim) no navio N"); //17
            tutorial.push_back("moedas <N> - Acrescenta N moedas ao jogador"); //18
            tutorial.push_back("vaipara <N> <x> <y> - Move o navio N na direcao das coordenadas (x,y)"); //19
            tutorial.push_back("vaipara <N> <P> - Move o navio N em direcao ao porto P"); //20
            tutorial.push_back("comprasold <N> <S> - Compra soldados S para o navio N"); //21
            tutorial.push_back("saveg <nome> - Salva o progresso do jogo com um nome"); //22
            tutorial.push_back("loadg <nome> - Recupera o jogo previamento guardado com o nome"); //23
            tutorial.push_back("delg <nome> - Apaga a copia do jogo guardado como nome"); //24
            tutorial.push_back("sair - Sai do jogo e volta para o menu principal"); //25
            tutorial.push_back("Pag. 1/4"); //26
            tutorial.push_back("Pag. 2/4"); //27
            tutorial.push_back("Pag. 3/4"); //28
            tutorial.push_back("Pag. 4/4"); //29
        //falta terceira pagina
        }
    }
    else if(lang == '2')
    {
        //commands
        {
            cmd.push_back("config");
            cmd.push_back("exec");
            cmd.push_back("next");
            cmd.push_back("buyship");
            cmd.push_back("sellship");
            cmd.push_back("list");
            cmd.push_back("buy");
            cmd.push_back("sell");
            cmd.push_back("move");
            cmd.push_back("auto");
            cmd.push_back("stop");
            cmd.push_back("pirate");
            cmd.push_back("evpos");
            cmd.push_back("evship");
            cmd.push_back("coins");
            cmd.push_back("goto");
            cmd.push_back("buycrew");
            cmd.push_back("saveg");
            cmd.push_back("loadg");
            cmd.push_back("delg");
            cmd.push_back("exit");
        }
        
        //lines
        {
            line.push_back("(Press any key to continue)");
            line.push_back("Welcome to Into the Horizon!");
            line.push_back("1 - New Game");
            line.push_back("2 - Tutorial");
            line.push_back("3 - Credits");
            line.push_back("4 - Exit Game");
            line.push_back("Enter your name (20 chars.): ");
            line.push_back("Name: ");
            line.push_back("Invalid name!");
            line.push_back("Welcome ");
            line.push_back("Good Luck Captain ");
            line.push_back("Turn ");
            line.push_back("Command: ");
            line.push_back("Command not specified");
            line.push_back("Command Recognized");
            line.push_back("Tutorial");
            line.push_back("Credits");
            line.push_back("Thanks for playing!");
            line.push_back("Programmers:");
            line.push_back("Game Testing Team:");
            line.push_back("Command doesn't exist");
            line.push_back("File doesn't exist");
            line.push_back("Open the default file?(Y/N)");
            line.push_back("Create a config file?(Y/N)");
            line.push_back("Default Values/Custom Values? (D/C)");
            line.push_back("Invalid command");
            line.push_back("Loaded file: ");
            line.push_back("Phase ");
            line.push_back("File name: ");
            line.push_back("Draw map?(Y/N)");
            line.push_back("Starting coins: ");
            line.push_back("Pirate chance per turn: ");
            line.push_back("Ship price: ");
            line.push_back("Crew price: ");
            line.push_back("Fish price: ");
            line.push_back("Cargo buy price: ");
            line.push_back("Cargo sell price: ");
            line.push_back("Harbor soldiers: ");
            line.push_back("Event chance: ");
            line.push_back("Storm chance: ");
            line.push_back("Siren chance: ");
            line.push_back("Calm chance: ");
            line.push_back("Riot chance: ");
            line.push_back("(If you choose 'N' we'll use the default)");
            line.push_back("Dimensions: 10 Lines / 20 Columns");
            line.push_back("Map window. Enter to terminate");
            line.push_back("Thanks for Playing!");
            line.push_back("Player's Name: ");
            line.push_back("Player's Gold: ");
            line.push_back("Fleet size: ");
        }
        
        //tutorial
        {
            tutorial.push_back("Tutorial");
            tutorial.push_back("Basic Commands:");
            tutorial.push_back("Advanced Commands:");
            tutorial.push_back("Game Objectives:");
            tutorial.push_back("config <FileName> - Reads the map caracteristics and parameter from the file");
            tutorial.push_back("exec <FileName> - Reads file commands and executes them");
            tutorial.push_back("next - Next turn");
            tutorial.push_back("buyship <T> Buys a ship of type T specified");
            tutorial.push_back("sellship <T> - Sells a ship of type T specified");
            tutorial.push_back("list - Lists prices in each harbor");
            tutorial.push_back("buy <N> <M> - Buys M tons of merchandise for ship N");
            tutorial.push_back("sell <N> - Sells all the merchandise of ship N");
            tutorial.push_back("move <N> <X> - Moves ship N to position X = (R-Right, L-Left, U-Up, D-Down)"); 
            tutorial.push_back("auto <N> - Puts ship N on auto mode");
            tutorial.push_back("stop <N> - Interrupts the auto mode of ship N");
            tutorial.push_back("pirate <x> <y> <T> - Spawns a new pirate ship of type T in coordinates (x,y)");
            tutorial.push_back("evpos <E> <x> <y> - Spawns a new event E = (S-Storm, C-Calm) in coordinates (x,y)");
            tutorial.push_back("evship <E> <N> - Spawns a new event E = (M-Mermaids, R-Riot) on ship N");
            tutorial.push_back("coins <N> - Adds N coins to the player");
            tutorial.push_back("goto <N> <x> <y> - Move ship N towards coordinates (x,y)");
            tutorial.push_back("goto <N> <P> - Move ship N towards harbor P");
            tutorial.push_back("buycrew <N> <S> - Buys S crew to ship N");
            tutorial.push_back("saveg <name> - Saves game in progress with the name");
            tutorial.push_back("loadg <name> - Loads game previously saves with the name");
            tutorial.push_back("delg <name> - Deletes game with the name");
            tutorial.push_back("exit - quits game and returns to the main menu");
            tutorial.push_back("Page 1/4");
            tutorial.push_back("Page 2/4");
            tutorial.push_back("Page 3/4");
            tutorial.push_back("Page 4/4");
        }
    }
    else
	exit (EXIT_FAILURE);
}

Interface::Interface(const Interface& orig) {}

void Interface::drawBox(WINDOW *win)
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

void Interface::drawMainMenu()
{
    int y=0, esp, r, extra, i=10;
    esp = Interface::getVertCenter(stdscr, 4, r, extra);
    
    y+=(esp+r);
    mvwaddstr(stdscr, ++y, i, line[2].c_str());
    y+=esp;
    mvwaddstr(stdscr, ++y, i, line[3].c_str());
    y+=esp;
    mvwaddstr(stdscr, ++y, i, line[4].c_str());
    y+=esp;
    mvwaddstr(stdscr, ++y, i, line[5].c_str());
    
    //just for fun
    ostringstream con;
    con << "Beta: " << GAME_VERSION_MAJOR << "." << GAME_VERSION_MINOR;
    mvwaddstr(stdscr, getmaxy(stdscr) - 2, getmaxx(stdscr) - strlen(con.str().c_str()) - 1, con.str().c_str());
    refresh();
}

const char* Interface::getCmd(int i)
{
    return cmd[i].c_str();
}

const char* Interface::getLine(int i)
{
    return line[i].c_str();
}

void Interface::tutPage()
{
    int i=6, l=5;
    
    //page 1
    {
        mvwaddstr(stdscr, 2, 3, tutorial[0].c_str());
        mvwaddstr(stdscr, 4, 3, tutorial[1].c_str());
        mvwaddstr(stdscr, ++++l, i, tutorial[6].c_str());
        mvwaddstr(stdscr, ++++l, i, tutorial[22].c_str());
        mvwaddstr(stdscr, ++++l, i, tutorial[23].c_str());
        mvwaddstr(stdscr, ++++l, i, tutorial[24].c_str());
        mvwaddstr(stdscr, ++++l, i, tutorial[25].c_str());
        mvwaddstr(stdscr, getmaxy(stdscr)-2, getmaxx(stdscr)-10, tutorial[26].c_str());
        refresh();
        getch();
    }

    //page 2
    { 
        l=5;
        drawBox(stdscr);
        mvwaddstr(stdscr, 2, 3, tutorial[0].c_str());
        mvwaddstr(stdscr, 4, 3, tutorial[2].c_str());
        mvwaddstr(stdscr, ++++l, i, tutorial[4].c_str());
        mvwaddstr(stdscr, ++++l, i, tutorial[5].c_str());
        mvwaddstr(stdscr, ++++l, i, tutorial[7].c_str());
        mvwaddstr(stdscr, ++++l, i, tutorial[8].c_str());
        mvwaddstr(stdscr, ++++l, i, tutorial[9].c_str());
        mvwaddstr(stdscr, ++++l, i, tutorial[10].c_str());
        mvwaddstr(stdscr, ++++l, i, tutorial[11].c_str());
        mvwaddstr(stdscr, ++++l, i, tutorial[12].c_str());
        mvwaddstr(stdscr, ++++l, i, tutorial[13].c_str());  
        mvwaddstr(stdscr, getmaxy(stdscr)-2, getmaxx(stdscr)-10, tutorial[27].c_str());
        refresh();
        getch();
    }
    
    //page 3
    {
        l=5;
        drawBox(stdscr);
        mvwaddstr(stdscr, 2, 3, tutorial[0].c_str());
        mvwaddstr(stdscr, 4, 3, tutorial[2].c_str());     
        mvwaddstr(stdscr, ++++l, i, tutorial[14].c_str());
        mvwaddstr(stdscr, ++++l, i, tutorial[15].c_str());
        mvwaddstr(stdscr, ++++l, i, tutorial[16].c_str());
        mvwaddstr(stdscr, ++++l, i, tutorial[17].c_str());
        mvwaddstr(stdscr, ++++l, i, tutorial[18].c_str());
        mvwaddstr(stdscr, ++++l, i, tutorial[19].c_str());
        mvwaddstr(stdscr, ++++l, i, tutorial[20].c_str());
        mvwaddstr(stdscr, ++++l, i, tutorial[21].c_str());
        mvwaddstr(stdscr, getmaxy(stdscr)-2, getmaxx(stdscr)-10, tutorial[28].c_str());
        refresh();
        getch();
    }

    //page 4 (incomplete)
    {
        l=5;
        drawBox(stdscr);
        mvwaddstr(stdscr, 2, 3, tutorial[0].c_str());
        mvwaddstr(stdscr, 4, 3, tutorial[3].c_str());
        mvwaddstr(stdscr, getmaxy(stdscr)-2, getmaxx(stdscr)-10, tutorial[29].c_str());
        refresh();
        getch();
    }
}
    
void Interface::credPage()
{
    int i=6, l=2;
    
    mvwaddstr(stdscr, 2, 3, line[18].c_str());
    mvwaddstr(stdscr, ++++l, i, "Bruno Junqueira (Back-end Developer)");
    mvwaddstr(stdscr, ++++l, i, "Gabriel Gomes (Front-end Developer)");
    
    l=10;
    mvwaddstr(stdscr, 10, 3, line[19].c_str());
    mvwaddstr(stdscr, ++++l, i, "Kostas Makridis");
    mvwaddstr(stdscr, ++++l, i, "Cassandra Dimas");
    refresh();
    getch();
}

void Interface::startgame()
{
    int r, flag, y;
    string name;
    clear();
    drawBox(stdscr);
    y = getVertCenter(stdscr, 2, r, flag);
    do
    {
        if(y != 0)
        {
            if(flag == 0)
                mvwaddstr(stdscr, r+y, getCenter(getLine(6)), getLine(6));
            else
                mvwaddstr(stdscr, r+y+1, getCenter(getLine(6)), getLine(6));
        }
        else
            mvwaddstr(stdscr, r, getCenter(getLine(6)), getLine(6));

        if(y != 0)
        {
            if(flag == 0)
                mvwaddstr(stdscr, r+y+2, getCenter(getLine(7)) - 10, getLine(7));
            else
                mvwaddstr(stdscr, r+y+2, getCenter(getLine(7)) - 10, getLine(7));
        }
        else
            mvwaddstr(stdscr, r+y+2, getCenter(getLine(7)) - 10, getLine(7));
    
	name = getInput(stdscr, 15);
    }
    while(name.empty());
    
    drawGameArea();
    game = new Game(name);
}

int Interface::configPhase()
{
    string cmdstring, parse, filename;
    ifstream file;
    int inv=0;
    char c;
    
    do
    {
        istringstream is;
        drawBox(wcmd);
        
        if(inv == 1)
            mvwaddstr(wcmd, getmaxy(wcmd)-2, 1, getLine(25));
        
        inv = 0;
        
        do
        {
            mvwaddstr(wcmd, getmaxy(wcmd)-3, 1, getLine(12));
            wrefresh(wcmd);
            cmdstring = getInput(wcmd, 25);
        }
        while(cmdstring.empty());

        is.str(cmdstring);
        is >> parse;
        
        if(parse != getCmd(0) && parse != getCmd(20))
        {
            inv = 1;
            continue;
        }
        
        if(parse == getCmd(0))
        {
            parse.clear();
            is >> parse;
            
            if(!parse.empty() || !is.bad())
            {
                file.open(parse, ios::in);
                
                if(!file.is_open())
                {
                    mvwaddstr(wcmd, getmaxy(wcmd)-2, 1, getLine(21));
                    wclrtoeol(wcmd);
                    mvwaddch(wcmd, getmaxy(wcmd)-2, getmaxx(wcmd)-1, '|');
                    wrefresh(wcmd);
                    
                    getch();
                    mvwaddstr(wcmd, getmaxy(wcmd)-2, 1, getLine(22));
                    wclrtoeol(wcmd);
                    mvwaddch(wcmd, getmaxy(wcmd)-2, getmaxx(wcmd)-1, '|');
                    wrefresh(wcmd);
                    do
                    {
                        c = getch();
                    }
                    while(c!='S' && c!='s' && c!='N' && c!='n' && c!='Y' && c!='y');
                    
                    if(c=='S'||c=='s'||c=='Y'||c=='y')
                    {
                        filename = "config.ini";
                        file.open(filename);
                        
                        if(!file.is_open())
                        {
                            mvwaddstr(wcmd, getmaxy(wcmd)-2, 1, getLine(21));
                            wclrtoeol(wcmd);
                            mvwaddch(wcmd, getmaxy(wcmd)-2, getmaxx(wcmd)-1, '|');
                            wrefresh(wcmd);
                            getch();
                            
                            mvwaddstr(wcmd, getmaxy(wcmd)-2, 1, getLine(23));
                            wclrtoeol(wcmd);
                            mvwaddch(wcmd, getmaxy(wcmd)-2, getmaxx(wcmd)-1, '|');
                            wrefresh(wcmd);
                            
                            do
                            {
                                c = getch();
                            }
                            while(c!='S' && c!='s' && c!='N' && c!='n' && c!='Y' && c!='y');
                            
                            if(c=='S'||c=='s'||c=='Y'||c=='y')
                            {
                                filename = createDefaultConfig();
                                file.open(filename);
                                
                                if(!file.is_open())
                                {
                                    mvwaddstr(wcmd, getmaxy(wcmd)-2, 1, "PLACEHOLDER! UNDEFINED ERROR!");
                                    return -1;
                                }
                            }
                            else
                                return -1;
                        }
                    }
                    else
                    {
                        mvwaddstr(wcmd, getmaxy(wcmd)-2, 1, getLine(23));
                        wclrtoeol(wcmd);
                        mvwaddch(wcmd, getmaxy(wcmd)-2, getmaxx(wcmd)-1, '|');
                        wrefresh(wcmd);
                        
                        do
                        {
                            c = getch();
                        }
                        while(c!='S' && c!='s' && c!='N' && c!='n' && c!='Y' && c!='y');
                        
                        if(c=='S'||c=='s'||c=='Y'||c=='y')
                        {
                            filename = createDefaultConfig();
                            
                            file.open(filename);
                                
                            if(!file.is_open())
                            {
                                mvwaddstr(wcmd, getmaxy(wcmd)-2, 1, "PLACEHOLDER! UNDEFINED ERROR!");
                                return -1;
                            }
                        }
                        else
                            return -1;
                    }
                }

                game->configPhase(file);
                file.close();
            }
            
            break;
        }
        else if(parse == getCmd(20))
            return -1;
    }
    while(parse != getCmd(0));
}

void Interface::MainGameLoop()
{
    int cmdval;
    string cmd;

    if(configPhase() == -1)
        return;
    
    game->startGame();
    
    do
    {
        drawBox(wcmd);
        drawMap();
        printStats();
        turncmd.clear();
        ostringstream g_turn;
        g_turn << getLine(11) << game->getTurn();
        
        mvwaddstr(wcmd, 1, 1, g_turn.str().c_str());
        
        do
        {
            wmove(wcmd, getmaxy(wcmd)-3, 1);
            wclrtoeol(wcmd);
            mvwaddch(wcmd, getmaxy(wcmd)-3, getmaxx(wcmd)-1, '|');
            mvwaddstr(wcmd, getmaxy(wcmd)-3, 1, getLine(12));
            wrefresh(wcmd);
            
            do
            {
                cmd = getInput(wcmd, 25);
            }
            while(cmd.empty());
            
            cmdval = parseCmd(cmd, 0);
            
            if(cmdval == -1)
                mvwaddstr(wcmd, getmaxy(wcmd)-2, 1, getLine(25));
            else
            {
                turncmd.push_back(cmd);
            }
            
            for(int i=turncmd.size()-1, j=(getmaxy(wcmd) - 4); i >= 0 && j >= 2; i--, j--)
            {
                mvwaddstr(wcmd, j, 1, turncmd[i].c_str());
                wclrtoeol(wcmd);
                mvwaddch(wcmd, j, getmaxx(wcmd)-1, '|');
            }
            wrefresh(wcmd);
        }
        while(cmdval != 20 && cmdval != 2);
        
        //change to next turn after this
        for(int i=0; i<turncmd.size(); i++)
            parseCmd(turncmd[i], 1);
        
        game->nextTurn();
    }
    while(cmdval != 20);
}

int Interface::parseCmd(string c, bool exec)
{
    int i, retval;
    istringstream is;
    string parse;
    is.str(c);

    is >> parse;

    for(i = 0; i<cmd.size(); i++)
        if(parse == cmd[i])
            break;
    
    switch(i)
    {
        case 0:
            return -1;
        case 1:
        {
            parse.clear();
            is >> parse;
            
            ifstream file;
            file.open(parse, ios::in);
            
            if(file.is_open())
                return openExecFile(file);
            else
                return -2;
        }
        case 2:
            return 2;
        case 3:
        {
            if(exec == false)
                return 0;
            
            char t;
            
            is >> t;
            
            if(game->getPlayerMoney() > game->getShipPrice())
                retval = game->PlayerBuyShip(t);
            
            return retval;
        }
        case 4:
        {
            if(exec == false)
                return 0;
            
            int id, retval;
            
            is >> id;
            
            if(id != 0)
                retval = game->PlayerSellShip(id);
            
            return retval;
        }
        case 5:
        {
            int wi = 1;
            ostringstream os;
            drawBox(wstats);
            os << getLine(32) << game->getShipPrice();
            mvwaddstr(wstats, wi++, 1, os.str().c_str());
            os.str("");
            os.clear();
            os << getLine(33) << game->getCrewPrice();
            mvwaddstr(wstats, wi++, 1, os.str().c_str());
            os.str("");
            os.clear();
            os << getLine(34) << game->getFishPrice();
            mvwaddstr(wstats, wi++, 1, os.str().c_str());
            os.str("");
            os.clear();
            os << getLine(35) << game->getCargoBuyPrice();
            mvwaddstr(wstats, wi++, 1, os.str().c_str());
            os.str("");
            os.clear();
            os << getLine(36) << game->getCargoSellPrice();
            mvwaddstr(wstats, wi++, 1, os.str().c_str());
            wrefresh(wstats);
            
            getch();
            
            drawBox(wstats);
            printStats();
            
            return 0;
        }
        case 6:
            if(exec == false)
                return 0;
            
            return 0;
        case 7:
            if(exec == false)
                return 0;
            
            return 0;
        case 8:
        {
            if(exec == false)
                return 0;
            
            int id;
            string dir;
            
            is >> id;
            is >> dir;
            
            if(id == 0 || dir == "")
                return -1;
            
            retval = game->PlayerShipMove(id, dir);
            
            return retval;
        }
        case 9:
            if(exec == false)
                return 0;
            
            return 0;
        case 10:
            if(exec == false)
                return 0;
            
            return 0;
        case 11:
            if(exec == false)
                return 0;
            
            return 0;
        case 12:
            if(exec == false)
                return 0;
            
            return 0;
        case 13:
            if(exec == false)
                return 0;
            
            return 0;
        case 14:
            if(exec == false)
                return 0;
            
            int m;
            
            is >> m;
            
            if(m != 0)
                game->PlayerAddMoney(m);
            
            return 0;
        case 15:
            if(exec == false)
                return 0;
            
            return 0;
        case 16:
            if(exec == false)
                return 0;
            
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 20;
        default:
            return -1;
    }
}

int Interface::openExecFile(ifstream& file)
{
    string input;
    int retval;
    
    while(!file.eof() && retval != 2 && retval != 20)
    {
        getline(file, input);
        
        retval = parseCmd(input, 0);
    }
    
    if(file.eof())
        return 0;
    else
        return retval;
}

int Interface::drawMap()
{
    //Color Initialization
    init_color(LAND_DARK, COLOR_CONVERTER(135), COLOR_CONVERTER(65), COLOR_CONVERTER(15));
    init_color(LAND_LIGHT, COLOR_CONVERTER(220), COLOR_CONVERTER(180), COLOR_CONVERTER(135));
    
    init_color(FRIENDLY, COLOR_CONVERTER(0), COLOR_CONVERTER(255), COLOR_CONVERTER(0));
    init_color(UNFRIENDLY, COLOR_CONVERTER(255), COLOR_CONVERTER(0), COLOR_CONVERTER(0));
    
    init_color(COLOR_SAILBOAT, COLOR_CONVERTER(255), COLOR_CONVERTER(255), COLOR_CONVERTER(255));
    init_color(COLOR_GALEON, COLOR_CONVERTER(255), COLOR_CONVERTER(255), COLOR_CONVERTER(0));
    init_color(COLOR_SCHOONER, COLOR_CONVERTER(165), COLOR_CONVERTER(165), COLOR_CONVERTER(165));
    init_color(COLOR_FRIGATE, COLOR_CONVERTER(255), COLOR_CONVERTER(102), COLOR_CONVERTER(0));
    init_color(COLOR_SPECIAL, COLOR_CONVERTER(153), COLOR_CONVERTER(0), COLOR_CONVERTER(204));
    
    
    //Pair creation
    
    //Ocean Tiles
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    init_pair(2, COLOR_WHITE, COLOR_CYAN);

    //Land Tiles
    init_pair(3, COLOR_WHITE, LAND_DARK);
    init_pair(4, COLOR_WHITE, LAND_LIGHT);
    
    //Harbor Tiles
    init_pair(5, COLOR_BLACK, FRIENDLY);
    init_pair(6, COLOR_WHITE, UNFRIENDLY);
    
    //Ship Colors
    init_pair(7, COLOR_BLACK, COLOR_SAILBOAT);
    init_pair(8, COLOR_BLACK, COLOR_GALEON);
    init_pair(9, COLOR_BLACK, COLOR_SCHOONER);
    init_pair(10, COLOR_BLACK, COLOR_FRIGATE);
    init_pair(11, COLOR_WHITE, COLOR_SPECIAL);
    
    init_pair(TERM_DEFAULT, COLOR_WHITE, COLOR_BLACK);
    
    wattron(wmap, COLOR_PAIR(TERM_DEFAULT));

    wclear(wmap);
    drawBox(wmap);
    
    if(game->getPhase() != 1)
        return -1;
    
    bool ls, toggler = false;
    int maxx, maxy;
    istringstream is;
    
    is.str(game->getMapDim());
    is >> maxy;
    is >> maxx;
    
    //Quick verification if map dimensions go over the map window's dimensions.
    if((maxy * 2) > getmaxy(wmap))
        return -1;
    if((maxx * 2) > getmaxx(wmap))
        return -1;
    
    //Step 1: Draw land tiles in every position on the map with a checkered color patern.
    for(int y=1; y<maxy+1; y++)
    {
        ls = toggler;
        
        for(int x=1; x<maxx+1; x++)
        {
            if(toggler == false)
            {
                wattron(wmap, COLOR_PAIR(3));
                toggler = !toggler;
            }
            else
            {
                wattron(wmap, COLOR_PAIR(4));
                toggler = !toggler;
            }
            
            mvwaddch(wmap, y*2, x*2, ' ');
            mvwaddch(wmap, y*2, x*2-1, ' ');
            mvwaddch(wmap, y*2-1, x*2, ' ');
            mvwaddch(wmap, y*2-1, x*2-1, ' ');
        }

        if(toggler == ls)
            toggler = !toggler;
    }

    //Step 2: Draw all of the existant ocean tiles given by the Game class.
    int y, x, prevy;
    for(int i=0; i<game->getTotalOceanTiles(); i++)
    {
        is.clear();
        is.str(game->getOceanCoord(i));
        
        is >> y;
        is >> x;
        
        if(y != prevy)
        {
            if(toggler == ls)
                toggler = !toggler;
            
            ls = toggler;
            prevy = y;
        }
        
        if(toggler == false)
        {
            wattron(wmap, COLOR_PAIR(1));
            toggler = !toggler;
        }
        else
        {
            wattron(wmap, COLOR_PAIR(2));
            toggler = !toggler;
        }
        
        mvwaddch(wmap, y*2, x*2, ' ');
        mvwaddch(wmap, y*2, x*2-1, ' ');
        mvwaddch(wmap, y*2-1, x*2, ' ');
        mvwaddch(wmap, y*2-1, x*2-1, ' ');
    }
    
    //Step 3: Draw all of the existing harbors, colored correctly depending on their "friendliness".
    for(int i=0; i<game->getTotalHarborTiles(); i++)
    {
        is.clear();
        is.str(game->getHarborCoord(i));
        
        is >> y;
        is >> x;
        
        if(game->harborIsFriendly(i) == true)
        {
            wattron(wmap, COLOR_PAIR(5));
        }
        else
        {
            wattron(wmap, COLOR_PAIR(6));
        }

        mvwaddch(wmap, y*2-1, x*2-1, game->getHarborID(i));
        mvwaddch(wmap, y*2-1, x*2, ' ');
        mvwaddch(wmap, y*2, x*2, ' ');
        mvwaddch(wmap, y*2, x*2-1, ' ');
    }
    
    //Step 4: Draw all the existing player fleet, along with marking which of the existing harbors
    //          is his main harbor.
    for(int i=0; i<game->getPlayerFleetSize(); i++)
    {
        if(game->getPlayerShipInHarbor(i))
            continue;
        
        string id;
        
        is.clear();
        is.str(game->getPlayerShipCoord(i));
        
        is >> y;
        is >> x;
        
        switch(game->getPlayerShipType(i))
        {
            case 1:
                wattron(wmap, COLOR_PAIR(7));
                break;
            case 2:
                wattron(wmap, COLOR_PAIR(8));
                break;
            case 3:
                wattron(wmap, COLOR_PAIR(9));
                break;
            case 4:
                wattron(wmap, COLOR_PAIR(10));
                break;
            case 5:
                wattron(wmap, COLOR_PAIR(11));
                break;
        }
        
        id = game->getPlayerShipID(i);
        
        mvwaddch(wmap, y*2-1, x*2-1, id[0]);
        mvwaddch(wmap, y*2-1, x*2, id[1]);
        mvwaddch(wmap, y*2, x*2-1, '+');
        mvwaddch(wmap, y*2, x*2, '+');
    }
    
    is.clear();
    is.str(game->getPlayerMainHarbor()->getCoord());
    is >> y;
    is >> x;
    wattron(wmap, COLOR_PAIR(5));
    mvwaddch(wmap, y*2-1, x*2, '*');
    
    wrefresh(wmap);
    return 0;
}

string Interface::getInput(WINDOW *win, int lim = 0)
{
    string input;
    char c;
    int y,x;
    
    getyx(win, y, x);
    
    do
    {
	c = getch();
	
	if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == ' ' || c == '.'))
        {
	    if(input.size() <= lim && lim > 0)
		input.push_back(c);
        }
	else if((c == 127 || c == 8) && !(input.empty()))
        {
	    input.pop_back();
            wclrtoeol(win);
        }
	
	mvwaddstr(win, y, x, input.c_str());
        mvwaddch(win, y, x + input.size(), '_');
	wclrtoeol(win);
	mvwaddch(win, y, getmaxx(win) - 1, '|');
	wmove(win, y, x + input.size() + 1);
	wrefresh(win);
    }
    while(c != '\n');

    return input;
}

int Interface::getNumber(WINDOW *win, int lim = 0)
{
    string num;
    istringstream is;
    char c;
    int n;
    int y,x;
    
    getyx(win, y, x);
    
    do
    {
	if(c >= '0' && c <= '9')
            if(num.size() <= lim && lim > 0)
                num.push_back(c);
	else if((c == 127) && !(num.empty()))
	    num.pop_back();
	
	mvwaddstr(win, y, x, num.c_str());
        mvwaddch(win, y, x + num.size(), '_');
	wclrtoeol(win);
	mvwaddch(win, y, getmaxx(win) - 1, '|');
	wmove(win, y, x + num.size());
	wrefresh(win);
    }
    while(c != '\n');
    
    is.str(num);
    is >> n;
    
    return n;
}

int Interface::getCenter(const char* a)
{
    int x;
    
    if(strcmp(a,"") == 0)
        return 0;
    
    string str(a);
    
    x = (getmaxx(stdscr)-strlen(str.c_str()))/2;
    
    return x;
}

int Interface::getCenter(string a)
{
    int x;
    
    x = (getmaxx(stdscr) - strlen(a.c_str()))/2;
    
    return x;
}

int Interface::getVertCenter(WINDOW *win, int n, int &r, int &flag)
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
            flag = 0;
            return esp;
        }
        else
        {
            flag = 1;
            return esp;
        }
    }
    else
    {
        flag = 0;
        return esp;
    }
}

void Interface::drawGameArea()
{
    wmap = subwin(stdscr, 22, 42, 0, 0);
    wcmd = subwin(stdscr, 18, 42, getmaxy(wmap), 0);
    wlog = subwin(stdscr, MAX_Y, MAX_X-getmaxx(wmap), 0, getmaxx(wmap));
    wstats = subwin(stdscr, MAX_Y, MAX_X-getmaxx(wmap), 0, getmaxx(wmap));
    drawBox(wmap);
    drawBox(wcmd);
    drawBox(wstats);
}

void Interface::SetScreenSize(int lines, int columns)
{
#if (defined __linux__ || defined __unix__) && !(defined _WIN32)
    
    std::ostringstream syscmd;
    syscmd << "\e[8;" << lines << ";" << columns << "t";
    std::cout << syscmd.str();
    
#elif (defined _WIN32) && !(defined __linux__ || defined __unix__)

    Consola::setScreenSize(lines, columns);
    
#endif
}

void Interface::endgame()
{
    delete game;
    delwin(wcmd);
    delwin(wlog);
    delwin(wmap);
    delwin(wstats);
    clear();
    mvwaddstr(stdscr, getmaxy(stdscr) / 2, getCenter(getLine(17)), getLine(17));
    wrefresh(stdscr);
    getch();
}

void Interface::printStats()
{
    int i=1;
    
    ostringstream os;
    os << getLine(47) << game->getPlayerName();
    mvwaddstr(wstats, i++, 1, os.str().c_str());
    os.str("");
    os.clear();
    os << getLine(48) << game->getPlayerMoney();
    mvwaddstr(wstats, i++, 1, os.str().c_str());
    os.str("");
    os.clear();
    os << getLine(49) << game->getPlayerFleetSize();
    mvwaddstr(wstats, i++, 1, os.str().c_str());
    
    wrefresh(wstats);
}

string Interface::createDefaultConfig()
{
    char c;
    ofstream file;
    string filename, input;
    
    mvwaddstr(wcmd, getmaxy(wcmd)-2, 1, getLine(24));
    wclrtoeol(wcmd);
    mvwaddch(wcmd, getmaxy(wcmd)-2, getmaxx(wcmd)-1, '|');
    wrefresh(wcmd);
    
    do
    {
        c = getch();
    }
    while(c!='D' && c!='d' && c!='C' && c!='c');
    
    if(c == 'D' || c == 'd')
    {
        filename = "config.ini";
        
        file.open(filename, ios::out | ios::trunc);
        
        if(!file.is_open())
            return "";
        
        file << "lines 10" << endl;
        file << "columns 20" << endl;
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
        file << "startmoney 1000" << endl;
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
        
        file.close();
        
        return filename;
    }
    else if(c == 'C' || c == 'c')
    {
        mvwaddstr(wstats, 1, 1, getLine(28));
        wrefresh(wstats);
        do
        {
            filename = getInput(wstats, 15);
        }
        while(filename.empty());
        
        mvwaddch(wstats, getcury(wstats), getcurx(wstats)-1, ' ');
        
        file.open(filename, ios::out | ios::trunc);
        
        mvwaddstr(wstats, 2, 1, getLine(29));
        mvwaddstr(wstats, 3, 1, getLine(43));
        wrefresh(wstats);
        
        do
        {
            c = getch();
        }
        while(c!='Y' && c!='y' && c!='S' && c!='s' && c!='N' && c!='n');

        if(c=='Y' || c=='y' || c=='S' || c=='s')
        {
            vector<string> g_map;
            g_map = userDrawCustomMap();
            
            file << "lines 10" << endl;
            file << "columns 20" << endl;
            
            for(int i=0; i<=g_map.size(); i++)
                file << g_map[i] << endl;
        }
        else
        {
            file << "lines 10" << endl;
            file << "columns 20" << endl;
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
        }
        
        wmove(wstats, 4, 1);
        wclrtoeol(wstats);
        mvwaddch(wstats, 4, getmaxx(wstats)-1, '|');
        mvwaddstr(wstats, 4, 1, getLine(30));
        wrefresh(wstats);
        do
        {
            input = getNumber(wstats, 10);
        }
        while(input.empty());
        mvwaddch(wstats, getcury(wstats), getcurx(wstats)-1, ' ');
        file << "startmoney " << input << endl;
        
        mvwaddstr(wstats, 5, 1, getLine(31));
        wrefresh(wstats);
        do
        {
            input = getNumber(wstats, 3);
        }
        while(input.empty());
        mvwaddch(wstats, getcury(wstats), getcurx(wstats)-1, ' ');
        file << "pirateprob  " << input << endl;
        
        mvwaddstr(wstats, 6, 1, getLine(32));
        wrefresh(wstats);
        do
        {
            input = getNumber(wstats, 5);
        }
        while(input.empty());
        mvwaddch(wstats, getcury(wstats), getcurx(wstats)-1, ' ');
        file << "shipprice " << input << endl;
        
        mvwaddstr(wstats, 7, 1, getLine(33));
        wrefresh(wstats);
        do
        {
            input = getNumber(wstats, 5);
        }
        while(input.empty());
        mvwaddch(wstats, getcury(wstats), getcurx(wstats)-1, ' ');
        file << "crewprice " << input << endl;
        
        mvwaddstr(wstats, 8, 1, getLine(34));
        wrefresh(wstats);
        do
        {
            input = getNumber(wstats, 10);
        }
        while(input.empty());
        mvwaddch(wstats, getcury(wstats), getcurx(wstats)-1, ' ');
        file << "fishprice " << input << endl;
        
        mvwaddstr(wstats, 9, 1, getLine(35));
        wrefresh(wstats);
        do
        {
            input = getNumber(wstats, 10);
        }
        while(input.empty());
        mvwaddch(wstats, getcury(wstats), getcurx(wstats)-1, ' ');
        file << "cargobuy " << input << endl;
        
        mvwaddstr(wstats, 10, 1, getLine(36));
        wrefresh(wstats);
        do
        {
            input = getNumber(wstats, 10);
        }
        while(input.empty());
        mvwaddch(wstats, getcury(wstats), getcurx(wstats)-1, ' ');
        file << "cargosell " << endl;
        
        mvwaddstr(wstats, 11, 1, getLine(37));
        wrefresh(wstats);
        do
        {
            input = getNumber(wstats, 10);
        }
        while(input.empty());
        mvwaddch(wstats, getcury(wstats), getcurx(wstats)-1, ' ');
        file << "harborcrew " << input << endl;
        
        mvwaddstr(wstats, 12, 1, getLine(38));
        wrefresh(wstats);
        do
        {
            input = getNumber(wstats, 10);
        }
        while(input.empty());
        mvwaddch(wstats, getcury(wstats), getcurx(wstats)-1, ' ');
        file << "eventprob " << input << endl;
        
        mvwaddstr(wstats, 13, 1, getLine(39));
        wrefresh(wstats);
        do
        {
            input = getNumber(wstats, 10);
        }
        while(input.empty());
        mvwaddch(wstats, getcury(wstats), getcurx(wstats)-1, ' ');
        file << "stormprob " << input << endl;
        
        mvwaddstr(wstats, 14, 1, getLine(40));
        wrefresh(wstats);
        do
        {
            input = getNumber(wstats, 10);
        }
        while(input.empty());
        mvwaddch(wstats, getcury(wstats), getcurx(wstats)-1, ' ');
        file << "sirenprob " << input << endl;
        
        mvwaddstr(wstats, 15, 1, getLine(41));
        wrefresh(wstats);
        do
        {
            input = getNumber(wstats, 10);
        }
        while(input.empty());
        mvwaddch(wstats, getcury(wstats), getcurx(wstats)-1, ' ');
        file << "calmprob " << input << endl;
        
        mvwaddstr(wstats, 16, 1, getLine(42));
        wrefresh(wstats);
        do
        {
            input = getNumber(wstats, 10);
        }
        while(input.empty());
        mvwaddch(wstats, getcury(wstats), getcurx(wstats)-1, ' ');
        file << "riotprob " << input << endl;
        
        drawBox(wstats);
        
        file.close();
        
        return filename;
    }
}

vector<string> Interface::userDrawCustomMap()
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
    
    mvwaddstr(wlog, 3, 1, getLine(43));
    mvwaddstr(wlog, 4, 1, getLine(45));
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

Interface::~Interface() {}