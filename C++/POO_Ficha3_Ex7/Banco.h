#ifndef BANCO_H
#define BANCO_H

#include "Conta.h"

class Banco
{
    string nome;
    vector <Conta> v;
    const Conta *conta;
    
public:
    
    Banco(string a);
    
    void AddConta(Conta x);
    bool Deposita(int v, int cc);
    string getNomes();
    int getSaldos();
    Conta const* getConta(int cc);
    bool eliminaConta(int cc);
};

#endif /* BANCO_H */

