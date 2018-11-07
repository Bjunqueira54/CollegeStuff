#ifndef EX1_H
#define EX1_H

#include "libs.h"
#include <cmath>

using namespace std;

class Ponto
{
    int x,y;
    
public:
    Ponto(int a, int b): x(a), y(b) {}
    
    int getx()
    {
        return x;
    }
    
    int gety()
    {
        return y;
    }
    
    int setx(int a)
    {
        x = a;
    }
    
    int sety(int b)
    {
        y = b;
    }
    
    Ponto& mover(int dx, int dy)
    {
        x += dx;
        y += dy;
        
        return *this;
    }
    
    double getDist(Ponto p2)
    {
        int cx, cy;
        double h; 
        
        cx = x - p2.x;
        cy = y - p2.y;       
        h = sqrt((cx*cx) + (cy*cy));
        
        return h;
    }
    
    string getAsString() const
    {
        ostringstream os;        
        os << "Ponto(" << x << "," << y << ")" << endl; 
        return os.str();
    }
};

#endif /* EX1_H */

