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


#ifdef __cplusplus
}
#endif

#endif /* PARAMSTRUCTS_H */

