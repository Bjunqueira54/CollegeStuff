#ifndef TARIFARIO_H
#define TARIFARIO_H

#include "headers.h"

class Tarifario
{
    int *tab = nullptr;
    int tam = 0;
    
public:
    
    //Tarifario();
    //Tarifario(const Tarifario& orig);
    
    void adicionaTreino(int n);
    
    virtual int calculaPagamento() = 0;
    int getTam() const {return tam;}
    int getValor(int i) const {return tab[i];}
    
    virtual ~Tarifario();
protected:
    void apagaTreino();
};

#endif