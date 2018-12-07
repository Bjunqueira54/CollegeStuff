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
    
#define BUFFERSIZE 1024
    
    extern pid_t sv_pid;
    extern pthread_t sv_recv_thread;
    extern int mode, sv_fd;
    extern char** line;
    
    static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

    //Protótipos de funções
    int edModeLoop(int string_len);
    int mvModeLoop();

    char* preLinePrep(char* string, int stringlen, int curind);
    void getUsername(char* userstring);
    void invertString(char* userstring);
    void printLine(char** line, char* curline);

    void inv_user(int sig, siginfo_t *info, void *extra);
    void sv_connect(int sig, siginfo_t *info, void *extra);
    void sv_disconnect(int sig);
    
    void* GetPageFromServer(void* arg);

#ifdef __cplusplus
}
#endif

#endif
