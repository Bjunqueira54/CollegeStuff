#ifndef CLIENTE_H
#define CLIENTE_H

#include "headers.h"
#include "Tarifario.h"

class Cliente
{
    string nome;
    int bi;
    int inicio = -1;
    bool Training = false;
    Tarifario *t;
    
public:
    
    Cliente(string a, int b, Tarifario *c): nome(a), bi(b), t(c) {}
    Cliente(const Cliente& orig);
    
    void IniciaTreino(int x);
    void TerminaTreino(int x);
    
    int pagar() {return t->calculaPagamento();}
    
    virtual ~Cliente();
};

#endif