#include "client.h"

int mode = 0; // Var. para determinar se estamos em modo de edição ou de seleção. 0=Seleção, 1=Edição, 2=Exit
char** line; 

int main(int argc, char** argv)
{
    ////////////////////////////////////////
    ///// Processamento dos argumentos /////
    ////////////////////////////////////////

    char username[MAXNAME];
    char pipename[15];
    int u=0, p=0; 

    if(argc != 1)
    {
        char c;
        while((c = getopt(argc, argv, "u:p:")) != -1)
        {
            switch(c)
            {
                case 'u':
                    u=1;
                    memcpy(username, optarg, MAXNAME*sizeof(char));
                    break;
                case 'p':
                    p=1;
                    sprintf(pipename, "/tmp/%s", optarg);
                    break;
                default:
                    fprintf(stderr, "Unknown parameters -%c\n", c);
            }
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///// Preparação das variáveis necessárias para a edição de texto /////
    ///////////////////////////////////////////////////////////////////////

    //char line[15][15+45+1]; // 15 linhas, 15 caracters de precedencia + 45 colunas + \0. Valores por defeito até ser implementada comunicação
    //char* tmp[15];
    char* curline; // Linha atual, 15 caracters de precedencia + 45 colunas + \0.
    curline = malloc((15+45+1)*sizeof(char));
    char preline[15+45+1]; // Linha antes de entrar no modo de edição
    int x, newx, y, newy;
    int c;
    
    /*for(int i=0; i<15; i++)
        tmp[i] = line[i];
    EditorLines = tmp;*/
    
    line = malloc(15*sizeof(char*));
    
    if(line == NULL)
        exit (EXIT_FAILURE);
    
    for(int i=0; i<15; i++)
    {
        line[i] = malloc((15+45)*sizeof(char));
        
        if(line[i] == NULL)
            exit (EXIT_FAILURE);
    }

    /////////////////////////////////////////////
    ///// Inicialização da string principal /////
    /////////////////////////////////////////////

    for(int y=0; y<15; y++)
    {
        for(int x=0; x<15+45; x++)
            line[y][x] = ' ';

        line[y][15+45] = '\0';
    }

    ////////////////////////////////////////////////////////////
    ///// Inicio da janela de ncurses para edição de texto /////
    ////////////////////////////////////////////////////////////

    initscr(); // inicializa ncurses
    noecho();
    keypad(stdscr, TRUE); // enable keypad input

    if(u == 0)
        getUsername(username);
    else
    {
        for(int i=strlen(username); i<MAXNAME; i++)
        {
            username[i] = ' ';
        }
    }

    ////////////////////////////////////////////////////////////////////////////////////
    /////Envia através do Main Pipe o username do cliente e fica a espera de um sinal///
    ////////////////////////////////////////////////////////////////////////////////////

    int cfd;
    struct sigaction invalid_username, sv_con, sv_disc;

    invalid_username.sa_flags = SA_SIGINFO;
    invalid_username.sa_sigaction = &inv_user;
    
    sv_con.sa_flags = SA_SIGINFO;
    sv_con.sa_sigaction = &sv_connect;
    
    sv_disc.sa_handler = &sv_disconnect;
    
    sigaction(SIGINT, &invalid_username, NULL);
    sigaction(SIGUSR1, &sv_con, NULL);
    sigaction(SIGUSR2, &sv_disc, NULL);

    if(p == 0)
        cfd = open(MEDIT_DEFAULT_MAIN_PIPE, O_WRONLY); // client file descriptor
    else
        cfd = open(pipename, O_WRONLY);

    if(cfd == -1)
    {
        endwin();
        return (EXIT_FAILURE);
    }

    pid_t cli_pid = getpid(); //client process id
    char cstring[15]; //comunication string
    char auxuser[MAXNAME];

    for(int k=0; k<MAXNAME && username[k] != ' '; k++)
    {
        auxuser[k] = username[k];
        auxuser[k+1] = '\0';
    }
    
    sprintf(cstring, "%s %lu", auxuser, (unsigned long) cli_pid);
    cstring[strlen(cstring)] = '\0';
    
    write(cfd, cstring, strlen(cstring));
    close(cfd);

    ////////////////////////////////////////////////////////////////////////////////////

    invertString(username);

    for(y=1; y<=9; y++)
    {
        curline = preLinePrep(curline, 45, y); // colocar espaçamento de username
        mvaddstr(y-1, 0, curline); // escreve string str na janela
        for(x=0; x<=15+45; x++)
            line[y-1][x] = curline[x];
    }

    for(y=10; y<=15; y++)
    {
        curline = preLinePrep(curline, 45, y);
        mvaddstr(y-1, 0, curline);
        for(x=0; x<15+45; x++)
            line[y-1][x] = curline[x];
    }
    refresh(); // refresh necessario para ncurses

    move(0, 15); // move o cursor da janela para pos (x,y)

    do
    {
        if(mode == 0) // move
        {
            mode = mvModeLoop();

            if(mode == 4)
            {
                getyx(stdscr, y, x); // busca posição (x,y) do standard screen

                for(x=0; x<=15+45; x++)
                {
                    preline[x] = line[y][x];
                }

                line[y][4] = '[';
                line[y][13] = ']';

                for(int i=0, j=5; i<MAXNAME; i++, j++)
                {
                    line[y][j] = username[i];
                }

                for(x=0; x<=15+45; x++)
                    curline[x] = line[y][x];

                mvwaddstr(stdscr, y, 0, curline);
                refresh();
                move(y, 15);

                mode = 1;
            }
            else if(mode == 2)
                break;
        }
        else if(mode == 1) // edit
        {
            mode = edModeLoop(45);

            if(mode >= 32 && mode <= 126)
            {
                getyx(stdscr, y, x); // busca posição (x,y) do standard screen
                newx = x;
                newy = y;
                
                if(line[y][15+45-1] == ' ')
                {
                    for(x=(15+45-1); x>newx; x--)
                    {
                        line[y][x] = line[y][x-1];
                    }

                    line[y][newx] = mode;
                    write(sv_fd, (char*) &mode, sizeof(char));
                    move(newy, newx+1);
                }

                mode = 1;
            }
            if(mode == 3)
            {
                getyx(stdscr, y, x); //busca posição (x,y) do standard screen
                newx=x; //guarda a pos atual
                newy=y;
                
                line[y][15+45] = ' '; //A pos onde estava o '\0' passa a ser um espaço

                for(;x<=15+45; x++) //Ciclo para mover...
                {
                    line[y][x-1] = line[y][x];  //... todos os caracteres da linha 1 pos. a esquerda
                }

                line[y][15+45] = '\0';  //repõe o '\0' no final da linha;
                
                write(sv_fd, "\b", sizeof(char));
                move(newy, newx-1); //move o cursor uma pos. a esquerda
                mode = 1; //continua no modo de edição
            }
            else if(mode == 5)
            {
                getyx(stdscr, y, x); // busca posição (x,y) do standard screen
                for(x=0; x<=15+45; x++)
                {
                        line[y][x] = preline[x];
                }
                write(sv_fd, "\r", sizeof(char));
                mode = 0;
            }
            else if(mode == 6)
            {
                getyx(stdscr, y, x);
                
                for(x=4; x<14; x++)
                    line[y][x] = ' ';
                
                write(sv_fd, "\n", sizeof(char));
                mode = 0;
            }

            getyx(stdscr, y, x); // busca posição (x,y) do standard screen
            newx=x;
            newy=y;
            for(y=0; y<15; y++)
            {
                for(x=0; x<=15+45; x++)
                {
                    curline[x] = line[y][x];
                }
                mvwaddstr(stdscr, y, 0, curline); // escreve na posição atual do cursor (linha atual)
            }
            move(newy, newx);
        }
        refresh(); // refresh necessario para ncurses
    }
    while(mode != 2); // Enquanto a tecla premida não for ESC

    free(curline);

    kill(sv_pid, SIGUSR1);
    pthread_kill(sv_recv_thread, SIGINT);
    pthread_join(sv_recv_thread, NULL);
    
    for(int i=0; i<15; i++)
        free(line[i]);
    free(line);
    
    endwin(); // fecha a janela do ncurses e devolve o controlo ao terminal original
    close(sv_fd);

    return (EXIT_SUCCESS);
}

