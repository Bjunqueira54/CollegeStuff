#ifndef FC_H
#define FC_H

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#include "Livro.h"

using namespace std;

//Ficcao Cientifica
class FC: public Livro
{
    string planeta;
    int ano;
    bool realista;
    
public:
    
    FC(string a, string b, string c, string d, int e, bool f);
    FC(const FC& orig);
    virtual ~FC();
    
    virtual string getInfo() const;
    
    virtual FC* clone();
};

#endif /* FC_H */
