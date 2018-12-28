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
    
public:
    
    //Map();
    //Map(const Map& orig);
    Map(vector<string> vmap);
    
    const string getDim() const;
    const int getTotalOceanTiles() const { return ocean.size(); }
    const string getOceanCoord(int i) const { return ocean[i]->getCoord(); }
    const int getTotalHarborTiles() const { return harbors.size(); }
    const string getHarborCoord(int i) const { return harbors[i]->getCoord(); }
    const bool harborIsFriendly(int i) const { return harbors[i]->isFriendly(); }
    const char getHarborID(int i) const { return harbors[i]->getID(); }
    
    virtual ~Map();
};

#endif