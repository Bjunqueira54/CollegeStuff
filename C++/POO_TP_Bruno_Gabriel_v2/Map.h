#ifndef MAP_H
#define MAP_H

#include "headers.h"

class Map
{
    vector <string> g_map;
    vector<vector<int>> g_fish;
    
public:
    
    Map();
    Map(vector<string> smap);
    Map(const Map& orig);
    
    Map& operator=(const Map& orig);
    
    vector<string> getMap() const
    {return g_map;}

    vector<vector<int>> getFish() const
    {return g_fish;}
    
    virtual ~Map();
};

#endif