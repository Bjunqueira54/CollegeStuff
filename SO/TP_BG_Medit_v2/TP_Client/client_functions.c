#include "client.h"

/* VARIVAIS GLOBAIS */
pid_t sv_pid;
int sv_fd;
pthread_t sv_recv_thread;

/* SERVER CONNECT */
void serverConnect(int sig)
{
    if(open(MEDIT_DEFAULT_MAIN_PIPE, O_WRONLY) == -1)
    {
        fprintf(stdout, "Server not running!\n");
        exit(EXIT_FAILURE);
    }
}

/* SERVER DISCONNECT */
void serverDisconnect(int sig)
{
    clear();
    mvwaddstr(stdscr, 1, 1, "Server has been shutdown!\n");
    refresh();
    getch();
    endwin();
    exit (EXIT_SUCCESS);
}

/* KILL THREAD */
void kThread()
{
    pthread_exit(NULL);
}

/* INVESTIGATE USER */
void invUser()
{
    
}

/* EDIT MODE LOOP */
int edModeLoop(int str_len)
{
    int c, x, y;
    c = getch();
    
    union sigval line_exit;
    line_exit.sival_int = -1;
    
    switch(c)
    {
        case KEY_RIGHT:            
            
        case KEY_LEFT:
       
        case KEY_BACKSPACE:
            
        case KEY_ENTER: //keypad enter
            
        case KEY_DC: //delete
            
        case 10: //keyboard enter
            
        case 27: //escape
            
        default:
            break;
            
    }
}

/* MOVE MODE LOOP */
int mvModeLoop()
{
    int c, x, y;
    c = getch();
    
    union sigval line_exit;
    line_exit.sival_int = -1;
    
    switch(c)
    {
        case KEY_UP:
            
        case KEY_DOWN:
            
        case KEY_ENTER: //keypad enter
            
        case 10: //keyboard enter
            
        case 27: //escape
            
        default:
            break;

    }
}

/* PRE LINE PREPARATIONS */
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

/* GET USERNAME */
void getUsername(char* userString) //redo
{
	mvwaddstr(stdscr, 0, 0, "What's your username?");
	char aux[MEDIT_MAXNAME + 1];
	aux[MEDIT_MAXNAME] = '\0';
        int c, i;

	for(i=0; i<MEDIT_MAXNAME; i++)
		userString[i] = ' ';

	for(int i=0; i<MEDIT_MAXNAME; i++)
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
					userString[--i] = ' ';
					i--;
				}
				else if(i == 0)
				{
					userString[i] = ' ';
					i--;
				}
				break;
			default:
				if(c<33 || c>126)
					i--;
				else
					userString[i] = c;
		}
		memcpy(aux, userString, MEDIT_MAXNAME * sizeof(char));
		mvwaddstr(stdscr, 1, 0, aux);
                //refresh();
	}
}

/* INVERT USERNAME STRING */
void invertString(char* userString)
{
	int scount=0, i;

	for(i=0; i<MEDIT_MAXNAME; i++)
		if(userString[i] == ' ')
			scount++;

	while(userString[MEDIT_MAXNAME - 1] == ' ')
	{
		for(int i=(MEDIT_MAXNAME - 1); i>0; i--)
		{
			userString[i] = userString[i-1];
		}
	}

	for(i=(scount - 1); i>=0; i--)
		userString[i] = ' ';
}