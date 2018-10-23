#define _DEFAULT_SOURCE

#include "server.h"

int main(int argc, char** argv)
{
    char processid[6];
    
    FILE *pExists = popen("pidof medit_server", "r");
    fgets(processid, 6, pExists);
    pid_t pid = strtoul(processid, NULL, 10);
    pclose(pExists);
    
    if(pid != 0)
    {
        fprintf(stderr, "Another server already exists on the system.\nEXITING!");
        return (EXIT_FAILURE);
    }
    
    Params params;
    params.f = 0;
    params.n = 0;
    params.p = 0;
    
    FILE *f;
    char c;
    
    if(argc != 1)
    {
        while((c = getopt(argc, argv, "f:n:p:")) != -1)
        {
            switch(c)
            {
                case 'f':
                    params.f = 1;
                    params.fname = optarg;
                    break;
                case 'n':
                    params.n = 1;
                    fprintf(stdout, "I still do not know how to use -%c\n", c);
                    break;
                case 'p':
                    params.p = 1;
                    fprintf(stdout, "I still do not know how to use -%c\n", c);
                    break;
                default:
                    fprintf(stderr, "Unknown parameter -%c\n", c);
            }
        }
    }
    
    Settings options;
    
    ParseEnvVars(&options);
    
    if(params.f == 1)
    {
        f = fopen(params.fname, "a+t");
    }
    else
    {
        f = fopen(DEFAULT_DB_FILE, "a+t");
    }
    
    char cmd[10];
    
    while(1)
    {
        fprintf(stdout, "Command: ");
        fscanf(stdin, "%s", cmd);
        
        for(int i=0; i<strlen(cmd); i++)
        {
            cmd[i] = tolower(cmd[i]);
        }
        
        if(strcmp(cmd, "settings") == 0)
        {
            CheckArgs(&params);
            CheckOptions(&options);
        }
        else if(strcmp(cmd, "shutdown") == 0)
        {
            fclose(f);
            
            return (EXIT_SUCCESS);
        }
        else
        {
            fprintf(stderr, "Unknown command!\n");
        }
    }
}