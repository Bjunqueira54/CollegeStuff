#include "ThreadHandlers.h"

void NotificationThreadHandle(void*)
{
    while(!Exit)
    {
        int time = (rand() % (20 - 5 + 1)) + 5;
        
        newNotification("Gaming!");
        
        sleep(time);
    }
    
    pthread_exit(0);
}