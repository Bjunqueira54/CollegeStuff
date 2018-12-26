#ifndef MAP_H
#define MAP_H

#include "headers.h"
#include "Harbor.h"
#include "Ocean.h"

class Map
{
    vector <Harbor*> harbors;
    vector <Ocean*> ocean;
    
public:
    
    Map();
    Map(const Map& orig);
    Map(vector<string> vmap);
    
    
    virtual ~Map();
};

#endif