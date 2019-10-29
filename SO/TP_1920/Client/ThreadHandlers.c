#include "ThreadHandlers.h"

void NotificationThreadHandle(void*)
{
    while(!Exit)
    {
        
    }
    
    pthread_exit(0);
}