#include "Conta.h"

Conta::Conta(Pessoa *a):titular(a)
{
    
}

void Conta::VariarSaldo(int a)
{
    saldo += a;
}

Pessoa const *Conta::getTitular() const
{
    return titular;
}

string Conta::getAsString() const
{
    ostringstream os;
    os << "Saldo: " << saldo << "\nTitular: " << getTitular() << endl;
}

int Conta::getSaldo() const
{
    return saldo;
}