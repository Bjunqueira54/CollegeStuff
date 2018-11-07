#ifndef AVISO_H
#define AVISO_H

#include "Prego.h"

using namespace std;

class Aviso
{
    string txt;
    Prego const *p;
    
public:
    
    Aviso(string a, Prego *b): txt(a), p(b){}
    
    string getInfo() const
    {
        ostringstream os;
        os << "Text: " << txt << p->GetLocal();
        return os.str();
    }
    
    void mudaDePrego(Prego *np)
    {
        p = np;
    }
};

#endif /* AVISO_H */

