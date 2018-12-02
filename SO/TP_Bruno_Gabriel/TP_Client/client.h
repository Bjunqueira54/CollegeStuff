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

#include "../medit_defaults.h"
    
    extern pid_t sv_pid;

    //Protótipos de funções
    int edModeLoop(int string_len);
    int mvModeLoop();

    char* preLinePrep(char* string, int stringlen, int curind);
    void getUsername(char* userstring);
    void invertString(char* userstring);
    void printLine(char** line, char* curline);

    void inv_user(int sig);
    void sv_connect(int sig, siginfo_t *info, void *extra);
    void sv_disconnect(int sig);

#ifdef __cplusplus
}
#endif

#endif
