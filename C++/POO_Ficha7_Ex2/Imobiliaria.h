#ifndef IMOBILIARIA_H
#define IMOBILIARIA_H

#include "headers.h"
#include "Imovel.h"

class Imobiliaria
{
    const string nome;
    vector<Imovel*> imoveis;
    
public:
    
    Imobiliaria(string a);
    Imobiliaria(const Imobiliaria& orig);
    
    Imovel* addImovel(const Imovel *a);
    
    virtual ~Imobiliaria();
    
private:

};

#endif