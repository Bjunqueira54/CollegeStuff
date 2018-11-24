#ifndef HARBOR_H
#define HARBOR_H

#include "headers.h"

class Harbor 
{
    const int y, x;
    const char id;
    bool friendly;
    
public:
    
    Harbor(int yy, int xx, char i);
    
    //Get
    const string getCoord() const;
    const bool getState() const {return friendly;}
    const char getId() const {return id;}
    
    //Set
    void toggleState();
};

#endif