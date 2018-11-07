#include "Pessoa.h"

Pessoa::Pessoa(string a, int b, int c): nome(a), cc(b), nif(c){}

string Pessoa::getNome() const
{
    return nome;
}

void Pessoa::setNome(string n)
{
    nome = n;
}

string Pessoa::getAsString() const
{
    ostringstream os;
    os << "Nome: " << nome << "\nCC: " << cc << "\nNIF: " << nif << endl;
    return os.str();
}

int Pessoa::getCC() const
{
    return cc;
}