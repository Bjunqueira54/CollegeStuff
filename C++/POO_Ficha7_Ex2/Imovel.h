#ifndef IMOVEL_H
#define IMOVEL_H

#include "headers.h"

class Imovel
{
    int area, preco, andar, id;
    static int conta;
    
public:
    
    Imovel(int a, int b, int c);
    Imovel(const Imovel& orig);
    
    int getCodigo() const {return id;}
    int getAndar() const {return andar;}
    virtual string getInfo() const;
    
    virtual ~Imovel();
    
private:

};

#endif