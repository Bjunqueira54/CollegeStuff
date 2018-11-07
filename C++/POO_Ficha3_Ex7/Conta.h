#ifndef CONTA_H
#define CONTA_H

#include "Pessoa.h"

using namespace std;

class Conta
{
    int saldo=0;
    Pessoa const *titular;
    
public:
    
    Conta(Pessoa *a);

    void VariarSaldo(int a);
    
    Pessoa const* getTitular() const;
    
    string getAsString() const;
    
    int getSaldo() const;
};

#endif /* CONTA_H */

