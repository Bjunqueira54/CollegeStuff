#include "Agenda.h"

Agenda::Agenda() {}

Agenda::Agenda(const Agenda& orig)
{
    for(int i=0; i<orig.v.size(); i++)
    {
        v.push_back((new Contacto(orig.v[i]->getNome(), orig.v[i]->getTel())));
    }
}

bool Agenda::addContacto(string a, int b)
{
    v.push_back(new Contacto(a, b));
}

string Agenda::getTel(string a) const
{
    ostringstream os;
    for(int i=0; i<v.size(); i++)
    {
        if(v[i]->getNome() == a)
        {
            ostringstream os;
            os << v[i]->getTel();
            return os.str();
        }
    }
}

bool Agenda::atualizaContacto(string a, int b)
{
    for(auto &it: v)
    {
        if(it->getNome() == a)
        {
            it->setTel(b);
            return true;
        }
    }
    return false;
}

bool Agenda::eliminaContacto(int a)
{
    for(int i=0; i<v.size(); i++)
    {
        if(v[i]->getTel() == a)
        {
            delete v[i];
            v.erase(v.begin() + i);
            return true;
        }
    }
    return false;
}

string Agenda::getString() const
{
    ostringstream os;
    for(int i=0; i<v.size(); i++)
        os << "Nome: " << v[i]->getNome() << " Tel.: " << v[i]->getTel() << endl;
    
    return os.str();
}

ostream& operator<<(ostream& out, Agenda &a)
{
    out << a.getString() << endl;
    
    return out;
}

Agenda::~Agenda()
{
    for(int i=0; i<v.size(); i++)
        delete v[i];
}