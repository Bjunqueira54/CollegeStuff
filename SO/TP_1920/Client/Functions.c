#include "Functions.h"

#define COR0 0
#define COR1 1
#define COR2 2

WINDOW* notification = NULL;
WINDOW* wizard = NULL;

void BackEndMessageCreation(WINDOW*, char*);
int ArticleCreation(WINDOW*, char*, int, int);

//The only reason why this function and createWizardWin()
//are separated is because of dimensions.
void createNotificationWin()
{
    notification = subwin(stdscr, 5, 15, getmaxy(stdscr) - 5, getmaxx(stdscr) - 15);
    wclear(notification);
}

void createWizardWin()
{
    wizard = subwin(stdscr, getmaxy(stdscr), getmaxx(stdscr), 0, 0);
    wclear(wizard);
}

void DestroyWindow(WINDOW* win)
{
    wclear(win);
    delwin(win);
    win = NULL;
    wrefresh(stdscr);
}

void drawBox(WINDOW* win)
{
    if(win == NULL)
        return;
    
    int y, x;
    
    getmaxyx(win, y, x);
    
    for(int i=0; i<y; i++)
    {
        mvwaddch(win, i, 0, '*');
        mvwaddch(win, i, x-1, '*');
    }
    for(int i=0; i<x; i++)
    {
        mvwaddch(win, 0, i, '*');
        mvwaddch(win, y-1, i, '*');
    }
}

int getwinstr(WINDOW* win, char* buf, int n, int y, int x)
{
    //yes, I am "making" my own fgets(), deal with it.
    //1/11/2019 - 1AM: Should be working 100%. Testing required.
    int c_read = 0;
    int c;
    
    mvwaddch(win, y, x, '_');
    wrefresh(win);
    
    while(c_read < n)
    {
        c = getch();
        
        if(c == 10) //Enter
        {
            mvwaddch(win, y, x, ' ');
            break;
            
        }
        else if(c == 27)    //Escape
        {
            /*mvwaddch(win, y, x, ' ');
            break;*/
            //Figure out later which
            //to return: -1 or 0
            return -1;
        }
        else if(c == KEY_BACKSPACE)
        {
            if(c_read == 0)
                continue;
            
            buf[c_read - 1] = '\0';
            c_read--;
            
            mvwaddch(win, y, x, ' ');
            x--;
            mvwaddch(win, y, x, '_');
        }
        else if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
        {
            mvwaddch(win, y, x, c);
            x++;
            mvwaddch(win, y, x, '_');
            
            buf[c_read] = c;
            c_read++;
        }
        else
            continue;
        
        wrefresh(win);
    }
    
    buf[c_read] = '\0';
    
    if(c_read < 0)
        return -1;
    
    return c_read;
}

void setWindowColor(int c)
{
    init_pair(COR0, COLOR_WHITE, COLOR_BLACK);
    init_pair(COR1, COLOR_WHITE, COLOR_RED);
    init_pair(COR2, COLOR_WHITE, COLOR_YELLOW);
    
    if(c == 0)
        wattron(notification, COLOR_PAIR(COR0));
    else if((c % 2) == 0)
        wattron(notification, COLOR_PAIR(COR2));
    else
        wattron(notification, COLOR_PAIR(COR1));
}

void newNotification(const char* notice_str)
{
    createNotificationWin();
    
    int rep = 1;
    
    while(rep < 5)
    {
        setWindowColor(rep);
        drawBox(notification);
        mvwaddstr(notification, 1, 1, "New Message!");
        mvwaddstr(notification, 2, 1, "Topic:");
        mvwaddstr(notification, 3, 1, notice_str);
        wrefresh(notification);
        usleep(250*1000);
        rep++;
    }
    
    DestroyWindow(notification);
}

void PrintMenu(pTopic TopicList)
{
    if(TopicList == NULL)
        return;
    else
    {
        drawBox(stdscr);
        
        int y = 1, x = 1;
        
        for(;y < getmaxy(stdscr) - 1 && TopicList != NULL; y++)
        {
            mvwaddstr(stdscr, y, x, TopicList->title);
        }
    }
}

//Un-optimized. Write logic now, create sub-functions later
void newMessage(pTopic TopicList)
{
    //New WINDOW* just so we don't write to stdscr
    createWizardWin();
    
    //If the user didn't select a topic in the main menu, he'll select it now.
    char* TopicTitle = malloc(sizeof(char) * MAXTITLELEN);
    
    //malloc returns NULL on error or if malloc(0)
    if(TopicTitle == NULL)
    {
        DestroyWindow(wizard);
        refresh();
        return;
    }
    
    drawBox(wizard);
    
    mvwaddstr(wizard, 2, 2, "Welcome to the message creation wizard!");
    mvwaddstr(wizard, 4, 2, "What topic do you wish to write to?");
    wrefresh(wizard);
    
    //Something went wrong
    if(getwinstr(wizard, TopicTitle, MAXTITLELEN, 5, 2) == -1)
    {
        DestroyWindow(wizard);
        refresh();
        return;
    }
    
    newTopicMessage(TopicTitle);
}

