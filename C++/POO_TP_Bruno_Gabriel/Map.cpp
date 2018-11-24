#include "Map.h"
#include "Player.h"

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
                char c = g_Map[y][x];
                ports.push_back(Harbor(y, x, c));
            }
        }
    }
}

void Map::readPlayerFleet(const Player& player)
{
    for(int i=0; i<player.getFleet().size(); i++)
    {
        for(int j=0; j<ships.size(); j++)
        {
            if(player.getFleet()[i].getId() == ships[j].getId())
                break;
        }
        ships.push_back(player.getFleet()[i]);
    }
}

const vector<Ship> Map::getShips() const
{
    return ships;
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

const string Map::getHarborCoord(char id) const
{
    for(int i=0; i<ports.size(); i++)
        if(ports[i].getId() == id)
            return ports[i].getCoord();
}

const Harbor* Map::getHarborByCoord(int y, int x) const
{
    ostringstream os;
    os << x << " " << y;
    
    for(int i=0; i<ports.size(); i++)
    {
        if(os.str() == ports[i].getCoord())
            return &ports[i];
    }
    
    return nullptr;
}

vector<string> Map::getMap() const
{
    return g_Map;
}