#ifndef TOPICS_H
#define TOPICS_H

#include "msgdist_defaults.h"

#ifdef __cplusplus
extern "C" {
#endif
    
    struct topic
    {
        char title[MAXTITLELEN];
        
        int id;

        pTopic next;
	pTopic prev;
        
        pText TextStart;
    };

#ifdef __cplusplus
}
#endif

#endif
