#ifndef EX3_H
#define EX3_H

#include "../ficha3_ex1/libs.h"
#include "../ficha3_ex1/classPonto.h"

/* Retangulo(Ponto a, int b, int c): cse(a.getx(),a.gety()), alt(b), larg(c) {} -> também funciona */

using namespace std;

class Retangulo
{
    Ponto cse;  // canto superior esquerdo
    int alt, larg;
    
public:  
    Retangulo(Ponto a, int b, int c): cse(a), alt(b), larg(c) {}
    
    int getArea()
    {
        return (alt*larg);
    }
    
    int getlarg()
    {
        return larg;
    }
    
    int getalt()
    {
        return alt;
    }
    
    Ponto getCanto()
    {
        return cse;
    }
    
    string getAsString() const
    {
        ostringstream os;
        os << "CSE: " << cse.getAsString() << "Altura: " << alt << endl << "Largura: " << larg << endl;
        return os.str();
    }
};

#endif /* EX3_H */