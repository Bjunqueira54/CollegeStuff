#ifndef MAP_H
#define MAP_H

#include "headers.h"
#include "Harbor.h"

class Ship;

class Map
{
    vector <string> g_map;
    vector<vector<int>> g_fish;
    vector<Harbor*> harbors;
    vector<Ship*> g_ships;
    
public:
    
    Map();
    Map(vector<string> smap);
    Map(const Map& orig);
    
    Map& operator=(const Map& orig);
    
    //Gets
    
    vector<string> getMap() const
    {return g_map;}

    vector<vector<int>> getFish() const
    {return g_fish;}
    
    vector<Ship*> getShips() const
    {return g_ships;}
    
    const bool getHarborState(int y, int x) const;
    const char getHarborId(int y, int x) const;
    
    //Sets
    
    void setHarbors();
    void setMainHarbors();
    void newShip(char t);
    bool sellShip(int id);
    
    //Move methods
    
    int move(int id, string dir);
    bool move(int id, char x);
    
    virtual ~Map();
};

#endif