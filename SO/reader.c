#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main () {

        int fd1,nr=0;
        char buf [100];

        fd1 = open ( "mypipe", O_RDONLY);
        perror("open");
        nr=read ( fd1, buf, 100 );
        perror("read");
        printf ( "%s\n", buf );
        close (fd1);
}
