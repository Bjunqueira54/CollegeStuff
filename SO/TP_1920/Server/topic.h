#ifndef TOPICS_H
#define TOPICS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "serverHeader.h"
    
    struct topic
    {
        char title[15];
        
        int id;

        pTopic next;
	pTopic prev;
        
        pText start;
    };

#ifdef __cplusplus
}
#endif

#endif
