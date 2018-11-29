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
#include <errno.h>

#include <pthread.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>

#include <ncurses.h>
#include <curses.h>

#include "../medit_defaults.h"
#include "structures.h"
    
    extern Settings *options;
    extern int ExitVar;

    //Protótipos de funções

    void CheckArgs(Params *p);
    void CheckOptions(Settings *a);
    void ParseEnvVars(Settings *a);
    int ParseCommands(Params *params, Settings *options, FILE *f);
    
    Client* ValidateNewClient(FILE *f, Client *c_vec, int *vec_tam, char *newcli);

#ifdef __cplusplus
}
#endif

#endif
