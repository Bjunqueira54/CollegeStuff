#ifndef MAP_H
#define MAP_H

#include "headers.h"
#include "Harbor.h"

class Ship;

class Map
{
    vector<string> g_Map;    //This serves as aid for drawMap()
    vector<vector<int>> pos_fish;   //This serves to store the fish amount in each position.
    static vector<Harbor> ports;    //This only serves as a information holder.
    vector<Ship> ships;            //This will hold information about every ship currently in the game.
    
public:
    Map();
    Map(string filename);
    Map(const Map& orig) = delete;
    Map& operator=(const Map &orig);
    
    void CreateHarborVector();
    void chooseMainHarbor(Player *player);
    
    const string getHarborCoord(char id) const;
    const Harbor* getHarborByCoord(int y, int x) const;
    vector<string> getMap() const;
    const vector<Ship> getShips() const;
};

#endif