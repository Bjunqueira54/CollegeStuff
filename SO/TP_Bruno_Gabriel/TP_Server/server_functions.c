#include "server.h"

int mp;	//Main Pipe File Descriptor
int cp; //Client Pipe File Descriptor
pClients cl_vec = NULL;
int cl_vec_tam = 0;

void SigHandler(int signal)
{
    pthread_exit(NULL);
}

void* WriteToClients(void* arg)
{
    struct sigaction kt;
    pClients aux;
    
    kt.sa_handler = &SigHandler;
    sigaction(SIGINT, &kt, NULL);
    
    while(1)
    {
        aux = cl_vec;

        while(aux != NULL)
        {
            aux->writefd = open(aux->pipewrite, O_WRONLY);

            for(int i=0; i<options->lines; i++)
            {
                if(aux->writefd != -1)
                {
                    write(aux->writefd, EditorLines[i], options->columns-1);
                    write(aux->writefd, "\n", sizeof(char));
                }
            }

            aux = aux->prox;
        }

        aux = NULL;
    }
}

void DeleteClient(pClients client)
{
    pid_t remove;
    
    if(client->readfd != 0)
        if(close(client->readfd) != EBADF)
            fprintf(stderr, "Error on client %i close(). ERROR %i\n", client->id, errno);
    
    /*if(client->writefd != 0)
        if(close(client->writefd) != EBADF)
            fprintf(stderr, "Error on client %i close(). ERROR %i\n", client->id, errno);*/ //Clients take care of this part
    
    if(client->active_thread == 1)
    {
        pthread_kill(client->cl_thread, SIGINT);
        pthread_join(client->cl_thread, NULL);
    }
    
    if((remove = fork()) == 0)
        execlp("rm", "rm", client->piperead, client->pipewrite, NULL);  //consider deleting client->pipewrite to be client's responsibility
    else
        waitpid(remove, NULL, 0);
    
    free(client->piperead);
    free(client->pipewrite);
}


void* ActivateLine(void* arg)
{
    pClients client = (pClients) arg;
    struct sigaction thr_cancel;
    fd_set cl_pipe_fd, cl_temp_fd;
    int bread, cl_fd, i;
    
    client->active_thread = 1;
    
    client->readfd = open(client->piperead, O_RDONLY);
    
    thr_cancel.sa_handler = &SigHandler;
    
    sigaction(SIGINT, &thr_cancel, NULL);
    
    FD_ZERO(&cl_pipe_fd);
    FD_SET(cl_fd, &cl_pipe_fd);
    
    while(1)
    {
        cl_temp_fd = cl_pipe_fd;
        
        memset((char*) EditorLines[client->acl], 0, options->columns*sizeof(char));
        
        switch(select(32, &cl_temp_fd, NULL, NULL, NULL))
        {
            case -1:
                if(errno == EINTR)
                    continue;
                else
                {
                    fprintf(stderr, "Error on select(). Client ID: %i, ERROR %i\n", client->id, errno);
                    pthread_exit(NULL);
                }
                break;
            case 0:
                fprintf(stderr, "Client ID %i select() timeout...\n", client->id);
                break;
            default:
                if(client->acl == -1)
                    continue;
                
                while((bread = read(cl_fd, (char*) EditorLines[client->acl], sizeof(char))))
                {
                    if(EditorLines[client->acl][bread-1] == '\n')
                    {
                        EditorLines[client->acl][bread] = '\0';
                        break;
                    }
                    else if(EditorLines[client->acl][bread-1] == '\b')
                        bread = bread - 1;
                    
                    EditorLines[client->acl][bread] = '\0';
                }
        }
    }
}

void ClientSignals(int signal, siginfo_t *info, void* extra)
{
    pClients aux;
    
    aux = cl_vec;
    
    while(aux != NULL)
    {
        if(aux->cl_pid == info->si_pid)
            break;
        
        aux = aux->prox;
    }
    
    if(aux == NULL)
        return;     //How did you get here? Only Validated Clients can send SIGUSR2, right?
    
    if(info->si_value.sival_int == -1)
    {
        //int exline = aux->acl;
        //Call for function to Aspell.
        aux->acl == -1;
        if(aux->active_thread == 1)
        {
            aux->active_thread = 0;
            pthread_kill(aux->cl_thread, SIGINT);
        }
        else
            fprintf(stderr, "How is the client sending a '-1' sival_int when he's already out of a line?\n");
    }
    else
    {
        aux->acl = info->si_value.sival_int;
        if(aux->active_thread == 0)
            pthread_create(&aux->cl_thread, NULL, ActivateLine, (void*) aux);
        else
            fprintf(stderr, "How did you get here? Anyway, client tried to create a new thread without exiting the old one\n");
    }
}

