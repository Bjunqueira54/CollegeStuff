#include "Policial.h"

Policial::Policial(string a, string b, string c, string d, int e): Livro(a,b,c), nomeD(c), numT(e) {}

Policial::Policial(const Policial& orig): Livro(orig.getTitulo(), orig.getAutor(), orig.getIsbn()), nomeD(orig.nomeD), numT(orig.numT) {}

Policial::~Policial() {}

string Policial::getInfo() const
{
    ostringstream os;
    os << Livro::getInfo() << "Nome Detetive: " << nomeD << " | Numero Tiros: " << numT << endl;;
    return os.str();
}

Policial* Policial::clone()
{return new Policial(*this);}