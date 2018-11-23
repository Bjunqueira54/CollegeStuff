#include "Map.h"

vector<string> Map::g_Map;
vector<Harbor> Map::ports;

Map::Map() {}

Map::Map(string filename)
{
    ifstream file;
    file.open(filename, ios::in);
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
    if(this == &orig)
        return *this;
    
    for(int i=0; i<orig.g_Map.size(); i++)
        g_Map.push_back(orig.g_Map[i]);
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

void Map::chooseMainHarbor(Player &player)
{
    vector<Harbor> fPorts;
    int j;
    
    for(int i=0; i<ports.size(); i++)
    {
        if(ports[i].isFriend() == true)
        {
            fPorts.push_back(ports[i]);
        }
    }
    
    mt19937 rng(time(NULL));
    uniform_int_distribution<int> mh(1, fPorts.size());
    j = mh(rng);
    fPorts[j].becomeMain(player);
}

string Map::getHarborCoord(char id) const
{
    for(int i=0; i<ports.size(); i++)
        if(ports[i].getId() == id)
            return ports[i].getCoord();
}

vector<string> Map::getMap() const
{
    return g_Map;
}