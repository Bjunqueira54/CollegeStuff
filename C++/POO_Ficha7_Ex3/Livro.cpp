#include "Livro.h"

Livro::Livro(string a, string b, string c): titulo(a), autor(b), isbn(c) {}

Livro::Livro(const Livro& orig): Livro(orig.titulo, orig.autor, orig.isbn) {}

Livro::~Livro() {}

string Livro::getTitulo() const
{return titulo;}

string Livro::getAutor() const
{return autor;}

string Livro::getIsbn() const
{return isbn;}

string Livro::getInfo() const
{
    ostringstream os;
    os << "Titulo: " << titulo << " | Autor: " << autor << " | ISBN: " << isbn << endl;
    return os.str();
}

bool Livro::operator ==(const Livro& a)
{
    if(isbn == a.isbn)
        return true;
    else 
        return false;
}

ostream& operator <<(ostream& out, Livro &a)
{
    out << a.getInfo();
    return out;
}

Livro* Livro::clone()
{return new Livro(*this);}