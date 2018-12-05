#ifndef PARAMSTRUCTS_H
#define PARAMSTRUCTS_H

#ifdef __cplusplus
extern "C" {
#endif
    
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
        char username[MAXNAME]; //Client Username
        int id;                 //Client ID
        int acl;                //Active Current Line
        
        pid_t cl_pid;           //Client Process ID
        pthread_t cl_thread;    //Client Line Editing Thread
        int active_thread;
        
        char *piperead;         //Client Named Pipe for Reading (Server reads from Client)
        int readfd;
        char *pipewrite;        //Client Named Pipe for Writting (Server writes to Client)
        int writefd;             //Client Pipe File Descriptor (for ease of access)
        
        pClients prev;
        pClients prox;
    };


#ifdef __cplusplus
}
#endif

#endif