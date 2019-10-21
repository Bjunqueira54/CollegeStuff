#ifndef TOPICS_H
#define TOPICS_H

#ifdef __cplusplus
extern "C" {
#endif
    
#include "serverHeader.h"

    typedef struct topic
    {
        char title[15];

        pText start;
    } Topic, *pTopic;

#ifdef __cplusplus
}
#endif

#endif