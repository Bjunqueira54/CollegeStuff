#include <irc_includes.h>

#define PROXY_PORT 1337
#define BUFFERSIZE 1024

int sv_sockfd;

int XchgMsg(const char* s)
{
	int sentbytes, msg_len;
	
	msg_len = strlen(s);
	
	if((sentbytes = send(sv_sockfd, s, msg_len, 0)) == -1)
	{
		fprintf(stderr, "send: ERROR %i", errno);
		return -1;
	}
	else if(sentbytes < msg_len)
	{
		fprintf(stderr, "XchgMsg send(): sentbytes < msg_len");
	}
	
	return 0;
}

void ServClient(int sockfd)
{
	static int cont=0;
	int msg_len, bytes_sent;
	char msg[BUFFERSIZE], tmp[BUFFERSIZE];
	
	msg_len = recv(sockfd, tmp, sizeof(tmp), 0);
	
	switch(msg_len)
	{
		case -1:
			perror("recv()");
			break;
		case 0:
			fprintf(stderr, "No Message...");
			break;
		default:
			msg[msg_len] = '\0';
			snprintf(msg, BUFFERSIZE, "<CLIENT %i> %s", ++cont, tmp);
			fprintf(stdout, "%s\n", msg);
			
			if(XchgMsg(msg) == 0)
			{
				msg_len = strlen(msg);
				
				if((bytes_sent = send(sockfd, msg, msg_len, 0)) == -1)
				{
					fprintf(stderr, "send: ERROR %i", errno);
				}
				else if(bytes_sent < msg_len)
				{
					fprintf(stderr, "send: sentbytes < msg_len");
				}
				else
				{
					fprintf(stdout, "OK!\n");
				}
			}
			else
			{
				fprintf(stderr, "Error sending client message to server\n");
			}
	}
}

int main(int argc, char** argv)
{
	char sv_ip[15];
	int sv_port, cl_sockfd, proxy_sockfd, cl_addr_len;
	struct sockaddr_in sv_addr, cl_addr, proxy_addr;
	
	fprintf(stdout, "Target Server IP: ");
	fscanf(stdin, "%15s", sv_ip);
	fprintf(stdout, "Target Server Port: ");
	fscanf(stdin, "%i", &sv_port);
	
	sv_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sv_sockfd == -1)
	{
		fprintf(stderr, "Server is down.\n");
		return 0;
	}
	
	memset((char*) &sv_addr, 0, sizeof(sv_addr));
	
	sv_addr.sin_family = AF_INET;
	sv_addr.sin_addr.s_addr = inet_addr(sv_ip);
	sv_addr.sin_port = htons(sv_port);
	
	connect(sv_sockfd, (struct sockaddr*) &sv_addr, sizeof(sv_addr));
	perror("connect()");
	
	proxy_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	perror("socket() #2");
	
	memset((char*) &proxy_addr, 0, sizeof(proxy_addr));
	
	proxy_addr.sin_family = AF_INET;
	proxy_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	proxy_addr.sin_port = htons(PROXY_PORT);
	
	bind(proxy_sockfd, (struct sockaddr*) &proxy_addr, sizeof(proxy_addr));
	perror("bind()");
	
	listen(proxy_sockfd, 5);
	
	cl_addr_len = sizeof(cl_addr);
	
	while(1)
	{
		cl_sockfd = accept(proxy_sockfd, (struct sockaddr*) &cl_addr, &cl_addr_len);
		
		if(cl_sockfd == -1)
			fprintf(stderr, "accept() ERROR: %i", errno);
		else
		{
			ServClient(cl_sockfd);
			close(cl_sockfd);
		}
	}
	
	return (EXIT_SUCCESS);
}