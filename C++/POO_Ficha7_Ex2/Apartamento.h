#ifndef APARTAMENTO_H
#define APARTAMENTO_H

#include "Imovel.h"

class Apartamento: public Imovel
{
    int quartos;
    
public:
    
    Apartamento(int i, int a, int q);
    
    virtual string getInfo() const;
    
    virtual ~Apartamento();
    
private:

};

#endif