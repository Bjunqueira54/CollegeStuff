#ifndef CLIENT_H
#define CLIENT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../medit_defaults.h"
    
#define BUFFERSIZE 1024
#define STRING_FORM 60
    
extern char** line;

struct parameters
{
    
};

struct envvars
{
    
};

/*typedef parameters Params, *param;
typedef envvars Options, *opt;*/

void serverConnect();
void serverDisconnect(int sig);
void kThread();

void invertString(char* userString);
char* preLinePrep(char* string, int stringlen, int curind);

#ifdef __cplusplus
}
#endif

#endif /* CLIENT_H */

