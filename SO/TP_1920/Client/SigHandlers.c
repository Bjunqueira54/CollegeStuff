#include "SigHandlers.h"

void SIGINT_Handler(int arg)
{
    Exit = true;
}