//Interface between newMessage() and
//BackEndMessageCreation() since main()
//can provide a TopicTitle if the user
//chooses to create a new Message
//while already inside a topic.
void newTopicMessage(char* TopicTitle)
{
    //This is here only if
    //main() was the one calling
    //this function.
    if(wizard == NULL)
        createWizardWin();
    
    BackEndMessageCreation(wizard, TopicTitle);
}

void BackEndMessageCreation(WINDOW* win, char* TopicTitle)
{
    pText newText = malloc(sizeof(Text));
    char time_str[5];
    
    //Keep these NULL.
    //Send to server first for verification
    //before recieving it back to add to TopicList
    newText->next = NULL;
    newText->prev = NULL;
    newText->topic = NULL;
    
    wclear(win);
    drawBox(win);
    
    mvwaddstr(win, 2, 2, "What Title will your message have?");
    wrefresh(win);
    //Something went wrong?
    if(getwinstr(win, newText->title, MAXTITLELEN, 3, 2) == -1)
    {
        free(newText);
        DestroyWindow(win);
        refresh();
        return;
    }
    
    mvwaddstr(win, 5, 2, "How many seconds do you want it to last?");
    wrefresh(win);
    //Something went wrong?
    if(getwinstr(win, time_str, 5, 6, 2) == -1)
    {
        free(newText);
        DestroyWindow(win);
        refresh();
        return;
    }
    
    newText->duration = atoi(time_str);
    
    wclear(win);
    drawBox(win);
    mvwaddstr(win, 1, 2, "Write your message (Max 1000 characters)(ESCAPE to finish)");
    wrefresh(win);
    
    ArticleCreation(win, newText->article, 4, 2);
    
    wclear(win);
    drawBox(win);
    mvwaddstr(win, 2, 2, "Thank you for submitting a new message");
    mvwaddstr(win, 3, 2, "The server will recieve it in a few moments.");
    mvwaddstr(win, 5, 2, "(press any key to Continue...)");
    
    getch();
    
    SendTextToServer(TopicTitle, newText);
}

//No point passing an 'n' value like in getwinstr()
//since articles will always have MAXTEXTLEN.
int ArticleCreation(WINDOW* win, char* buf, int y, int x)
{
    //Check later if this is allowed
    //If not, push it outside and
    //give it parameters
    //ONLY WORKS WITH x FOR NOW
    void checkBoundaries()
    {
        if(x >= getmaxx(win) - 2)
        {
            x = 1;
            y++;
        }
        else if(x <= 1)
        {
            x = getmaxx(win) - 2;
            y--;
        }
        
        //This is only just so the fucking thing doesn't crash
        //I'll think about something else at a later date.
        if(y <= 0 || y >= getmaxy(win) - 1)
            y--;
        
        //BOUNDARIE CHECKING IS BUGGY! FIX ASAP!
    }
    
    int c_read = 0;
    int c;
    char c_left[5] = "";
    
    //Keeping these for now
    //Maybe usefull?
    int begy = y, begx = x;
    
    mvwaddstr(win, 2, 2, "Characters left: 1000");
    mvwaddch(win, y, x, '_');
    wrefresh(win);
    
    while(c_read < MAXTEXTLEN)
    {
        c = getch();
        
        if(c == 27)    //Escape
            break;
        else if(c == KEY_BACKSPACE)
        {
            if(c_read == 0)
                continue;
            
            buf[c_read - 1] = '\0';
            c_read--;
            
            mvwaddch(win, y, x, ' ');
            x--;
            checkBoundaries();
            mvwaddch(win, y, x, '_');
        }
        /*else if((c >= 'A' && c <= 'Z') ||
                (c >= 'a' && c <= 'z') ||
                (c >= '0' && c <= '9') ||
                (c == ' ') ||)*/
        else if(c >= 32 && c <= 126)
        {
            mvwaddch(win, y, x, c);
            x++;
            checkBoundaries();
            mvwaddch(win, y, x, '_');
            
            buf[c_read] = c;
            c_read++;
        }
        //DO NOT ENABLE THE ENTER KEY YET!
        /*else if(c == 10) //Enter
        {
            buf[c_read] = '\n';
            c_read++;
            
            mvwaddch(win, y, x, ' ');
            y++;
            x = 1;
            mvwaddch(win, y, x, '_');
        }*/
        else
            continue;
        
        memset(c_left, 0, 4);
        snprintf(c_left, 5, "%4.0d", 1000 - c_read);
        wmove(win, 2, 19);
        wclrtoeol(win);
        mvwaddch(win, 2, getmaxx(win) - 1, '*');
        mvwaddstr(win, 2, 19, c_left);
        wrefresh(win);
    }
    
    buf[c_read] = '\0';
    
    if(c_read < 0)
        return -1;
    
    return c_read;
}