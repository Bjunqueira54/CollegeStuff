#ifndef PREGO_H
#define PREGO_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Prego
{
    int x, y;
    
public:
    
    Prego(int a, int b): x(a), y(b)
    {
        cout << "Contruir Prego" << x << "," << y << endl;
    }
    
    ~Prego()
    {
        cout << "Destruir Prego" << x << "," << y << endl;
    }
    
    void MudaDeSitio(int nx, int ny)
    {
        x=nx;
        y=ny;
    }
    
    string GetLocal() const
    {
        ostringstream os;
        os << x << "," << y;
        return os.str();
    }

};

#endif /* PREGO_H */