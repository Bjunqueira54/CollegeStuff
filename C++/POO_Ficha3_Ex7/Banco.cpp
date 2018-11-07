#include "Banco.h"

Banco::Banco(string a): nome(a){}

void Banco::AddConta(const Conta x)
{
    v.push_back(x);
}

bool Banco::Deposita(int valor, int cc)
{
    for(auto it = v.begin(); it != v.end(); it++)
    {
        if(it->getTitular()->getCC() == cc)
        {
            it->VariarSaldo(valor);
            return true;
        }
    }
    
    return false;
}

string Banco::getNomes()
{
    ostringstream con;
    
    for(auto it = v.begin(); it != v.end(); it++)
    {
        con << it->getTitular()->getNome() << " ";
    }
    
    return con.str();
}

int Banco::getSaldos()
{
    int total=0;
    
    for(auto it = v.begin(); it != v.end(); it++)
    {
        total += it->getSaldo();
    }
    
    return total;
}

Conta const* Banco::getConta(int cc)
{
    for(auto it : v)
    {
        if(it.getTitular()->getCC() == cc)
            return conta;
    }
}

bool Banco::eliminaConta(int cc)
{
    for(auto it = v.begin(); it != v.end(); it++)
    {
        if(it->getTitular()->getCC() == cc)
        {
            v.erase(it);
            return true;
        }
    }
    
    return false;
}