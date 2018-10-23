#ifndef SERVER_H
#define SERVER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <ctype.h>
#include <unistd.h>
    
#include "paramstructs.h"
#include "paramstructs.h"
#include "medit_defaults.h"
#include "server_defaults.h"

    //Protótipos de funções
    
    void CheckArgs(Params *p);
    void CheckOptions(Settings *a);
    void ParseEnvVars(Settings *a);

#ifdef __cplusplus
}
#endif

#endif /* SERVER_H */

