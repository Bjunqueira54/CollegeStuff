#include "Fracao.h"

Fracao::Fracao(int a, int b): num(a),den(b)
{
    if(b == 0)
        den=1;
    else
        den=b;
}

void Fracao::setnum(int x)
{
    num=x;
}

void Fracao::setden(int x)
{
    den=x;
}

int Fracao::getnum() const
{
    return num;
}

int Fracao::getden() const
{
    return den;
}

Fracao Fracao::operator*(Fracao x)
{
    x.num = x.num * this->num;
    x.den = x.den * this->den;
    
    return x;
}

Fracao& Fracao::operator*=(const Fracao &x)
{
    num *= x.num;
    den *= x.den;
    
    return *this;
}

bool operator==(Fracao a, Fracao b)
{
    if(a.getnum() == b.getnum() && a.getden() == b.getden())
        return true;
    else
        return false;
}

bool operator!=(Fracao a, Fracao b)
{
    return !(a == b);
}

Fracao& Fracao::operator ++()
{
    this->num += this->den;
    return *this;
}

const Fracao Fracao::operator++(int x)
{
    Fracao a = *this;
    this->num += den;
    return a;
}