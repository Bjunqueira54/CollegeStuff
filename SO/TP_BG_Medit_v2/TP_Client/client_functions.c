#include "client.h"

/* VARIVAIS GLOBAIS */
pid_t sv_pid;
int sv_fd;

/* KILL THREAD  */
void KT()
{
    pthread_exit(NULL);
}

/* SERVER DISCONNECT */
void serverDisconnect(int sig)
{
    clear();
    mvwaddstr(stdscr, 1, 1, "Server has been shutdown!");
    refresh();
    getch();
    endwin();
    exit (EXIT_SUCCESS);
}
/* SERVER CONNECT */
void serverConnect(int sig)
{
    
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

/* EDIT MODE LOOP */
int edModeLoop(int string_len)
{
    int c, x, y;
    getyx(stdscr, y, x);
    c = getch();

    union sigval line_exit;
    line_exit.sival_int = -1;

    switch(c)
    {
        case KEY_RIGHT:         //right arrow key
            if(x<15+string_len)
            {
                x++;
                move(y,x);
            }
            return 1;

        case KEY_LEFT:          //left arrow key
            if(x>15)
            {
                x--;
                move(y,x);
            }
            return 1;

        case 10:                //keyboard enter
            move(y, 15);
            sigqueue(sv_pid, SIGUSR2, line_exit);
            return 6;
            break;

        case KEY_ENTER:         //keypad enter
            move(y, 15);
            sigqueue(sv_pid, SIGUSR2, line_exit);
            return 6;
            break;

        case 27:                //keyboard escape
            move(y, 15);
            sigqueue(sv_pid, SIGUSR2, line_exit);
            return 5;
            break;

        case KEY_BACKSPACE:     //keyboard backspace
            if(x>15)
            {
                return 3;
            }
            return 1;
            break;

        case KEY_DC:            //keyboard del
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

/* MOVE MODE LOOP */
int mvModeLoop() //redo
{
    int c, x, y;
    getyx(stdscr, y, x);
    c = getch();
    
    union sigval line;
    line.sival_int = y;

    switch(c)
    {
        case KEY_UP:        //arrow up key
            if(y>0)
            {
                y--;
                move(y,x);
            }
        return 0;

        case KEY_DOWN:      //arrow down key
            if(y<14)
            {
                y++;
                move(y,x);
            }
            return 0;

        case 10:            //keyboard enter
            sigqueue(sv_pid, SIGUSR2, line);
            return 4;
            break;

        case KEY_ENTER:     //keypad Enter
            sigqueue(sv_pid, SIGUSR2, line);
            return 4;
            break;

        case 27:            //escape
            return 2;
            break;

        default:
            return 0;
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

/* INVERT USERNAME */
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