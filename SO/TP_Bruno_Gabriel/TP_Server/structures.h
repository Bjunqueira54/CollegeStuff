#ifndef PARAMSTRUCTS_H
#define PARAMSTRUCTS_H

#ifdef __cplusplus
extern "C" {
#endif

//#include "server.h"
    
#define MAXLEN 15
    
    typedef struct clients Clients, *pClients;
    
    typedef struct parameters
    {
        int f;
        char* fname;
        
        int p;
        char *pname;
        
        int n, npipes;
    } Params;
    
    typedef struct Defaults
    {
        int lines, columns, timeout, maxusers;
    } Settings;
    
    struct clients
    {
        char username[MAXNAME];
        int id;
        int acl;    //Active Current Line
        pClients prev;
        pClients next;
    };


#ifdef __cplusplus
}
#endif

#endif