#include "Aquario.h"

Aquario::Aquario(string a): nome(a) {}

Aquario::Aquario(const Aquario& orig) {}

void Aquario::addPeixe(Peixe* p)
{
    v.push_back(p);
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
        os << v[i]->getInfo();
    
    return os.str();
}

Aquario::~Aquario() {}

ostream& operator<<(ostream& out, Aquario &a)
{
    out << a.getInfo() << endl;
        
    return out;
}