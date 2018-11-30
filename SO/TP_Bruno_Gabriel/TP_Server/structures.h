#ifndef PARAMSTRUCTS_H
#define PARAMSTRUCTS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "server.h"
    
#define MAXLEN 15
    
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
    
    typedef struct clients
    {
        char username[MAXNAME];
        int acl;    //Active Current Line
    } Client, *pClient;


#ifdef __cplusplus
}
#endif

#endif