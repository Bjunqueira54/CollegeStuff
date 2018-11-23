#include <irc_includes.h>

#define BUFFERSIZE 4096
#define SV_PORT 1337

void ServClient(int sockfd);
int writeN(int sockfd, char* msg, int nbytes);
int readLine(int sockfd, char* msg, int nbytes);

int main(int argc, char** argv)
{
    int sockfd, newsock, cl_addr_len;
    struct sockaddr_in sv_addr, cl_addr;
    
    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    
    if(sockfd == -1)
    {
        fprintf(stderr, "ERROR SOCKET %i", errno);
        close(sockfd);
        exit (EXIT_FAILURE);
    }
    
    memset((char*) &sv_addr, 0, sizeof(sv_addr));
    
    sv_addr.sin_family = AF_INET;
    sv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    sv_addr.sin_port = htons(SV_PORT);
    
    if(bind(sockfd, (struct sockaddr*) &sv_addr, sizeof(sv_addr)) == -1)
    {
        fprintf(stderr, "BIND ERROR %i", errno);
        close(sockfd);
        exit (EXIT_FAILURE);
    }
    
    if(listen(sockfd, 5) == -1)
    {
        fprintf(stderr, "LISTEN ERROR %i", errno);
        close(sockfd);
        exit (EXIT_FAILURE);
    }
    
    cl_addr_len = sizeof(cl_addr);
    
    while(1)
    {
        newsock = accept(sockfd, (struct sockaddr*) &cl_addr, &cl_addr_len);
        if(newsock == -1)
        {
            fprintf(stderr, "Error accepting cliente\n");
        }
        else
        {
            ServClient(newsock);
            close(newsock);
        }
    }
    return (EXIT_SUCCESS);
}

void ServClient(int sockfd)
{
    static char msg[BUFFERSIZE];
    static unsigned int cont = 0;
    int nbytes, nsent;
    
    nbytes = readLine(sockfd, msg, BUFFERSIZE);
    
    switch(nbytes)
    {
        case -1:
            fprintf(stderr, "READLINE ERROR %i\n", errno);
            return;
        case 0:
            fprintf(stderr, "NO DATA!\n");
            return;
        default:
            msg[nbytes]='\0';
            fprintf(stdout, "<CLIENT %i> %s\n", ++cont, msg);
            
            fprintf(stdout, "<SERVER> Sending confirmation\n");
            sprintf(msg, "%i", nbytes);
            nbytes = strlen(msg);
            
            nsent = writeN(sockfd, msg, nbytes);
            
            if(nsent == -1)
                fprintf(stderr, "<SERVER> ERROR CONFIRMING");
            else if(nsent < nbytes)
                fprintf(stderr, "<SERVER> CONFIRMED BUT TRUNCATED\n");
            else
                fprintf(stdout, "<SERVER> CONFIRMED!\n");
    }
}

int writeN(int sockfd, char* msg, int nbytes)
{
    int nLeft, nWritten;
    
    nLeft = nbytes;
    
    while(nLeft > 0)
    {
        nWritten = send(sockfd, msg, sizeof(msg), 0);
        
        if(nWritten == -1 || nWritten == 0)
            return (nWritten);
        
        nLeft -= nWritten;
        msg += nWritten;
    }
}

int readLine(int sockfd, char* msg, int nbytes)
{
    int nread, i=0;
    char c;
    
    while(i<nbytes-1)
    {
        nread = recv(sockfd, &c, sizeof(c), 0);
        
        if(nread == -1)
            return nread;
        else if(nread == 0)
            break;
        
        if(c == '\r')
            continue;
        if(c == '\n')
            break;
        
        msg[i++] = c;
    }
    
    msg[i] = '\0';
    
    return i;
}