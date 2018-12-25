#ifndef FRIGATE_H
#define FRIGATE_H

class Frigate: public Ship
{
    
public:
    
    Frigate();
    Frigate(const Frigate& orig);
    virtual ~Frigate();
};

#endif