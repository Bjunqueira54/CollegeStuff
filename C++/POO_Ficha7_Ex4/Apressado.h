#ifndef APRESSADO_H
#define APRESSADO_H

#include "Tarifario.h"

class Apressado: public Tarifario
{
    
public:
    
    Apressado();
    Apressado(const Apressado& orig);
    
    virtual int calculaPagamento();
    
    virtual ~Apressado();
};

#endif