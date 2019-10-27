#include "clientHeader.h"

bool Exit;

//Client
int main(int argc, char** argv)
{
    int server_pipe;
    
    /*server_pipe = open(NAMEDPIPE, O_WRONLY);
    
    if(server_pipe == -1)
    {
        fprintf(stderr, "Server is not running!\nEXITING\n");
        exit (EXIT_FAILURE);
    }*/
    
    if(argc != 3)
    {
        fprintf(stderr, "You need to indicate your username\n");
        fprintf(stdout, "Example usage: './client -u user1337'\n");
        exit (EXIT_FAILURE);
    }
    
    char username[MAXUSERLEN];
    
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
    
    pid_t selfPID = getpid();
    
    char pipestr[32];
    
    snprintf(pipestr, sizeof(char)*32, "%d\n%s", selfPID, username);

    Exit = false;

    getchar();
    
    //Iniciar o ncurses
    
    initscr();
    noecho();
    keypad(stdscr, true);
    
    getch();
    
    while(!Exit)
    {
        newNotification("Gaming");
        getch();
        ClearTestPopUp();
        getch();
    }
    
    endwin();
    
    return (EXIT_SUCCESS);
}