#ifndef CLIENT_H
#define CLIENT_H

#ifdef __cplusplus
extern "C" {
#endif
    
#ifndef _DEFAULT_SOURCE
#define _DEFAULT_SOURCE
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <ctype.h>
#include <unistd.h>
#include <ncurses.h>
#include <curses.h>

#define MAXNAME 9
    
    //Protótipos de funções
    int edModeLoop();
    int mvModeLoop();
    
    char* preLinePrep(char* string, int stringlen, int curind);


#ifdef __cplusplus
}
#endif

#endif

