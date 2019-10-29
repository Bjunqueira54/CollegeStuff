#include "SigHandlers.h"

void sigintHandler(int arg)
{
    Exit = true;
}