#ifndef SERVER_DEFAULTS_H
#define SERVER_DEFAULTS_H

#ifdef __cplusplus
extern "C" {
#endif
    
#ifndef _POSIX_C_SOURCE
#define _POSIX_C_SOURCE
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#include <pthread.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <getopt.h>
#include <signal.h>

#include <ncurses.h>
#include <curses.h>

#define DEFAULT_DB_FILE "medit.db"
    
#define MEDIT_MAXLINES 15
#define MEDIT_MAXCOLUMNS 45
    
#define MEDIT_TIMEOUT 10
#define MEDIT_MAXUSERS 3

#define MEDIT_MAXNAME 8
    
#define MEDIT_PIPE_SIZE 25

#define MEDIT_DEFAULT_MAIN_PIPE "/tmp/medit_main_pipe"

#ifdef __cplusplus
}
#endif

#endif

