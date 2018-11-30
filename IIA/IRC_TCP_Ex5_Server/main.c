#include <irc_includes.h>
#include <pthread.h>

#define SV_PORT 6000
#define BUFFERSIZE 4096

void Abort(const char* msg, int sockfd)
{
	fprintf(stderr, "%sERROR %i\n", msg, errno);
	close(sockfd);
	exit (EXIT_FAILURE);
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

void* ServeClient(void* Arg)
{
	int sockfd = *(int*) Arg;
	int nbread, nbsent;
	static unsigned int cl_id = 0;
	++cl_id;
	char msg[BUFFERSIZE];
	
	do
	{
		nbread = readLine(sockfd, msg, BUFFERSIZE);

		switch(nbread)
		{
			case -1:
				fprintf(stderr, "Error on readLine()\n");
				return NULL;
			case 0:
				fprintf(stdout, "No data to read\n");
				return NULL;
			default:
				msg[nbread] = '\0';
				fprintf(stdout, "<CLIENT %i> %s\n", cl_id, msg);
				memset(msg, 0, sizeof(msg));
				sprintf(msg, "%i", nbread);
				nbread = strlen(msg);

				nbsent = writeN(sockfd, msg, nbread);

				if(nbsent == -1)
					fprintf(stderr, "ERROR SENDING CONFIRMATION\n");
				else if(nbsent < nbread)
					fprintf(stdout, "TRUNCATED CONFIRMATION\n");
				else
					fprintf(stdout, "CONFIRMED!\n");
		}
	}
	while(nbread != 0);
	
	close(sockfd);
	sockfd = 0;
	
	pthread_exit(NULL);
}

int main(int argc, char** argv)
{
	int sockfd, newsock, cl_addr_len;
	int* socketsfd[5] = {0, 0, 0, 0, 0};
	struct sockaddr_in sv_addr, cl_addr;
	
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	
	if(sockfd == -1)
		Abort("Error on socket()\n", sockfd);
	
	memset((char*) &sv_addr, 0, sizeof(sv_addr));
	
	sv_addr.sin_family = AF_INET;
	sv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	sv_addr.sin_port = htons(SV_PORT);
	
	if(bind(sockfd, (struct sockaddr*) &sv_addr, sizeof(sv_addr)) == -1)
		Abort("Error on bind()\n", sockfd);
	
	if(listen(sockfd, 5) == -1)
		Abort("Error on listen()\n", sockfd);
	
	cl_addr_len = sizeof(cl_addr);
	
	while(1)
	{
		newsock = accept(sockfd, (struct sockaddr*) &cl_addr, &cl_addr_len);
		
		if(newsock == -1)
			Abort("Error in accept()\n", newsock);
		else
		{
			pthread_t cl_thread;
			pthread_create(&cl_thread, NULL, ServeClient, (void*) &newsock);
			for(int i=0; i<5; i++)
				if(socketsfd[i] == 0)
					socketsfd[i] = &newsock;
		}
	}
	
	for(int i=0; i<5; i++)
		close(*socketsfd[i]);
	
    return (EXIT_SUCCESS);
}

