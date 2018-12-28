#ifndef GAME_H
#define GAME_H

#include "headers.h"
#include "Player.h"
#include "Settings.h"
#include "Map.h"

class Game
{
    const string playername;
    static Player* player;
    static Player* pirate;
    static Settings* settings;
    static Map* map;
    static int turn;
    int phase = 0;
    
public:
    
    Game();
    Game(const Game& orig);
    Game(string n);
    
    void configPhase(ifstream& file);
    void startGame();
    
    const int getPhase() const { return phase; }
    const string getMapDim() const { return map->getDim(); }
    const string getTileCoord() const { return map->getTileCoord(); }
    const int getTotalOceanTiles() const { return map->getTotalOceanTiles(); }
    const int getTotalHarborTiles() const { return map->getTotalHarborTiles(); }
    const bool harborIsFriendly(int yy, int xx) const { return map->harborIsFriendly(yy, xx); }
    
    virtual ~Game();
};

#endif