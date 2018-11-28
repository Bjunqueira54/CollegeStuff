#include "Peixe.h"
#include "Aquario.h"

int Peixe::conta=500;

Peixe::Peixe(string a, string b, int p): nome(a), cor(b), peso(p), id(conta++), p(nullptr) {}

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

void Peixe::comer(int n)
{
    if(!vivo)
        return;

    peso += n;
    
    if(peso > 50)
    {
        mt19937 rng(time(NULL));
        uniform_real_distribution<double> chance(0.00, 100.00);
        
        if(chance(rng) >= 50.00)
            vivo = false;
        else
        {
            p->addPeixe(new Peixe(nome, cor, 10));
            peso = 40;
        }
    }
}

Peixe::~Peixe(){}

Piranha::Piranha(string a, string b):Peixe("Piranha "+a, b) {}

void Piranha::comer(int n)
{
    setPeso(getPeso() + 2 * n);
}