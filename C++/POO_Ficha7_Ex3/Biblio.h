#ifndef BIBLIO_H
#define BIBLIO_H

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#include "Livro.h"

using namespace std;

class Biblio
{
    string morada;
    vector <Livro*> v;
    
public:
    
    Biblio(string a);
    Biblio(const Biblio& orig);
    virtual ~Biblio();

    bool addLivro(Livro *a); //nao se pode repetir livro
    string getInfo() const;
};

ostream& operator<<(ostream& out, Biblio &a);

#endif /* BIBLIO_H */

