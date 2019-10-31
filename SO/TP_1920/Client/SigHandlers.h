#ifndef SIGHANDLERS_H
#define SIGHANDLERS_H

#ifdef __cplusplus
extern "C" {
#endif
    
#include "clientHeader.h"
    
    void SIGINT_Handler(int);
    void SIGALRM_Handler(int);
    
#ifdef __cplusplus
}
#endif

#endif