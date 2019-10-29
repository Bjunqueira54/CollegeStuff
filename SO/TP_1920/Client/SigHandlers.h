#ifndef SIGHANDLERS_H
#define SIGHANDLERS_H

#ifdef __cplusplus
extern "C" {
#endif
    
#include "clientHeader.h"
    
    void sigintHandler(int);
    
#ifdef __cplusplus
}
#endif

#endif