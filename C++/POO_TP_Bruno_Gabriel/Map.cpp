#include "Map.h"

Map::Map() {}

Map::Map(ifstream &file)
{
    file.seekg(ios::beg);
    string mapline;
    
    do
    {
        getline(file, mapline);
        dMap.push_back(mapline);
    }
    while(mapline != "");
    
    dMap.pop_back();
}

Map& Map::operator =(const Map& orig)
{
    dMap = orig.dMap;
}

vector<string> Map::getMap() const
{
    return dMap;
}