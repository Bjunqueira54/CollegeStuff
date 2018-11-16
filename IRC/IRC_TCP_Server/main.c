#include <irc_includes.h>

#define SV_PORT 6000
#define BUFFERSIZE 4096

void ServClient(int sockfd)
{
    char msg[BUFFERSIZE];
    int msg_len, sentbytes;
    
    fprintf(stdout, "Entrei na funcao ServClient\n");
    
    msg_len = recv(sockfd, msg, sizeof(msg), 0);
    
    int opt = 1;
    
    switch(msg_len)
    {
        case -1:
            fprintf(stderr, "recv: ERROR %i\n", errno);
            return;
            break;
        case 0:
            fprintf(stdout, "No message recieved\n");
            return;
            break;
        default:
            msg[msg_len] = '\0';
            fprintf(stdout, "<Client> %s\n", msg);
            snprintf(msg, BUFFERSIZE, "%i", msg_len);
            msg_len = strlen(msg);
            
            if((sentbytes = send(sockfd, msg, msg_len, 0)) == -1)
            {
                fprintf(stderr, "send: ERROR %i", errno);
            }
            else if(sentbytes < msg_len)
            {
                fprintf(stderr, "send: sentbytes < msg_len");
            }
            else
            {
                fprintf(stdout, "OK!\n");
            }
            
            return;
    }
}

int main(int argc, char** argv)
{
    int sockfd, newsock, cl_addr_len;
    struct sockaddr_in sv_addr, cl_addr;
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    if(sockfd == -1)
    {
        fprintf(stderr, "socket: ERROR %i", errno);
        close(sockfd);
        exit (EXIT_FAILURE);
    }
    
    memset((char*) &sv_addr, 0, sizeof(sv_addr));
    
    sv_addr.sin_family = AF_INET;
    sv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    sv_addr.sin_port = htons(SV_PORT);
    
    if(bind(sockfd, (struct sockaddr*) &sv_addr, sizeof(sv_addr)) == -1)
    {
        fprintf(stderr, "bind: ERROR %i", errno);
        close(sockfd);
        exit (EXIT_FAILURE);
    }
    
    if(listen(sockfd, 5) == -1)
    {
        fprintf(stderr, "listen: ERROR %i", errno);
        close(sockfd);
        exit (EXIT_FAILURE);
    }
    
    cl_addr_len = sizeof(cl_addr);
    
    while(1)
    {
        newsock = accept(sockfd, (struct sockaddr*) &cl_addr, &cl_addr_len);
        
        if(newsock == -1)
        {
            fprintf(stderr, "accept: ERROR %i", errno);
        }
        else
        {
            ServClient(newsock);
            close(newsock);
        }
    }
    
    return (EXIT_SUCCESS);
}

