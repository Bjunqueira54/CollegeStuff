#ifndef POLICIAL_H
#define POLICIAL_H

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#include "Livro.h"

using namespace std;

class Policial: public Livro
{
    string nomeD;   //nome detetive
    int numT;       //numero tiros disparados
public:
    
    Policial(string a, string b, string c, string d, int e);
    Policial(const Policial& orig);
    virtual ~Policial();
    
    virtual string getInfo() const;
    
    virtual Policial* clone();
};

#endif /* POLICIAL_H */

