#include <irc_includes.h>

#define SV_PORT 6000
#define BUFFERSIZE 4096

int main(int argc, char** argv)
{
    char msg[BUFFERSIZE];
    int sockfd, msg_len;
    struct sockaddr_in sv_addr;
    
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    
    if(sockfd == -1)
    {
        fprintf(stderr, "Erro no sock fd\n");
        return EXIT_FAILURE;
    }
    
    memset((char*) &sv_addr, 0, sizeof(sv_addr));
    
    sv_addr.sin_family = AF_INET;
    sv_addr.sin_port = htons(SV_PORT);
    sv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    if(bind(sockfd, (struct sockaddr*) &sv_addr, sizeof(sv_addr)) == -1)
    {
        fprintf(stderr, "Erro no bind\n");
        return (EXIT_FAILURE);
    }
    
    fprintf(stdout, "Waiting for Client...\n\n");
    
    while(1)
    {
        msg_len = recvfrom(sockfd, msg, sizeof(msg), 0, NULL, NULL);
        
        if(msg_len == -1)
        {
            fprintf(stderr, "Erro a receber mensagem\n");
        }
        else
        {
            fprintf(stdout, "<CLIENT> %s", msg);
        }
    }
    return (EXIT_SUCCESS);
}