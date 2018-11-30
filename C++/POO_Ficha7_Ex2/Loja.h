#ifndef LOJA_H
#define LOJA_H

#include "Imovel.h"

class Loja: public Imovel
{
    
public:
    
    Loja(int a);
    
    virtual string getInfo() const;
    
    virtual ~Loja();
    
private:

};

#endif