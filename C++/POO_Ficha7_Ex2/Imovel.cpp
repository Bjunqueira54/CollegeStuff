#include "Imovel.h"

int Imovel::conta = 1;

Imovel::Imovel(int a, int b, int c): area(a), preco(b), andar(c), id(conta++) {}

Imovel::Imovel(const Imovel& orig) {}

string Imovel::getInfo() const
{
    ostringstream os;
    
    os << id << " " << area << " " << preco << " " << andar;
    
    return os.str();
}

Imovel::~Imovel() {}