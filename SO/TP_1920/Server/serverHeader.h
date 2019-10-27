#ifndef SERVERHEADER_H
#define SERVERHEADER_H

#ifndef _DEFAULT_SOURCE
#define _DEFAULT_SOURCE
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <inttypes.h>
#include <errno.h>

#include <pthread.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>

#include "../typedefines.h" //MUST BE INCLUDED FIRST
typedef struct client Client, *pClient;

#include "../msgdist_defaults.h"
#include "../topic.h"
#include "../text.h"
#include "client.h"
#include "serverInterface.h"

extern int maxMessages;
extern bool Exit;
extern bool Filter;

bool serverMainLoop(char *cmd, char *opt, pClient aux);

#endif