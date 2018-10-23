#ifndef MEDIT_DEFAULTS_H
#define MEDIT_DEFAULTS_H

#ifdef __cplusplus
extern "C" {
#endif
    
#include "server.h"

#define MEDIT_MAXLINES 15
#define MEDIT_MAXCOLUMNS 45
    
#define MEDIT_TIMEOUT 10
#define MEDIT_MAXUSERS 3
    
    typedef struct Defaults
    {
        int lines, columns, timeout, maxusers;
    } Settings;

#ifdef __cplusplus
}
#endif

#endif

