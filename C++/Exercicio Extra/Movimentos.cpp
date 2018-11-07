#include "Movimentos.h"

Movimentos::Movimentos(string a="", int b=0): name(a), saldo(b) {}

bool Movimentos::addMov(int x)
{
    mov.push_back(x);
}

Movimentos& Movimentos::operator+=(int x)
{
    saldo += x;
    mov.push_back(x);
    return *this;
}

Movimentos& Movimentos::operator-=(int x)
{
    saldo -= x;
    mov.push_back(0-x);
    return *this;
}

Movimentos operator+(Movimentos a, int b)
{
    a.setSaldo(a.getSaldo() + b);
    a.addMov(b);
    return a;
}

Movimentos operator-(Movimentos a, int b)
{
    a.setSaldo(a.getSaldo() - b);
    a.addMov(b);
    return a;
}

void Movimentos::setSaldo(int x)
{
    saldo = x;
}

int& Movimentos::getSaldo()
{
    return saldo;
}