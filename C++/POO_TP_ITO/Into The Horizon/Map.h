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
    
    virtual ~Map();
};

#endif