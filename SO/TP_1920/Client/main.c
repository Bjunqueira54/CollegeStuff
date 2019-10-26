#include "clientHeader.h"

//Client
int main(int argc, char** argv)
{
    if(argc != 3)
    {
        fprintf(stderr, "You need to indicate your username\n");
        fprintf(stdout, "Example usage: './client -u user1337'\n");
        exit (EXIT_FAILURE);
    }
    
    char username[25];
    
    char c = getopt(argc, argv, "u:");
    
    switch(c)
    {
        case 'u':
            fprintf(stdout,"Your username is: %s\n", optarg);
            break;
        default:
            fprintf(stderr, "I don't recognize that launch argument\n");
            exit (EXIT_FAILURE);
            break;
    }
    
    getchar();
    
    //Iniciar o ncurses
    
    initscr();
    noecho();
    keypad(stdscr, true);
    
    getch();
    
    while(!Exit)
    {
        
    }
    
    endwin();
    
    return (EXIT_SUCCESS);
}