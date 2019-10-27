#ifndef TEXT_H
#define TEXT_H

#ifdef __cplusplus
extern "C" {
#endif

    struct text
    {
        char title[15];
        char topicTitle[15];
        char article[1000];

        int duration;

        pText prev, next;
        pTopic topic;
    };

#ifdef __cplusplus
}
#endif

#endif