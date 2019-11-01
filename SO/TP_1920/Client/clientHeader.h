#ifndef CLIENTHEADER_H
#define CLIENTHEADER_H

#ifndef _DEFAULT_SOURCE
#define _DEFAULT_SOURCE
#endif

#ifdef __cplusplus
extern "C" {
#endif
    
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <signal.h>
#include <getopt.h>
#include <string.h>
#include <stdbool.h>
#include <fcntl.h>
#include <pthread.h>
#include <ncurses.h>
    
#include "../typedefines.h"
    
#include "../msgdist_defaults.h"
#include "../topic.h"
#include "../text.h"
    
#include "Functions.h"
#include "SigHandlers.h"
#include "ThreadHandlers.h"
    
    extern bool Exit;

#ifdef __cplusplus
}
#endif

#endif