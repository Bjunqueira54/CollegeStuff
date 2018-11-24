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
    
    setHarbors();
}

Map::Map(const Map& orig)
{
    for(int i=0; i<orig.getMap().size(); i++)
        g_map.push_back(orig.getMap()[i]);
    
    for(int i=0; i<orig.getFish().size(); i++)
        g_fish.push_back(orig.getFish()[i]);
    
    setHarbors();
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

const bool Map::getHarborState(int y, int x) const
{
    ostringstream os;
    os << y << " " << x;
    
    for(int i=0; i<harbors.size(); i++)
    {
        if(harbors[i]->getCoord() == os.str())
        {
            return harbors[i]->getState();
        }
    }
    
    return false;
}

const char Map::getHarborId(int y, int x) const
{
    ostringstream os;
    
    os << y << " " << x;
    
    for(int i=0; i<harbors.size(); i++)
    {
        if(harbors[i]->getCoord() == os.str())
            return harbors[i]->getId();
    }
    
    return ' ';
}

void Map::setHarbors()
{
    for(int y=0; y<g_map.size(); y++)
    {
        for(int x=0; x<g_map[y].size(); x++)
        {
            if((g_map[y][x]>='A' && g_map[y][x] <='Z') || (g_map[y][x] >='a' && g_map[y][x] <= 'z'))
                harbors.push_back(new Harbor(y+1, x+1, g_map[y][x]));
        }
    }
}

Map::~Map()
{
    for(auto it = harbors.begin(); it != harbors.end();)
    {
        delete *it;
        harbors.erase(it);
    }
}