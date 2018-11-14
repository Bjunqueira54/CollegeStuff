#include "ABC.h"

using namespace std;

void func(ABC y)
{
    cout << "F: " << y.getTxt() << endl;
}

int main(int argc, char** argv)
{
    ABC *p = new ABC("Ola Mundo");
    ABC a("ABCDEF");
    
    cout << p->getTxt() << endl;
    cout << a.getTxt() << endl;
    
    delete p;
    
    ///////////////////////////////////////////////
    
    ABC x("Ola Mundo Outra Vez");
    
    func(x);
    
    cout << x.getTxt() << endl;
    
    ///////////////////////////////////////////////
    
    ABC A("AAAA");
    ABC B("BBBB");
    ABC C("CCCC");
    
    A = B;
    C = C;
    
    cout << C.getTxt() << endl;
    cout << A.getTxt() << endl;
    
    return 0;
}

