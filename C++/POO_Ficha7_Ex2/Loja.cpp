#include "Loja.h"

Loja::Loja(int a): Imovel(a, 15*a, 0) {}

string Loja::getInfo() const
{
    ostringstream os;
    
    os << "LOJA" << endl;
    os << Imovel::getInfo() << endl;
    
    return os.str();
}

Loja::~Loja() {}