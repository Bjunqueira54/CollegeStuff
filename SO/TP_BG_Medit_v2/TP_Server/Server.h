#ifndef SERVER_H
#define SERVER_H

#ifndef _DEFAULT_SOURCE
#define _DEFAULT_SOURCE
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <inttypes.h>
#include <errno.h>

#include <pthread.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>

#include <ncurses.h>
#include <curses.h>

#include "../medit_defaults.h"
#include "structures.h"
    
    extern Params *params;
    extern Options *options;
    extern int ExitVar;
    extern char** EditLines;
    extern pClient cl_vec;
    
    //Function Prototypes
    
    void ClientDisconnect();
    void ClientSignals();
    void ParseEnvVars(Options *a);
    
    void* ParseCommands();

#ifdef __cplusplus
}
#endif

#endif