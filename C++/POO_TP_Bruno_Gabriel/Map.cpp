#include "Map.h"

vector<string> Map::g_Map;
vector<Harbor> Map::ports;

Map::Map() {}

Map::Map(ifstream &file)
{
    file.seekg(ios::beg);
    string mapline;
    
    do
    {
        getline(file, mapline);
        g_Map.push_back(mapline);
    }
    while(mapline != "");
    
    g_Map.pop_back();
}

Map& Map::operator =(const Map& orig)
{
    g_Map = orig.g_Map;
}

void Map::CreateHarborVector()
{
    for(int y=0; y<g_Map.size(); y++)
    {
        for(int x=0; x<g_Map[y].size(); x++)
        {
            if((g_Map[y][x] >= 'A' && g_Map[y][x] <= 'Z') || (g_Map[y][x] >= 'a' && g_Map[y][x] <= 'z'))
            {
                ports.push_back(Harbor(y, x, g_Map[y][x]));
            }
        }
    }
}

vector<Harbor> Map::getFriendlyHarbors() const
{
    vector<Harbor> fPorts;
    
    for(int i=0; i<ports.size(); i++)
    {
        if(ports[i].isFriend() == true)
        {
            fPorts.push_back(ports[i]);
        }
    }
    return fPorts;
}

vector<string> Map::getMap() const
{
    return g_Map;
}