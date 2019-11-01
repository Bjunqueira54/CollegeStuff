#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#ifdef __cplusplus
extern "C" {
#endif
    
#include "clientHeader.h"

    void newNotification(const char* notice_str);
    void ClearTestPopUp();
    void PrintMenu(pTopic);
    void newMessage(pTopic);
    void newTopicMessage(char*);
    
    //Arguments: WINDOW* pointer to any valid window\n
    //Returns: N/A\n
    //Function: draws '*' around the window to emulate boxing\n
    void drawBox(WINDOW*);
    
    //Arguments: WINDOW* to use; char* to write to; the number of bytes to read;
    //y coord to write to; x coord to write to; Accept Enter: true/false\n
    //Returns: -1 on error or the number of characters read (0 included)
    int getwinstr(WINDOW*, char*, int n, int y, int x);
    
#ifdef __cplusplus
}
#endif

#endif