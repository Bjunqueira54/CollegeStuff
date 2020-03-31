#ifndef MSGDIST_DEFAULTS_H
#define MSGDIST_DEFAULTS_H

#ifdef __cplusplus
extern "C" {
#endif
    
#ifndef _POSIX_C_SOURCE
#define _POSIX_C_SOURCE
#endif
    
    //Add defaults values here for both Client and Server
#define MAXUSERLEN 25
#define NAMEDPIPE "/tmp/msgdist/msgdist_mainpipe"
#define CMD_SIZE 10

#ifdef __cplusplus
}
#endif

#endif
