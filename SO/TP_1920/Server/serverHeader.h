#ifndef SERVERHEADER_H
#define SERVERHEADER_H

extern int maxMessages;
typedef struct text Text, *pText;
typedef struct topic Topic, *pTopic;
typedef struct client Client, *pClient;

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include "clients.h"
#include "topics.h"
#include "text.h"

#endif