#ifndef CLIENT_H
#define CLIENT_H

#ifdef __cplusplus
extern "C" {
#endif
    
#ifndef _DEFAULT_SOURCE
#define _DEFAULT_SOURCE
#endif

#include "../medit_defaults.h"
    
#define BUFFERSIZE 1024
#define STRING_FORM 60
    
extern char** line;

struct parameters
{
    int a;
};

struct envvars
{
    int a;
};

typedef struct parameters Params, *param;
typedef struct envvars Options, *opt;

void serverConnect(int sig);
void serverDisconnect(int sig);
void invUser();
void kThread();


#ifdef __cplusplus
}
#endif

#endif /* CLIENT_H */

