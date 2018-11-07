#include "Fracao.h"

ostream& operator<<(ostream &out, const Fracao &a)
{
    out << a.getnum() << "/" << a.getden();
    
    return out;
}

int main(int argc, char** argv)
{
    Fracao a(2,3), b(1,2), c, d(2,4);
    
    c = a * b;
    cout << c << endl;
    
    c = a * b * d;
    cout << c << endl;
    
    c = a * 3;
    cout << c << endl;
    
    d *= a;
    cout << d << endl;
    
    (a *= b) *= c;
    cout << a << endl;
    
    cout << "A == B? " << (a == b) << endl;
    cout << "A != B? " << (a != b) << endl;
    cout << "2 == A? " << (2 == a) << endl;
    
    cout << ++(++a) << endl;
    cout << b++ << endl;
    cout << b << endl;
    
    // Implementa Fracao + Fracao, Fracao - Fracao e Fracao/Fracao
    // Implementar Fracao += Fracao e Fracao -= Fracao
    
    return 0;
}

