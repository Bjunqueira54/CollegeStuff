#include "client.h"

pid_t sv_pid;
int sv_fd;
pthread_t sv_recv_thread;

void kt()
{
    pthread_exit(NULL);
}

void* GetPageFromServer(void* arg)
{
    struct sigaction killthread;
    int nread;
    char buffer[BUFFERSIZE] = "";
    fd_set sv_fd_read, sv_fd_temp;
    
    killthread.sa_handler = &kt;
    sigaction(SIGINT, &killthread, NULL);
    
    FD_ZERO(&sv_fd_read);
    FD_SET(sv_fd, &sv_fd_read);
    
    while(1)
    {
        sv_fd_temp = sv_fd_read;
        memset((char*) buffer, 0, sizeof(buffer));

        switch(select(32, &sv_fd_temp, NULL, NULL, NULL))
        {
            case -1:
                if(errno == EINTR)
                    continue;
                else
                {
                    mvaddstr(getmaxy(stdscr)-1, 0, "select() error in GetPageFromServer()");
                    refresh();
                }
                break;
            case 0:
                fprintf(stdout, "Timeout...\n");
                continue;
            default:
                while((nread=read(sv_fd, buffer, BUFFERSIZE-1)))
                {
                    buffer[BUFFERSIZE]=0;
                    int i=0, j=0;
                    for(i=0; i<15; i++)
                    {
                        while(buffer[j] != '\n' || buffer[j] != '\0')
                        {
                            line[i][j+15] = buffer[j];
                        }
                    }
                    break;
                }
        }
    }
}

void inv_user(int sig, siginfo_t *info, void *extra)
{
    clear();
    
    if(info->si_value.sival_int == 1)
        mvaddstr(0, 0, "Invalid username!");
    else if(info->si_value.sival_int == 2)
        mvaddstr(0, 0, "Username already authenticated!");
    else if(info->si_value.sival_int == 3)
        mvaddstr(0, 0, "Server is full!");
    refresh();
    getch();
    endwin();
    exit (EXIT_SUCCESS);
}

void sv_disconnect(int sig)
{
    clear();
    mvwaddstr(stdscr, 1, 1, "Server has been shutdown!");
    refresh();
    getch();
    endwin();
    exit (EXIT_SUCCESS);
}

void sv_connect(int sig, siginfo_t *info, void *extra)
{
    if(info->si_value.sival_int == 1)
    {
        sv_pid = info->si_pid;
        char pipename[25];
        sprintf(pipename, "/tmp/client%luw", (unsigned long) getpid());
        mkfifo(pipename, S_IRUSR | S_IWUSR);
        sv_fd = open(pipename, O_RDONLY | O_NONBLOCK);
        pthread_create(&sv_recv_thread, NULL, GetPageFromServer, NULL);
    }
    else if(info->si_value.sival_int == 2)
    {
        int y, x;
        getyx(stdscr, y, x);
        move(y, 15);
        mode = 0;
        return;
    }
    else if(info->si_value.sival_int == 3)
        //Code a way to exit the line
        fprintf(stdout, "Placeholder Text\n");
}

int edModeLoop(int string_len)
{
    int c, x, y;
    getyx(stdscr, y, x);
    c = getch();

    union sigval line_exit;
    line_exit.sival_int = -1;

    switch(c)
    {
        case KEY_RIGHT:
            if(x<15+string_len)
            {
                x++;
                move(y,x);
            }
            return 1;

        case KEY_LEFT:
            if(x>15)
            {
                x--;
                move(y,x);
            }
            return 1;

        case 10: //keyboard enter
            move(y, 15);
            sigqueue(sv_pid, SIGUSR2, line_exit);
            return 6;
            break;

        case KEY_ENTER: //keypad enter
            move(y, 15);
            sigqueue(sv_pid, SIGUSR2, line_exit);
            return 6;
            break;

        case 27: //keyboard escape
            move(y, 15);
            sigqueue(sv_pid, SIGUSR2, line_exit);
            return 5;
            break;

        case KEY_BACKSPACE: //keyboard backspace
            if(x>15)
            {
                return 3;
            }
            return 1;
            break;

        case KEY_DC: //keyboard del
            if(x>15)
            {
                return 3;
            }
            return 1;
            break;

        default:
            if(c >= 32 && c <= 126)
            {
                if(x<15+45)
                    return c;
                else
                    return 1;
            }
            /*else  //Isto serve para debug do código da tecla premida e não é relevante para o trabalho
            {
                    int newx, newy;
                    getyx(stdscr, y, x);
                    newx=x;
                    newy=y;
                    char whatis[25];
                    sprintf(whatis, "%i", c);
                    mvwaddstr(stdscr, 17, 2, whatis);
                    move(newy, newx);
            }*/
            return 1;
    }
}

int mvModeLoop()
{
    int c, x, y;
    getyx(stdscr, y, x);
    c = getch();
    
    union sigval line;
    line.sival_int = y;

    switch(c)
    {
        case KEY_UP:
            if(y>0)
            {
                y--;
                move(y,x);
            }
        return 0;

        case KEY_DOWN:
            if(y<14)
            {
                y++;
                move(y,x);
            }
            return 0;

        case 10:    //Keyboard Enter
            sigqueue(sv_pid, SIGUSR2, line);
            return 4;
            break;

        case KEY_ENTER: //Keypad Enter
            sigqueue(sv_pid, SIGUSR2, line);
            return 4;
            break;

        case 27:    //Escape
            return 2;
            break;

        default:
            return 0;
    }
}

char* preLinePrep(char* string, int stringlen, int curind)
{
	if(curind < 10)
		sprintf(string, "(0%i)", curind);
	else
		sprintf(string, "(%i)", curind);

	//characters 4-13 are reserved for client [username]
	for(int i=4; i<14; i++)
		string[i] = ' ';

	string[14] = '|';

	for(int i=15; i<(15+stringlen); i++)
		string[i] = ' ';
	string[15+stringlen] = '\0';

	return string;
}

void getUsername(char* userstring)
{
	mvwaddstr(stdscr, 0, 0, "What's your username?");
	int c, i;
	char aux[MAXNAME+1];
	aux[MAXNAME] = '\0';

	for(i=0; i<MAXNAME; i++)
		userstring[i] = ' ';

	for(int i=0; i<MAXNAME; i++)
	{
		move(1, i);
		c = getch();

		switch(c)
		{
			case KEY_ENTER:
				return;
			case 10:
				return;
			case 27:
				endwin();
				exit (EXIT_SUCCESS);
			case KEY_BACKSPACE:
				if(i>0)
				{
					userstring[--i] = ' ';
					i--;
				}
				else if(i == 0)
				{
					userstring[i] = ' ';
					i--;
				}
				break;
			default:
				if(c<33 || c>126)
				{
					i--;
				}
				else
				{
					userstring[i] = c;
				}
		}
		memcpy(aux, userstring, MAXNAME*sizeof(char));
		mvwaddstr(stdscr, 1, 0, aux);
	}
}

void invertString(char* userstring)
{
	int scount=0, i;

	for(i=0; i<MAXNAME; i++)
		if(userstring[i] == ' ')
			scount++;

	while(userstring[MAXNAME-1] == ' ')
	{
		for(int i=(MAXNAME-1); i>0; i--)
		{
			userstring[i] = userstring[i-1];
		}
	}

	for(i=(scount-1); i>=0; i--)
		userstring[i] = ' ';
}
