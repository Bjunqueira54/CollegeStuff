#ifndef STRUCTURES_H
#define STRUCTURES_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../medit_defaults.h"

    typedef struct client Client, *pClient;
    typedef struct defaults Options;
    typedef struct parameters Params;
    
    struct defaults
    {
        int lines;
        int columns;
        int timeout;
        int maxusers;
    };
    
    struct parameters
    {
        int f;
        char *fname;
        
        int p;
        char *pipename;
        
        int n;
        int npipes;
    };
    
    struct client
    {
        char name[MEDIT_MAXNAME];   //Username
        int id;                     //User's ID
        int current;                //User's Current Active Editing Line
        
        pid_t cl_pid;               //User's Client Process ID
        pthread_t cl_thread;        //User's Thread
        int active_thread;          //Thread flag
        
        char *piperead;             //Client reading pipe (Server Reads from Client)
        int read;                   //Reading Pipe File Descriptor
        char *pipewrite;            //Client writing pipe (Server Writes to Client)
        int write;                  //Writing Pipe File Descriptor
        
        pClient prev;               //Previous User in the list
        pClient next;               //Next User in the list
    };

#ifdef __cplusplus
}
#endif

#endif