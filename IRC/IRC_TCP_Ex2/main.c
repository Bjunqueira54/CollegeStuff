#include <irc_includes.h>

#define BUFFERSIZE 4096

int writeN(int sockfd, char *buffer, int nbytes)
{
    int nLeft, nWritten;
    
    nLeft = nbytes;
    
    while(nLeft > 0)
    {
        nWritten = send(sockfd, buffer, nLeft, 0);
        if(nWritten == 0 || nWritten == -1)
            return nWritten;
        
        nLeft -= nWritten;
        buffer += nWritten;
    }
    
    return nWritten;
}

int readLine(int sockfd, char* buffer, int nbytes)
{
    int nread, i;
    char c;
    
    i=0;
    
    while(i<nbytes-1)
    {
        nread = recv(sockfd, &c, sizeof(c), 0);
        if(nread == -1)
            return nread;
        if(nread == 0)
            break;
        if(c=='\r')
            continue;
        if(c=='\n')
            break;
        buffer[i++] = c;
    }
}

int main(int argc, char** argv)
{
    int sockfd, msg_len, nbytes, sv_port;
    char msg[BUFFERSIZE], sv_ip[15];
    struct sockaddr_in sv_addr;
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    if(sockfd == -1)
    {
        fprintf(stderr, "SOCKET ERROR %i", errno);
        close(sockfd);
        exit (EXIT_FAILURE);
    }
    
    memset((char*) &sv_addr, 0, sizeof(sv_addr));
    
    
    fprintf(stdout, "Server IP: ");
    fscanf(stdin, "%15s", sv_ip);
    fprintf(stdout, "Server Port: ");
    fscanf(stdin, "%i", &sv_port);
    
    sv_addr.sin_family = AF_INET;
    sv_addr.sin_addr.s_addr = inet_addr(sv_ip);
    sv_addr.sin_port = htons(sv_port);
    
    if(connect(sockfd, (struct sockaddr*) &sv_addr, sizeof(sv_addr)) == -1)
    {
        fprintf(stderr, "CONNECT ERROR %i", errno);
        close(sockfd);
        exit (EXIT_FAILURE);
    }
    getchar();
    fprintf(stdout, "Mensagem: ");
    fgets(msg, BUFFERSIZE, stdin);
    
    msg_len = strlen(msg);
    
    if((nbytes = writeN(sockfd, msg, msg_len)) == -1)
    {
        fprintf(stderr, "writeN ERROR %i", errno);
        close(sockfd);
        exit (EXIT_FAILURE);
    }
    else if(nbytes < msg_len)
        fprintf(stderr, "Message Truncated!\n");
    else
        fprintf(stdout, "Message sent!\n");
    
    msg_len = strlen("\n");
    
    if(writeN(sockfd, "\n", msg_len) != msg_len)
        fprintf(stderr, "Error sending '\n' ");
    
    nbytes = readLine(sockfd, msg, sizeof(msg));
    
    if(nbytes == -1)
    {
        fprintf(stderr, "READLINE ERROR %i", errno);
        close(sockfd);
        exit (EXIT_FAILURE);
    }
    
    close(sockfd);
    exit (EXIT_SUCCESS);
    
    return (EXIT_SUCCESS);
}