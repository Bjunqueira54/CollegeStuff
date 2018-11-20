#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main (){
        char * phrase = "Stuff this in your pipe and smoke it";
        int fd1, nw=0;
        fd1 = open ( "mypipe", O_WRONLY | O_NONBLOCK);
        perror("open");
        nw = write (fd1, phrase, strlen ( phrase)+1 );
        perror("write");
        close (fd1);
}
