#include "SigHandlers.h"

//Find another way to handle this signal.
//exit() is currently here because
//main() hangs on getch() and doesn't
//recheck Exit. Not too serious, but not
//perfect either.
void SIGINT_Handler(int arg)
{
    Exit = true;
    exit (EXIT_SUCCESS);
}

void SIGALRM_Handler(int signal, siginfo_t* info, void* extra)
{
    
}