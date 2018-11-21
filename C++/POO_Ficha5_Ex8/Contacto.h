#ifndef CONTACTO_H
#define CONTACTO_H

#include "headers.h"

class Contacto
{
    string nome;
    int tel;

public:
    
    Contacto();
    Contacto(string a, int b);
    Contacto(const Contacto& orig);
    
    string getNome() const;
    int getTel() const;
    
    void setTel(int a);
    
    virtual ~Contacto();
};

#endif