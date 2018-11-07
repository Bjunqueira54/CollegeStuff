#ifndef FRACAO_H
#define FRACAO_H

#include <cstdlib>
#include <iostream>

using namespace std;

class Fracao
{
    int num, den;
    
public:
    
    Fracao(int a=0, int b=1);
    
    void setnum(int x);
    void setden(int x);
    int getnum() const;
    int getden() const;
    
    Fracao operator*(Fracao x);
    Fracao& operator*=(const Fracao &x);
    Fracao& operator++();
    const Fracao operator++(int x);
};

bool operator==(Fracao a, Fracao b);
bool operator!=(Fracao a, Fracao b);

#endif

