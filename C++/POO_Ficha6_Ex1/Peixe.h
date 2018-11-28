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
    bool vivo = true;
    
public:
    
    Peixe(string a, string b="cizento", int p=50);
    Peixe(const Peixe& orig);
    
    int getId() const;
    
    string getCor() const {return cor; }
    int getPeso() const {return peso;}
    string getNome() const {return nome;}
    
    string getInfo() const;
    void ligaAq(Aquario *a);
    bool queroSair();
    void setPeso(int n) {peso = n;}
    
    virtual void comer(int n);
    
    virtual ~Peixe();
    
};

class Piranha: public Peixe
{
    
public:
    Piranha(string a, string b="Cinzento");
    
    virtual void comer(int n);
};

#endif