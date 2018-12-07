#include "Apressado.h"
#include "Tarifario.h"

Apressado::Apressado(): Tarifario::Tarifario() {}

Apressado::Apressado(const Apressado& orig) {}

int Apressado::calculaPagamento()
{
    int total = 0;
    
    for(int i=0; i<getTam(); i++)
	total += getValor(i);

    apagaTreino();
    
    return total;
}

Apressado::~Apressado() {}