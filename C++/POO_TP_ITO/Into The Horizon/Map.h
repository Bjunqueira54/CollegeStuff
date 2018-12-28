#ifndef MAP_H
#define MAP_H

#include "headers.h"
#include "Harbor.h"
#include "Ocean.h"

class Map
{
    vector <Harbor*> harbors;
    vector <Ocean*> ocean;
    const int height, width;
    static int coordcall;
    
public:
    
    //Map();
    //Map(const Map& orig);
    Map(vector<string> vmap);
    
    const string getDim() const;
    const string getTileCoord() const;
    const int getTotalOceanTiles() const { return ocean.size(); }
    const int getTotalHarborTiles() const { return harbors.size(); }
    const bool harborIsFriendly(int yy, int xx) const;
    
    virtual ~Map();
};

#endif