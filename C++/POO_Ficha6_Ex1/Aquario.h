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
    bool removePeixe(int id);
    void alimenta(int n);
    
    Aquario& operator=(const Aquario& orig) = delete;
    
    virtual ~Aquario();
    
};

ostream& operator<<(ostream& out, Aquario &a);

#endif