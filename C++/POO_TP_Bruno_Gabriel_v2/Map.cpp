#include "Map.h"

Map::Map()
{
    
}

Map::Map(vector<string> v)
{
    for(int i=0; i<v.size(); i++)
    {
        g_map.push_back(v[i]);
    }
}

Map::Map(const Map& orig)
{
    for(int i=0; i<orig.getMap().size(); i++)
        g_map.push_back(orig.getMap()[i]);
    
    for(int i=0; i<orig.getFish().size(); i++)
        g_fish.push_back(orig.getFish()[i]);
}

Map& Map::operator =(const Map& orig)
{
    if(this == &orig)
        return *this;
    
    for(int i=0; i<orig.getMap().size(); i++)
        g_map.push_back(orig.getMap()[i]);
    
    for(int i=0; i<orig.getFish().size(); i++)
        g_fish.push_back(orig.getFish()[i]);
}

Map::~Map()
{
    
}