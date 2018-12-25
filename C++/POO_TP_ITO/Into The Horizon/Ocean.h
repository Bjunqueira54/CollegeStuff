#ifndef OCEAN_H
#define OCEAN_H

class Ocean: public Tile
{
    
public:
    
    Ocean();
    Ocean(const Ocean& orig);
    virtual ~Ocean();
};

#endif