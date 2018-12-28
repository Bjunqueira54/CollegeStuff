#include "Map.h"

int Map::coordcall = 0;

/*Map::Map() {}

Map::Map(const Map& orig) {}*/

Map::Map(vector<string> vmap): height(vmap.size()), width(vmap[0].size())
{
    int y, x;
    
    for(y=1; y<=vmap.size(); y++)
    {
	for(x=1; x<=vmap[y-1].size(); x++)
	{
	    if(vmap[y-1][x-1] == '.')
		ocean.push_back(new Ocean(y, x));
	    else if((vmap[y-1][x-1] >= 'a' && vmap[y-1][x-1] <= 'z') || (vmap[y-1][x-1] >= 'A' && vmap[y-1][x-1] <= 'Z'))
		harbors.push_back(new Harbor(vmap[y-1][x-1], y, x));
	}
    }
}

const string Map::getDim() const
{
    ostringstream os;
    
    os << height << " " << width;
    
    return os.str();
}

const string Map::getTileCoord() const
{
    ostringstream os;
    int i;
    
    i = coordcall;
    coordcall++;
    
    if(i < ocean.size())
    {
        return ocean[i]->getCoord();
    }
    else if(i >= ocean.size())
    {
        if(i - ocean.size() < harbors.size())
        {
            return harbors[i - ocean.size()]->getCoord();
        }
        else
            coordcall = 0;
    }
}

const bool Map::harborIsFriendly(int yy, int xx) const
{
    string coord;
    
    coord = yy + " " + xx;
    
    for(int i=0; i<harbors.size(); i++)
    {
        if(coord == harbors[i]->getCoord())
            return harbors[i]->isFriendly();
    }
}

Map::~Map() {}