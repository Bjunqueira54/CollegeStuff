#include "Cliente.h"
#include "Tarifario.h"

Cliente::Cliente(const Cliente& orig) {}

void Cliente::IniciaTreino(int x)
{
    if(!Training)
    {
	Training = true;
	inicio = x;
    }
}

void Cliente::TerminaTreino(int x)
{
    if(Training)
    {
	Training = false;
	t->adicionaTreino(x-inicio);
    }
}

Cliente::~Cliente() {}