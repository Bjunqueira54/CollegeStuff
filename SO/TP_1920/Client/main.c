#include "clientHeader.h"

bool Exit;

//Client
int main(int argc, char** argv)
{
    if(argc != 3)
    {
        fprintf(stderr, "You need to indicate your username\n");
        fprintf(stdout, "Example usage: './client -u user1337'\n");
        exit (EXIT_FAILURE);
    }
    
    char username[MAXUSERLEN];
    *username = 0;
    
    char c = getopt(argc, argv, "u:");
    
    switch(c)
    {
        case 'u':
            memcpy(username, optarg, strlen(optarg));
            fprintf(stdout,"Your username is: %s\n", username);
            break;
        default:
            fprintf(stderr, "I don't recognize that launch argument\n");
            exit (EXIT_FAILURE);
            break;
    }
    
    if(*username == 0)
    {
        fprintf(stderr, "You didn't specify a username!\nEXITING!\n");
        exit (EXIT_FAILURE);
    }

    ////////////////////////////////
    ///Iniciar todas as variaveis///
    ////////////////////////////////
    
    int server_pid;
    pthread_t notification_thread;
    Exit = false;
    pTopic TopicList = NULL;
    
    ///////////////////////
    ///Iniciar o ncurses///
    ///////////////////////
    
    initscr();              //Inicia a janela principal 'stdscr' do ncurses
    start_color();          //Liga as cores
    noecho();               //Desliga o echo'ing de characteres
    curs_set(0);            //Desliga o piscar do cursor no terminal
    keypad(stdscr, true);   //Liga o keypad
    
    ////////////////////////////////////
    ///Iniciar o tratamento do sinais///
    ////////////////////////////////////
    
    signal(SIGINT, sigintHandler);
    
    ////////////////////////
    ///Iniciar as Threads///
    ////////////////////////
    
    pthread_create(&notification_thread, NULL, NotificationThreadHandle, NULL);
    
    init_pair(10, COLOR_GREEN, COLOR_RED);
    wattron(stdscr, COLOR_PAIR(10));
    mvwaddstr(stdscr, 1, 1, "Test from main()");
    wrefresh(stdscr);
    
    while(!Exit)
    {
        
    }
    
    pthread_join(notification_thread, NULL);
    
    endwin();
    
    return (EXIT_SUCCESS);
}