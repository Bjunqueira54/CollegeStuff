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
#define SERVER_PID "/tmp/msgdist/msgdist_serverpid"
#define MSGDIST_DIR "/tmp/msgdist"
#define CMD_SIZE 30

#ifdef __cplusplus
}
#endif

#endif
