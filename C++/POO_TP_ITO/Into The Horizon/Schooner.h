#ifndef SCHOONER_H
#define SCHOONER_H

class Schooner: public Ship
{
    
public:
    
    Schooner();
    Schooner(const Schooner& orig);
    virtual ~Schooner();
};

#endif