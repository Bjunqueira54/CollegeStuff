#include "Language.h"
#include "Functions.h"

vector <string> Language::cmd;
vector <string> Language::line;
vector <string> Language::tutorial;

Language::Language(int lang)
{
    if(lang == 1)
    {
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
        
        {
            line.push_back("(Prima qualquer tecla para continuar)");    //0
            line.push_back("Bem vindo a Piratas e Mercadores!");        //1
            line.push_back("1 - Novo Jogo");                            //2
            line.push_back("2 - Tutorial");                             //3
            line.push_back("3 - Creditos");                             //4
            line.push_back("4 - Sair do Jogo");                         //5
            line.push_back("Introduza o seu nome (20 chars.): ");       //6
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
            line.push_back("Abrir o ficheiro de defeito?(Y/N)");        //22
            line.push_back("Criar um ficheiro de defeito?(Y/N)");       //23
            line.push_back("Valores por defeito/Seus valores?(D/C)");   //24
            line.push_back("Comando inválido");                         //25
            line.push_back("Ficheiro aberto: ");                        //26
            line.push_back("Fase ");                                    //27
            line.push_back("Nome do ficheiro: ");                       //28
            line.push_back("Desenha desenhar o mapa?(Y/N)");            //29
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
        }
        
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
            tutorial.push_back("Pag. 1/3"); //26
            tutorial.push_back("Pag. 2/3"); //27
            tutorial.push_back("Pag. 3/3"); //28
        //falta terceira pagina
        }
    }
    else if(lang == 2)
    {
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
        
        {
            line.push_back("(Press any key to continue)");
            line.push_back("Welcome to Merchants and Pirates!");
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
            line.push_back("Create a default file?(Y/N)");
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
        }
        
        {//spellcheck - X
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
            tutorial.push_back("Page 1/3");
            tutorial.push_back("Page 2/3");
            tutorial.push_back("Page 3/3");
        }
    }
}

vector<string> Language::getCmdvec() const
{
    return cmd;
}

vector<string> Language::getLinevec() const
{
    return line;
}

const char* Language::getCmd(int i)
{
    return cmd[i].c_str();
}

const char* Language::getLine(int i)
{
    return line[i].c_str();
}

void Language::tutPage()
{
    int i=5;
    
    { //page 1
        mvwaddstr(stdscr, 2, 3, tutorial[0].c_str());
        mvwaddstr(stdscr, 4, 3, tutorial[1].c_str());
        mvwaddstr(stdscr, 6, i, tutorial[6].c_str());
        mvwaddstr(stdscr, 7, i, tutorial[22].c_str());
        mvwaddstr(stdscr, 8, i, tutorial[23].c_str());
        mvwaddstr(stdscr, 9, i, tutorial[24].c_str());
        mvwaddstr(stdscr, 10, i, tutorial[25].c_str());
        mvwaddstr(stdscr, getmaxy(stdscr)-2, getmaxx(stdscr)-10, tutorial[26].c_str());
        refresh();
        getch();
    }
    
    drawBox(stdscr);
    { //page 2
        mvwaddstr(stdscr, 2, 3, tutorial[0].c_str());
        mvwaddstr(stdscr, 4, 3, tutorial[2].c_str());
        mvwaddstr(stdscr, 6, i, tutorial[4].c_str());
        mvwaddstr(stdscr, 7, i, tutorial[5].c_str());
        mvwaddstr(stdscr, 8, i, tutorial[7].c_str());
        mvwaddstr(stdscr, 9, i, tutorial[8].c_str());
        mvwaddstr(stdscr, 10, i, tutorial[9].c_str());
        mvwaddstr(stdscr, 11, i, tutorial[10].c_str());
        mvwaddstr(stdscr, 12, i, tutorial[11].c_str());
        mvwaddstr(stdscr, 13, i, tutorial[12].c_str());
        mvwaddstr(stdscr, 14, i, tutorial[13].c_str());
        mvwaddstr(stdscr, 15, i, tutorial[14].c_str());
        mvwaddstr(stdscr, 16, i, tutorial[15].c_str());
        mvwaddstr(stdscr, 17, i, tutorial[16].c_str());
        mvwaddstr(stdscr, 18, i, tutorial[17].c_str());
        mvwaddstr(stdscr, 19, i, tutorial[18].c_str());
        mvwaddstr(stdscr, 20, i, tutorial[19].c_str());
        mvwaddstr(stdscr, 21, i, tutorial[20].c_str());
        mvwaddstr(stdscr, 22, i, tutorial[21].c_str());
        mvwaddstr(stdscr, getmaxy(stdscr)-2, getmaxx(stdscr)-10, tutorial[27].c_str());
        refresh();
        getch();
    }

    drawBox(stdscr);
    { //page 3 (incompleto)
        mvwaddstr(stdscr, 2, 3, tutorial[0].c_str());
        mvwaddstr(stdscr, 4, 3, tutorial[3].c_str());
        mvwaddstr(stdscr, getmaxy(stdscr)-2, getmaxx(stdscr)-10, tutorial[28].c_str());
        refresh();
        getch();
    }
}

void Language::credPage()
{
    mvwaddstr(stdscr, 2, 3, line[18].c_str());
    mvwaddstr(stdscr, 4, 10, "Bruno Junqueira (Back-end Developer)");
    mvwaddstr(stdscr, 5, 10, "Gabriel Gomes (Front-end Developer)");
    
    mvwaddstr(stdscr, 10, 3, line[19].c_str());
    mvwaddstr(stdscr, 12, 10, "Kostas Makridis");
    mvwaddstr(stdscr, 13, 10, "Cassandra Dimas");
    refresh();
    getch();
}