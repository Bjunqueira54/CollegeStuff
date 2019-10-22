#include <string.h>

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
    
    char c = getopt(argc, argv, "u:");
    
    switch(c)
    {
        case 'u':
            fprintf(stdout,"O teu username e: %s\n", optarg);
            break;
        default:
            fprintf(stderr, "Olha o engracadinho. Como e que entras-te aqui palhaco?\n");
            exit (EXIT_FAILURE);
            break;
    }
    
    getchar();
    
    //Iniciar o ncurses
    
    initscr();
    noecho();
    keypad(stdscr, true);
    
    getch();
    
    endwin();
    
    return (EXIT_SUCCESS);
}