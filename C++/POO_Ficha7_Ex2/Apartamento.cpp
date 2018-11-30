#include "Apartamento.h"

Apartamento::Apartamento(int a, int b, int c): Imovel(a, 10*a, b), quartos(c) {}

string Apartamento::getInfo() const
{
    ostringstream os;
    
    os << "APARTAMENTO" << endl;
    os << Imovel::getInfo() << " " << quartos;
    
    return os.str();
}

Apartamento::~Apartamento() {}