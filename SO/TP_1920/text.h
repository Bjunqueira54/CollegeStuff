#ifndef TEXT_H
#define TEXT_H

#include "msgdist_defaults.h"


#ifdef __cplusplus
extern "C" {
#endif

    struct text
    {
        char title[MAXTITLELEN];
        char article[MAXTEXTLEN];

        int duration;

        pText prev;
        pText next;
        
        pTopic topic;
    };

#ifdef __cplusplus
}
#endif

#endif