void ClientDisconnect(int signal, siginfo_t *info, void* extra)
{
    pid_t cl_pid, remove;
    pClients aux = cl_vec, aux2;

    cl_pid = info->si_pid;
    
    while(aux != NULL)  //Este ciclo avança até ao fim da lista ligada.
    {
        if(aux->cl_pid == cl_pid)   //Se encontrar um cliente cujo PID seja igual ao PID do processo que enviou o sinal, sai fora do ciclo.
            break;
        
        aux = aux->prox;
    }
    
    if(aux == NULL) //Nunca deverá entrar aqui. Só para prevenir de um cliente ser apagado quando não devia.
        return;
    
    /*if((remove = fork()) == 0)
        execlp("rm", "rm", aux->piperead, aux->pipewrite, NULL);    //aux->pipewrite should be the client's responsibility
    else
        waitpid(remove, NULL, 0);*/
    
    aux->writefd = -1;
    aux2 = aux;
    
    
    if(aux2->prev == NULL)   //Se for o 1º elemento da Lista
    {
        if(aux2->prox != NULL)
        {
            cl_vec = aux2->prox;
            aux2->prox->prev = NULL;
        }
        else    //No caso de ser o unico elemento, aux->prox deverá ser NULL, logo cl_vec ficará vazio.
            cl_vec = NULL;
    }
    else if(aux2->prox == NULL)  //Se for o ultimo elemento da lista
        aux2->prev->prox = NULL;
    else    //Se for um elemento no meio da lista
    {
        aux2->prox->prev = aux2->prev;
        aux2->prev->prox = aux2->prox;
    }
    
    DeleteClient(aux);
    
    free(aux);
    cl_vec_tam--;
    
    if(cl_vec_tam <= 0)
    {
        cl_vec_tam = 0;
        cl_vec = NULL;
    }
}

void CheckArgs(Params *p)
{
    if(p->f == 1)
        fprintf(stdout, "Database File: %s\n", p->fname);
    else
        fprintf(stdout, "Database File: %s\n", DEFAULT_DB_FILE);
    
    if(p->p == 1)
        fprintf(stdout, "Main Named Pipe: %s\n", p->pname);
    else
        fprintf(stdout, "Main Named Pipe: %s\n", MEDIT_DEFAULT_MAIN_PIPE);
    
}

void CheckOptions(Settings *a)
{
    fprintf(stdout, "Max Lines: %i\n", a->lines);
    fprintf(stdout, "Max Columns: %i\n", a->columns);
    fprintf(stdout, "Max Users: %i\n", a->maxusers);
    fprintf(stdout, "User Line Timeout: %i\n", a->timeout);
}

void ParseEnvVars(Settings *a)
{
    char* env;

    if((env = getenv("MEDIT_MAXLINES")) != NULL)
    {
        a->lines = atoi(env);
        if(a->lines <= 0 || a->lines > MEDIT_MAXLINES)
            a->lines = MEDIT_MAXLINES;
    }
    else
        a->lines = MEDIT_MAXLINES;
    
    if((env = getenv("MEDIT_MAXCOLUMNS")) != NULL)
    {
        a->columns = atoi(env);
        if(a->columns <= 0 || a->columns > MEDIT_MAXCOLUMNS)
            a->columns = MEDIT_MAXCOLUMNS;
    }
    else
        a->columns = MEDIT_MAXCOLUMNS;
    
    if((env = getenv("MEDIT_TIMEOUT")) != NULL)
    {
        a->timeout = atoi(env);
        if(a->timeout <= 0)
            a->timeout = MEDIT_TIMEOUT;
    }
    else
        a->timeout = MEDIT_TIMEOUT;
    
    if((env = getenv("MEDIT_MAXUSERS")) != NULL)
    {
        a->maxusers = atoi(env);
        if(a->maxusers <= 0 || a->maxusers > MEDIT_MAXLINES)
            a->maxusers = MEDIT_MAXUSERS;
    }
    else
        a->maxusers = MEDIT_MAXUSERS;
}

