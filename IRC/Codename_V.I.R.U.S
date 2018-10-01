//VIRTUAL INTERCEPTING REALLITY ULTRA SUPREME
//WARNING!!!!!!!! Don't run this in your PC! It won't work ¯\_(ツ)_/¯
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define SV_IP "127.0.0.1"
#define SV_PORT 6000
#define BUFFERSIZE 4096

#define floc "/home/gothicdread/Desktop/Bandit_Passwords"

int main(int argc, char** argv)
{
    FILE *f = fopen(floc, "r");
    
    if(!floc)
    {
        fprintf(stderr, "Erro a abrir o ficheiro!\n");
        exit (EXIT_FAILURE);
    }
    
    char msg[BUFFERSIZE];
    int sockfd, msg_len;
    struct sockaddr_in sv_addr;
    
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    
    if(sockfd == -1)
    {
        fprintf(stderr, "Erro a inicar o socket! ERROR %i\n", errno);
        return (EXIT_FAILURE);
    }
    
    memset((char *) &sv_addr, 0, sizeof(sv_addr));
    
    sv_addr.sin_family = AF_INET;
    sv_addr.sin_addr.s_addr = inet_addr(SV_IP);
    sv_addr.sin_port = htons(SV_PORT);
    
    while(1)
    {
        if(fscanf(f, "%4096s", msg) == EOF)
        {
            fprintf(stdout, "Terminei a leitura!\n");
            char msg_eof[3] = "EOF";
            msg_len = sizeof(msg_eof);
            if(sendto(sockfd, msg_eof, msg_len, 0, (struct sockaddr*) &sv_addr, sizeof(sv_addr)) == -1)
            {
                fprintf(stderr, "Erro a enviar a eof! ERROR %i\n", errno);
                return (EXIT_FAILURE);
            }
            close(sockfd);
            fclose(f);
            return (EXIT_SUCCESS);
        }
        
        msg_len = sizeof(msg);
        
        if(sendto(sockfd, msg, msg_len, 0, (struct sockaddr*) &sv_addr, sizeof(sv_addr)) == -1)
        {
            fprintf(stderr, "Erro a enviar mensagem! ERROR %i", errno);
            return (EXIT_FAILURE);
        }
    }
    
    return (EXIT_SUCCESS);
}
