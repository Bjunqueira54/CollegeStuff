#ifndef PIPEFUNCTIONS_H
#define PIPEFUNCTIONS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "clientHeader.h"
    
    void SendTextToServer(char*, pText);
    
    void RecieveTopicFromServer();
    void RecieveTextFromServer();

#ifdef __cplusplus
}
#endif

#endif