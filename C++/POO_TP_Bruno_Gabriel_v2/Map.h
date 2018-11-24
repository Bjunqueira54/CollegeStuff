#ifndef MAP_H
#define MAP_H

#include "headers.h"
#include "Harbor.h"

class Map
{
    vector <string> g_map;
    vector<vector<int>> g_fish;
    vector<Harbor*> harbors;
    
public:
    
    Map();
    Map(vector<string> smap);
    Map(const Map& orig);
    
    Map& operator=(const Map& orig);
    
    //Gets
    
    vector<string> getMap() const
    {return g_map;}

    vector<vector<int>> getFish() const
    {return g_fish;}
    
    const bool getHarborState(int y, int x) const;
    const char getHarborId(int y, int x) const;
    
    //Sets
    
    void setHarbors();
    
    virtual ~Map();
};

#endif