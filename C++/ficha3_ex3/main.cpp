#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include "classRetangulo.h"

int main(int argc, char** argv) 
{
    Ponto p1(2,3);
    Retangulo r1(p1,4,3);
    Retangulo r2(p1,10,2);
    
    cout << "Area: " <<r1.getArea() << endl;
    cout << r1.getCanto() << endl;
    cout << r1.getAsString() << endl;
    
    return 0;
}

