#ifndef CLIENTS_H
#define CLIENTS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "serverHeader.h"

    struct client
    {
        char username[8];
        
        pid_t c_PID;

        //array\listaLigada (?) de subscriçoes
    };

#ifdef __cplusplus
}
#endif

#endif
