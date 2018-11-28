#include "Aquario.h"

Aquario::Aquario(string a): nome(a) {}

Aquario::Aquario(const Aquario& orig)
{
    nome = orig.nome;
    
    for(int i=0; i<orig.v.size(); i++)
    {
        v.push_back(new Peixe(orig.v[i]->getNome(), orig.v[i]->getCor()));
        v[i]->ligaAq(this);
    }
}

void Aquario::addPeixe(Peixe* p)
{
    v.push_back(p);
    p->ligaAq(this);
}

bool Aquario::verificaPeixe(int id) const
{
    for(int i=0; i<v.size(); i++)
    {
        if(id == v[i]->getId())
            return true;
    }
    return false;
}

string Aquario::getInfo() const
{
    ostringstream os;
    
    for(int i=0; i<v.size(); i++)
        os << v[i]->getInfo() << endl;
    
    return os.str();
}

bool Aquario::removePeixe(int id)
{
    for(int i=0; i<v.size(); i++)
    {
        if(id == v[i]->getId())
        {
            auto it = v.begin();
            it += i;
            v.erase(it);
            return true;
        }
    }
    return false;
}

void Aquario::alimenta(int n)
{
    for(int i=0; i<v.size(); i++)
        v[i]->comer(n);

}

Aquario::~Aquario() {}

ostream& operator<<(ostream& out, Aquario &a)
{
    out << a.getInfo();
        
    return out;
}