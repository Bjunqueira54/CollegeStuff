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
    
    extern Settings *options;
    extern Params *params;
    //extern char EditorLines[15][15+45+1];
    extern char** EditorLines;
    extern int ExitVar;
    extern int mp, cp;  //File Descriptors: Main Pipe, Client Pipes
    
    extern pClients cl_vec;

    //Protótipos de funções

    void CheckArgs(Params *p);
    void CheckOptions(Settings *a);
    void ParseEnvVars(Settings *a);
    void* ParseCommands(void* arg);
    void* MainPipeHandler(void* arg);
    void ClientDisconnect(int signal, siginfo_t *info, void* extra);
    void ClientSignals(int signal, siginfo_t *info, void* extra);
    
    void ValidateNewClient(const char* newuser, pid_t cl_pid);
    void* ActivateLine(void* arg);
    void DeleteClient(pClients client);
    void ClientDisconnect(int signal, siginfo_t *info, void* extra);
    void* WriteToClients(void* arg);

#ifdef __cplusplus
}
#endif

#endif
