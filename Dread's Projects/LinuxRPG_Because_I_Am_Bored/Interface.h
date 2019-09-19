#ifndef INTERFACE_H
#define INTERFACE_H

#include "includes.h"

class Interface
{
public:
    Interface();
    Interface(const Interface& orig);
    
    void WelcomeScreen();
    void ClearScreen();
    
    virtual ~Interface();
    
private:

    
};

#endif