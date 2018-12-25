#ifndef INTERFACE_H
#define INTERFACE_H

#include "headers.h"

class Interface
{
    
public:
    
    Interface();
    Interface(const Interface& orig);
    
    void SetScreenSize(int lines, int columns);
    
    virtual ~Interface();
};

#endif