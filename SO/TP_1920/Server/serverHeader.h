#ifndef SERVERHEADER_H
#define SERVERHEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdbool.h>

#include "typedefines.h" //MUST BE INCLUDED FIRST

#include "client.h"
#include "topic.h"
#include "text.h"

extern int maxMessages;
extern bool Exit;

#endif