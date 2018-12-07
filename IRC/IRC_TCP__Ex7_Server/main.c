#include <irc_includes.h>

#define SV_PORT 6000
#define BUFFERSIZE 1024

void ServProxy(int sockfd)
{
	int msg_len, bytes_sent;
	char msg[BUFFERSIZE];
	
	msg_len = recv(sockfd, msg, sizeof(msg), 0);
	
	switch(msg_len)
	{
		case -1:
			perror("recv()");
			break;
		case 0:
			fprintf(stdout, "No message....\n");
			break;
		default:
			msg[msg_len] = 0;
			fprintf(stdout, "%s\n", msg);
			snprintf(msg, BUFFERSIZE, "%i", msg_len);
			msg_len = strlen(msg);
			
			if((bytes_sent = send(sockfd, msg, msg_len, 0)) == -1)
				perror("send()");
			else if(bytes_sent < msg_len)
				fprintf(stderr, "Message Truncated (bytes sent < message size\n");
			else
				fprintf(stdout, "OK!\n");
	}
	return;
}

int main(int argc, char** argv)
{
	int sockfd, proxy_sockfd, proxy_addr_len;
	struct sockaddr_in sv_addr, proxy_addr;
	
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	perror("socket()");
	
	memset((char*) &sv_addr, 0, sizeof(sv_addr));
	
	sv_addr.sin_family = AF_INET;
	sv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	sv_addr.sin_port = htons(SV_PORT);
	
	bind(sockfd, (struct sockaddr*) &sv_addr, sizeof(sv_addr));
	perror("bind()");
	
	listen(sockfd, 1);
	perror("listen()");
	
	proxy_addr_len = sizeof(proxy_addr);
	
	while(1)
	{
		proxy_sockfd = accept(sockfd, (struct sockaddr*) &proxy_addr, &proxy_addr_len);
		
		if(proxy_sockfd == -1)
			fprintf(stderr, "accept: ERROR %i", errno);
		else
		{
			ServProxy(proxy_sockfd);
			close(proxy_sockfd);
		}
	}
	
	return (EXIT_SUCCESS);
}