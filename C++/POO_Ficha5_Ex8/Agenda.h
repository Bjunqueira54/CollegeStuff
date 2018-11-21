#ifndef AGENDA_H
#define AGENDA_H

#include "headers.h"
#include "Contacto.h"

class Agenda
{
    vector <Contacto*> v;
    
public:
    
    Agenda();
    Agenda(const Agenda& orig);
    
    bool addContacto(string a, int b);
    
    string getTel(string a) const;
    string getString() const;
    bool atualizaContacto(string a, int b);
    bool eliminaContacto(int a);
    
    virtual ~Agenda();
};

ostream& operator<<(ostream& out, Agenda &a);

#endif