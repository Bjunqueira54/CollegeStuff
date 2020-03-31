#ifndef MSGDIST_DEFAULTS_H
#define MSGDIST_DEFAULTS_H

#ifdef __cplusplus
extern "C" {
#endif
    
//Add defaults values here for both Client and Server

#define MSGDIST_DIR "/tmp/msgdist"
#define SERVER_PID "/tmp/msgdist/msgdist_serverpid"

#define MAXUSERLEN 25
#define MAXTITLELEN 15
#define MAXTEXTLEN 1000
    
#define CMD_SIZE 40

#ifdef __cplusplus
}
#endif

#endif
