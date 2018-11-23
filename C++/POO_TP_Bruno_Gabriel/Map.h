#ifndef MAP_H
#define MAP_H

#include "headers.h"
#include "Harbor.h"

class Map
{
    static vector<string> g_Map;
    vector<vector<int>> pos_fish;
    static vector<Harbor> ports;
    
public:
    Map();
    Map(string filename);
    Map(const Map& orig) = delete;
    Map& operator=(const Map &orig);
    
    void CreateHarborVector();
    
    void chooseMainHarbor(Player &player);
    string getHarborCoord(char id) const;
    vector<string> getMap() const;
};

#endif