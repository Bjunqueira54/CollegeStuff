#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class Pessoa
{
    string nome;
    int cc, nif;
    
public:
    
    Pessoa(string a, int b, int c);
    
    string getNome() const;
    
    void setNome(string n);
    
    string getAsString() const;
    
    int getCC() const;
};

#endif /* PESSOA_H */

