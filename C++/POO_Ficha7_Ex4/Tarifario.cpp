#include "Tarifario.h"

/*Tarifario::Tarifario() {}

Tarifario::Tarifario(const Tarifario& orig) {}*/

void Tarifario::apagaTreino()
{
    if(tab != nullptr)
    {
	delete []tab;
	tab = nullptr;
	tam = 0;
    }
}

int Tarifario::calculaPagamento()
{
    int total = 0;
    
    for(int i=0; i<tam; i++)
	total += tab[i];

    return total;
}

void Tarifario::adicionaTreino(int n)
{
    int *tmp = new int[tam+1];
    
    for(int i=0; i<tam; i++)
	tmp[i] = tab[i];
    
    tmp[tam] = n;
    
    if(tab != nullptr)
    {
	delete[]tab;
    }
    
    tam++;
    tab = tmp;
}

Tarifario::~Tarifario()
{
    delete []tab;
}