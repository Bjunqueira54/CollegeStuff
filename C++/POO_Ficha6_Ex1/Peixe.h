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
    
    string getCor() const {
        return cor;
    }

    string getNome() const {
        return nome;
    }
    
    string getInfo() const;
    void ligaAq(Aquario *a);
    bool queroSair();
    
    virtual ~Peixe();
    
};

#endif