#include "Map.h"
#include "Functions.h"

Map::Map()
{
    
}

Map::Map(vector<string> v)
{
    for(int i=0; i<v.size(); i++)
    {
        g_map.push_back(v[i]);
    }
    
    int i = g_map.size();
    int j = g_map[0].size();
    int y=0, x;
    vector<int> t;
    
    do
    {
        for(x=0; x<j; x++)
            t.push_back(1);
        g_fish.push_back(t);
        y++;
    }
    while(y < i);
    
    g_ships.push_back(nullptr);
    
    setHarbors();
}

Map::Map(const Map& orig)
{
    for(int i=0; i<orig.getMap().size(); i++)
        g_map.push_back(orig.getMap()[i]);
    
    for(int i=0; i<orig.getFish().size(); i++)
        g_fish.push_back(orig.getFish()[i]);
    
    for(int i=0; i<g_ships.size(); i++)
        g_ships.push_back(orig.getShips()[i]);
    
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
    
    for(int i=0; i<g_ships.size(); i++)
        g_ships.push_back(orig.getShips()[i]);
    
    setHarbors();
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

const int Map::getShipId(int y, int x) const
{
    ostringstream os;
    os << y << " " << x;
    for(int i=0; i<g_ships.size(); i++)
    {
        if(g_ships[i]->GetCoord() == os.str())
            return g_ships[i]->GetId();
    }
    return 0;
}

const char Map::getShipType(int y, int x) const
{
    ostringstream os;
    os << y << " " << x;
    for(int i=0; i<g_ships.size(); i++)
        if(g_ships[i]->GetCoord() == os.str())
            return g_ships[i]->GetType();
    return '\0';
}

void Map::setHarbors()
{
    for(int y=0; y<g_map.size(); y++)
    {
        for(int x=0; x<g_map[y].size(); x++)
        {
            if((g_map[y][x]>='A' && g_map[y][x] <='Z') || (g_map[y][x] >='a' && g_map[y][x] <= 'z'))
                harbors.push_back(new Harbor(y, x, g_map[y][x]));
        }
    }
}

void Map::setMainHarbors()
{
    if(harbors.empty())
        return;
    
    vector<Harbor*> fports;
    
    for(int i=0; i<harbors.size(); i++)
    {
        if(harbors[i]->getState() == true)
            fports.push_back(harbors[i]);
    }
    
    mt19937 rng(time(NULL));
    uniform_int_distribution<int> mh(0, fports.size()-1);
    
    player->SetMainHarbor(fports[mh(rng)]);
    pirates->SetMainHarbor(nullptr);
}

void Map::newShip(char t)
{
    if(g_ships[0] == nullptr)
    {
        g_ships[0] = player->newShip(t);
    }
    else
        g_ships.push_back(player->newShip(t));
}

bool Map::sellShip(int id)
{
    if(player->sellShip(id) == true)
    {
        for(int i=0; i<g_ships.size(); i++)
        {
            if(g_ships[i]->GetId() == id)
            {
                auto it = g_ships.begin() + i;
                delete *it;
                g_ships.erase(it);
                return true;
            }
        }
    }
    
    return false;
}

int Map::move(int id, string dir)
{
    istringstream is;
    istringstream cur;
    istringstream des;
    int y, x, dy, dx;
    char c;
    
    for(int i=0; i<g_ships.size(); i++)
    {
        if(g_ships[i]->GetId() == id && g_ships[i]->getOwner() == player)
        {
            is.str(dir);
            
            while(g_ships[i]->GetMovesl() != 0)
            {
                is >> c;
                if(!is.good())
                    break;
                
                if(move(i, c))
                    g_ships[i]->setMovesl(1);
            }
            
            return 0;
        }
    }
    return -1;
}

bool Map::move(int id, char c)
{
    istringstream dest;
    istringstream curr;
    int y, x, dy, dx;
    
    dest.str(g_ships[id]->GetDest());
    dest >> dy;
    dest >> dx;
    
    y=dy;
    x=dx;
    
    if(c == 'E' || c == 'e')
    {
        if(dx>0)
            dx--;
        else
            dx = g_map[y].size() - 1;
    }
    else if(c == 'D' || c == 'd')
    {
        if(dx < g_map[y].size()-1)
            dx++;
        else
            dx = 0;
    }
    else if(c == 'C' || c == 'c')
    {
        if(dy>0)
            dy--;
        else
            dy = g_map.size() - 1;
    }
    else if(c == 'B' || c == 'b')
    {
        if(dy<g_map.size() - 1)
            dy++;
        else
            dy = 0;
    }
    else
        return false;
    
    if(g_map[dy][dx] == '+' || g_map[dy][dx] == '^' || g_map[dy][dx] == '*' || g_map[dy][dx] == '@')
        return false;
    else
        g_ships[id]->setDest(dy, dx);
    
    if(!((g_map[y][x]>='A' && g_map[y][x]<='Z') || (g_map[y][x]>='a' && g_map[y][x]<='z')))
        g_map[y][x] = '.';
    else
        g_ships[id]->toggleHarbor();
    
    if(!( (g_map[dy][dx]>='A' && g_map[dy][dx]<='Z') || (g_map[dy][dx]>='a' && g_map[dy][dx]<='z') ))
        g_map[dy][dx] = '^';
    else
        g_ships[id]->toggleHarbor();
    
    return true;
}

Map::~Map()
{
    for(auto it = harbors.begin(); it != harbors.end();)
    {
        delete *it;
        harbors.erase(it);
    }
}