void ValidateNewClient(const char* newuser, pid_t cl_pid)
{
    char *dbname;
    pClients aux = NULL;
    
    aux = cl_vec;
        
    while(aux != NULL)
    {
        if(strcmp(newuser, aux->username) == 0) //If user already exists
        {
            union sigval user_exists;
            user_exists.sival_int = 2;

            if( sigqueue(cl_pid, SIGINT, user_exists) == -1)
                fprintf(stderr, "sigqueue() error in ValidateNewClient() USER EXISTS\n");

            return;
        }
        aux = aux->prox;
    }

    aux = NULL;
    
    dbname = params->fname;
    
    FILE *db;
    db = fopen(dbname, "r");
    
    if(db == NULL)
    {
        fprintf(stderr, "Error opening database file");
        ExitVar = 1;
        return;
    }
    
    while(1)
    {
        char filestring[101] = "", username[MAXNAME]="";
        pClients newcl = NULL, aux = NULL;
        
        if(fscanf(db, "%[^\n]s", filestring) == EOF)
            break;
        fgetc(db);
        
        filestring[strlen(filestring)] = '\0';
        
        for(int i=0; i<MAXNAME && i<strlen(filestring); i++)
            username[i] = filestring[i];
        
        username[strlen(username)] = '\0';

        if(strcmp(username, newuser) == 0)
        {
            newcl = malloc(sizeof(Clients));
            
            if(newcl == NULL)
            {
                fprintf(stderr, "Error allocating memory for a new client\n");
                return;
            }
            
            strcpy(newcl->username, username);
            newcl->acl = -1;
            newcl->cl_pid = cl_pid;
            newcl->prev = NULL;
            newcl->prox = NULL;
            
            if(params->n != 1)
            {
                char pipename[20];
                sprintf(pipename, "/tmp/client%lur", (unsigned long) cl_pid);
                mkfifo(pipename, S_IRUSR | S_IWUSR);
                newcl->piperead = malloc(strlen(pipename)*sizeof(char));
                strcpy(newcl->piperead, pipename);
                
                memset((char*) pipename, 0, sizeof(pipename));
                sprintf(pipename, "/tmp/client%luw", (unsigned long) cl_pid);
                newcl->pipewrite = malloc(strlen(pipename)*sizeof(char));
                strcpy(newcl->pipewrite, pipename);
            }
            
            if(cl_vec == NULL)
            {
                cl_vec = newcl;
                newcl->id = 1;
            }
            else
            {
                aux = cl_vec;
                
                if(aux->id != 1)    //Se já tiver existido um cliente com id 1 mas entranto já saiu.
                {
                    aux->prev = newcl;
                    newcl->prox = aux;
                    cl_vec = newcl;
                    newcl->id = 1;
                }
                else
                {
                    while(aux->prox != NULL)
                    {
                        if(aux->id + 1 != aux->prox->id)    //Se o próximo da lista não tiver o ID a seguir a aux atual, é porque existiu um cliente com este ID mas entretanto já saiu.
                            break;
                        
                        aux = aux->prox;
                    }
                    
                    if(aux->prox == NULL)
                    {
                        aux->prox = newcl;
                        newcl->prev = aux;
                        newcl->id = newcl->prev->id + 1;
                    }
                    else
                    {
                        newcl->prox = aux->prox;
                        aux->prox = newcl;
                        newcl->prev = aux;
                        newcl->prox->prev = newcl;
                        newcl->id = newcl->prev->id + 1;
                    }
                }
            }
            cl_vec_tam++;
            
            union sigval cl_connected;
            cl_connected.sival_int = 1;
            if(sigqueue(cl_pid, SIGUSR1, cl_connected) == -1)
                fprintf(stderr, "sigqueue() error in ValidateNewClient() CLIENT CONNECTED");
            
            fclose(db);
            return;
        }
    }
    
    union sigval invalid_user;
    invalid_user.sival_int = 1;
    if(sigqueue(cl_pid, SIGINT, invalid_user) == -1)
        fprintf(stderr, "sigqueue() error in ValidateNewClient() INVALID USER\n");
    
    fclose(db);
}

