#include "Biblio.h"
#include "Livro.h"

Biblio::Biblio(string a): morada(a) {}

Biblio::Biblio(const Biblio& orig)
{
    morada = orig.morada;
    
    for(int i=0; i<orig.v.size(); i++)
    {
        v.push_back(orig.v[i]->clone());
    }
}

Biblio::~Biblio() {}

bool Biblio::addLivro(Livro *a)
{
    for(int i=0; i<v.size(); i++)
    {
        if(a->getIsbn() == v[i]->getIsbn())
        {
            delete a;
            return false;
        }
    }
    v.push_back(a);
    return true;
}

ostream& operator<<(ostream& out, Biblio &a)
{
    out << a.getInfo();
    return out;
}

string Biblio::getInfo() const
{
    ostringstream os;
    for(int i=0; i<v.size(); i++)
    {
        os << v[i]->getInfo() << endl;
    }
    return os.str();     
}

//biblioteca tem de ter um destrutor que destroi objetos e livros
//construtor por copia