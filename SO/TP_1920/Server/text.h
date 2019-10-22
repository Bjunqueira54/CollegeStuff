#ifndef TEXT_H
#define TEXT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "serverHeader.h"

    typedef struct text
    {
        char title[15];

        char article[1000];

        int duration;

        pText prev, next;
    } Text, *pText;

#ifdef __cplusplus
}
#endif

#endif
