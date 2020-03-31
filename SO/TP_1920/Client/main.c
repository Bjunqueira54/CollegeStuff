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
    
    pid_t server_pid;
    pid_t self_pid;
    
    pthread_t notification_thread;
    Exit = false;
    pTopic TopicList = NULL;
    
    int current_topic_id = 0;
    int action;
    
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
    
    struct sigaction sigUSR1, sigUSR2, sigALRM;
    
    sigUSR1.sa_flags = SA_SIGINFO;
    
    
    sigUSR2.sa_flags = SA_SIGINFO;
    
    
    sigALRM.sa_flags = SA_SIGINFO;
    //sigALRM.sa_sigaction = &SIGALRM_Handler;
    
    signal(SIGINT, SIGINT_Handler);
    
    ////////////////////////
    ///Iniciar as Threads///
    ////////////////////////
    
    drawBox(stdscr);
    mvwaddstr(stdscr, 1, 1, "Welcome to MSGDIST!");
    wrefresh(stdscr);
    
    while(!Exit)
    {
        PrintMenu(TopicList);
        
        switch(tolower(getch()))
        {
            case 'n':
            {
                if(current_topic_id == 0)
                    newMessage(TopicList);
                else
                {
                    //How can current_topic_id not be 0 and this be NULL?
                    //You know what they say: Better safe than SegFault
                    if(TopicList == NULL)
                        newMessage(TopicList);
                    else
                    {
                        pTopic aux = TopicList;
                        
                        while(aux != NULL)
                        {
                            if(aux->id == current_topic_id)
                                newTopicMessage(aux->title);
                        }
                    }
                }
                break;
            }
            case KEY_UP:
                clear();
                mvwaddstr(stdscr, 5, 5, "I pressed Arrow Up");
                refresh();
                break;
            case KEY_DOWN:
                clear();
                mvwaddstr(stdscr, 5, 5, "I pressed Arrow Down");
                refresh();
                break;
            case KEY_RIGHT: //KEY_RIGHT and KEY_LEFT aren't used right now
                clear();
                mvwaddstr(stdscr, 5, 5, "I pressed Arrow Right");
                refresh();
                break;
            case KEY_LEFT:  //but it won't hurt to have them here just in case.
                clear();
                mvwaddstr(stdscr, 5, 5, "I pressed Arrow Left");
                refresh();
                break;
            case 10:
                clear();
                mvwaddstr(stdscr, 5, 5, "I pressed enter");
                refresh();
                break;
            case 27:
                Exit = true;
                break;
            default:
                break;
        }
    }
    
    //pthread_join(notification_thread, NULL);
    
    endwin();
    
    return (EXIT_SUCCESS);
}