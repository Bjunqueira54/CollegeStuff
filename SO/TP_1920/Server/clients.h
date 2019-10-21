#ifndef CLIENTS_H
#define CLIENTS_H

#ifdef __cplusplus
extern "C" {
#endif
    
#include "serverHeader.h"
    
    typedef struct clients
    {
        char username[8];
        
        //array\listaLigada (?) de subscriçoes
    } Client, *pClient;

#ifdef __cplusplus
}
#endif

#endif