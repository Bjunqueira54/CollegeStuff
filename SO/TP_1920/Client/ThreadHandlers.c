#include "ThreadHandlers.h"

void *NotificationThreadHandle(void* arg)
{
    int max = 5;
    int min = 1;
    
    while(!Exit)
    {
        int time = (int) (rand() % (max - min + 1)) + min;
        
        newNotification("Gaming!");
        
        sleep(time);
    }
    
    return NULL;
}