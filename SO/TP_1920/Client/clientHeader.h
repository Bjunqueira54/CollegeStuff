#ifndef CLIENTHEADER_H
#define CLIENTHEADER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <ncurses.h>
#include <sys/types.h>
#include <string.h>
#include <signal.h>
#include <stdbool.h>
#include <fcntl.h>
#include <pthread.h>
    
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