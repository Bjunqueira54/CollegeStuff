#include <irc_includes.h>
#include <sys/time.h>

#define BUFFERSIZE  4096
#define TIMEOUT 10

void Abort(char *msg);

int main(int argc, char **argv)
{
    char msg[BUFFERSIZE], ip[15];
    struct sockaddr_in serv_addr;
    int msg_len, port;
    int udp_socket = socket(AF_INET, SOCK_DGRAM, 0);
    struct timeval timeout;
    
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    
    if (udp_socket == -1)
    {
        fprintf(stderr, "Erro a criar socket!\n");
        return -1;
    }
    
    setsockopt(udp_socket, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));
    
    memset((char*) &serv_addr, 0, sizeof(serv_addr));
    
    fprintf(stdout, "Server IP: ");
    fscanf(stdin, "%15s", ip);
    fprintf(stdout, "Server Port: ");
    fscanf(stdin, "%i", &port);
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip);
    serv_addr.sin_port = htons(port);
    
    getchar();
    fflush(stdin);
    
    while(1)
    {
        fprintf(stdout, "Message: ");
        fgets(msg, BUFFERSIZE, stdin);
        msg_len = strlen(msg);
        
        if(sendto(udp_socket, msg, msg_len, 0, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) == -1)
        {
            fprintf(stderr, "Erro no envio da mensagem!\n");
            return -2;
        }
        else
        {
            fprintf(stdout, "Mensagem enviada!\n");
        }
    }
    
    close(udp_socket);
    fprintf(stdout, "\n");
        
    return EXIT_SUCCESS;
}