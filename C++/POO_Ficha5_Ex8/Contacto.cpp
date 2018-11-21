#include "Contacto.h"

Contacto::Contacto() {}

Contacto::Contacto(string a, int b): nome(a), tel(b) {}

Contacto::Contacto(const Contacto& orig) {}

string Contacto::getNome() const
{
    return nome;
}

int Contacto::getTel() const
{
    return tel;
}

void Contacto::setTel(int a)
{
    tel = a;
}

Contacto::~Contacto()
{
    cout << "Destruir " << nome << endl;
}