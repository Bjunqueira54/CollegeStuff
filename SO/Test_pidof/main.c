#define _DEFAULT_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv)
{
    FILE *f = popen("pidof bash", "r");
    char pid[19];
    fgets(pid, 19, f);
    fprintf(stdout, "%s", pid);
    
    return (EXIT_SUCCESS);
}

