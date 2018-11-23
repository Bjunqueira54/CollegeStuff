#include "Peixe.h"
#include "Aquario.h"

int Peixe::conta=500;

Peixe::Peixe(string a, string b): nome(a), cor(b), peso(50), id(conta++), p(nullptr) {}

Peixe::Peixe(const Peixe& orig){}

int Peixe::getId() const
{
    return id;
}

string Peixe::getInfo() const
{
    ostringstream os;
    
    os << "Nome: " << nome << " ID: " << id << " Peso: " << peso << " Cor: " << cor;
    
    return os.str();
}

void Peixe::ligaAq(Aquario* a)
{
    p = a;
}

bool Peixe::queroSair()
{
    if(p==nullptr)
        return false;
    
    if(p->removePeixe(id) == true)
    {
        p = nullptr;
        return true;
    }
    else
        return false;
}

Peixe::~Peixe(){}