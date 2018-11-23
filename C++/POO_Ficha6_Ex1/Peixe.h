#ifndef PEIXE_H
#define PEIXE_H

#include "headers.h"

class Aquario;

class Peixe
{
    string nome, cor;
    int peso, id;
    static int conta;
    Aquario *p;
    
public:
    
    Peixe(string a, string b="cizento");
    Peixe(const Peixe& orig);
    
    int getId() const;
    string getInfo() const;
    
    virtual ~Peixe();
    
};

#endif