void* ParseCommands(void* arg)
{
    char cmd[25];
    fprintf(stdout, "Command: ");
    fgets(cmd, 25, stdin);
    cmd[strlen(cmd)-1] = '\0';  //Replaces '\n' with '\0'
    int scount=0;
    
    for(int i=0; i<strlen(cmd); i++)
    {
        cmd[i] = tolower(cmd[i]);
        if(cmd[i] == ' ')
        {
            scount++;
            break;
        }
    }
    
    if(strcmp(cmd, "settings") == 0)
    {
        CheckArgs(params);
        CheckOptions(options);
    }
    else if(strcmp(cmd, "shutdown") == 0)
        ExitVar = 1;
    else if(strcmp(cmd, "statistics") == 0)
        fprintf(stderr, "Coming soon...\n");
    else if(strcmp(cmd, "users") == 0)
    {
        fprintf(stderr, "\nNumber of currently connected users: %i\n\n", cl_vec_tam);
        pClients aux = cl_vec;
        
        while(aux != NULL)
        {
            fprintf(stdout, "Username: %s\n", aux->username);
            fprintf(stdout, "ID: %i\n", aux->id);
            fprintf(stdout, "Active Reading Pipe: %s\n", aux->piperead);
            fprintf(stdout, "Active Writting Pipe: %s\n", aux->pipewrite);
            if(aux->acl != -1)
                fprintf(stdout, "Current Editing Line: %i\n", aux->acl);
            else
                fprintf(stdout, "Current Editing Line: N/A\n");
            putc('\n', stdout);
            aux = aux->prox;
        }
    }
    else if(strcmp(cmd, "text") == 0)
        fprintf(stderr, "Coming soon...\n");
    else if(scount > 0)
    {
        char argument[20];
        cmd[4] = '\0';

        for(int i=0, j=5; j<20; i++, j++)
        {
            argument[i] = cmd[j];
            cmd[j] = '\0';
        }
        
        if(strcmp(cmd, "load") == 0)
        {
            fprintf(stdout, "Coming soon...\n");

            FILE *load = fopen(argument, "rt");

            if(load == NULL)
                fprintf(stderr, "File either does not exist in directory or name too long\n");
            else
                fprintf(stdout, "If this command was working, file %s would be loaded\n", argument);
        }
        else if(strcmp(cmd, "save") == 0)
        {
            fprintf(stdout, "Coming soon...\n");
            FILE *save = fopen(argument, "rt");

            if(save == NULL)
                fprintf(stderr, "File either does not exist in directory or name too long\n");
            else
                fprintf(stdout, "If this command was working, file %s would be saved\n", argument);
        }
        else if(strcmp(cmd, "free") == 0)
        {
            fprintf(stdout, "Coming soon...\n");

            int line;
            line = atoi(argument);
            
            if(cmd <= 0)
                fprintf(stderr, "Invaline line number.\n");
            else
                fprintf(stdout, "If this command was working, line %i would be forcefully free now.\n", line);
        }
    }
    else
        fprintf(stderr, "Unknown command!\n");
        
    return NULL;
}

void* MainPipeHandler(void* arg)
{
    char* pipename = (char*) arg;
    struct sigaction action;
    fd_set mp_set, mp_set_temp;
    
    action.sa_handler = &SigHandler;
    sigaction(SIGINT, &action, NULL);
    
    mp = open(pipename, O_RDONLY);
    
    FD_ZERO(&mp_set);
    FD_SET(mp, &mp_set);
    
    while(1)
    {
        mp_set_temp = mp_set;
        
        switch(select(32, &mp_set_temp, NULL, NULL, NULL))
        {
            case -1:
                if(errno == EINTR)
                    continue;
                else
                {
                    fprintf(stderr, "Something undefined occurred in MainPipeHandler() select()\n");
                    break;
                }
            case 0:
                continue;
            default:
            {
                int bytesread, i;
                char readstring[15] = "", username[MAXNAME] = "", cl_pid_string[6] = "";
                pid_t cl_pid;
                
                while((bytesread = read(mp, readstring, 15)))
                {
                    readstring[bytesread] = '\0';
                    
                    for(i=0; i<MAXNAME && readstring[i] != ' '; i++)
                        username[i] = readstring[i];
                    
                    for(;readstring[i] == ' '; i++);
                    
                    for(int j=0; i<15 && j<6; j++, i++)
                        cl_pid_string[j] = readstring[i];
                    
                    intmax_t num;
                    char *tmp;
                    
                    num = strtoimax(cl_pid_string, &tmp, 10);
                    
                    cl_pid = (pid_t) num;
                    
                    if(cl_vec_tam <= options->maxusers)
                        ValidateNewClient(username, cl_pid);
                    else
                    {
                        union sigval sv_full;
                        sv_full.sival_int = 3;
                        if(sigqueue(cl_pid, SIGINT, sv_full) == -1)
                            fprintf(stderr, "sigqueue() error in MainPipeHandler SERVER FULL\n");
                    }
                }
            }
        }
    }
}
