#ifndef GALEON_H
#define GALEON_H

class Galeon: public Ship
{
    
public:
    
    Galeon();
    Galeon(const Galeon& orig);
    virtual ~Galeon();
};

#endif