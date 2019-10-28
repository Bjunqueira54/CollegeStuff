#ifndef TOPICS_H
#define TOPICS_H

#ifdef __cplusplus
extern "C" {
#endif
    
    struct topic
    {
        char title[15];
        
        int id;

        pTopic next;
	pTopic prev;
        
        pText TextStart;
    };

#ifdef __cplusplus
}
#endif

#endif
