#ifndef AQUARIO_H
#define AQUARIO_H

#include "headers.h"
#include "Peixe.h"

class Aquario
{
    string nome;
    vector<Peixe*> v;
    
public:
    
    Aquario(string a);
    Aquario(const Aquario& orig);
    
    void addPeixe(Peixe *p);
    bool verificaPeixe(int id) const;
    string getInfo() const;
    
    virtual ~Aquario();
    
};

ostream& operator<<(ostream& out, Aquario &a);

#endif