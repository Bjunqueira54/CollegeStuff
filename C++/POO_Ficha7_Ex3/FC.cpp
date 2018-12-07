#include "FC.h"

FC::FC(string a, string b, string c, string d, int e, bool f): Livro(a,b,c), planeta(d), ano(e), realista(f) {}

FC::FC(const FC& orig): Livro(orig.getTitulo(), orig.getAutor(), orig.getIsbn()), planeta(orig.planeta), ano(orig.ano), realista(orig.realista) {}

FC::~FC() {}

string FC::getInfo() const
{
    ostringstream os;
    os << Livro::getInfo() << "Planeta: " << planeta << " | Ano: " << ano << " | Realista: " << realista << endl;;
    return os.str();
}

FC* FC::clone()
{return new FC(*this);}