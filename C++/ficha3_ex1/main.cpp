#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include "classPonto.h"

int main(int argc, char** argv) 
{
    Ponto p1(2,3);
    Ponto p2(4,-5);
    const Ponto p3(2,1);
    
    cout << "Coord. x: " << p1.getx() << endl << "Coord. y: " << p1.gety() << endl;
    p2.sety(2);
    cout << "Distancia: " << p1.getDist(p2) << endl;  
    cout << p1.getAsString() << endl;
    
    p1.mover(2,-1).mover(1,3);
    cout << p1.getAsString() << endl;
    
    return 0;
}

