#include "Map.h"

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

Map::~Map()
{
    for(auto& it: ocean)
    {
        delete it;
        it = nullptr;
    }
    
    for(auto& it: harbors)
    {
        delete it;
        it = nullptr;
    }
}