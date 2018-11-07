#ifndef MOVIMENTOS_H
#define MOVIMENTOS_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Movimentos
{
    const string name;
    int saldo;
    vector <int> mov;
    
public:
    Movimentos(string a, int b);
    
    void setSaldo(int x);
    int &getSaldo();
    bool addMov(int x);
    
    Movimentos& operator+=(int x);
    Movimentos& operator-=(int x);
};

Movimentos operator+(Movimentos a, int b);
Movimentos operator-(Movimentos a, int b);

#endif /* MOVIMENTOS_H */

