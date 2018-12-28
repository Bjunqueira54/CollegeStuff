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
    void nextTurn();
    
    const int getPhase() const { return phase; }
    const int getTurn() const { return turn; }
    const string getMapDim() const { return map->getDim(); }
    const int getTotalOceanTiles() const { return map->getTotalOceanTiles(); }
    const string getOceanCoord(int i) const { return map->getOceanCoord(i); }
    const int getTotalHarborTiles() const { return map->getTotalHarborTiles(); }
    const string getHarborCoord(int i) const { return map->getHarborCoord(i); }
    const bool harborIsFriendly(int i) const { return map->harborIsFriendly(i); }
    const char getHarborID(int i) const { return map->getHarborID(i); }
    
    const int getPlayerMoney() const { return player->getMoney(); }
    const string getPlayerName() const { return player->getName(); }
    const int getPlayerFleetSize() const { return player->getNships(); }
    const int getShipPrice(char t) const { return settings->GetShipprice(); }
    const string getPlayerShipCoord(int i) const { return player->getShipCoord(i); }
    const bool getPlayerShipInHarbor(int i) const { return player->getShipInHarbor(i); }
    const int getPlayerShipType(int i) const { return player->getShipType(i); }
    const string getPlayerShipID(int i) const { return player->getShipID(i);}
    const Harbor* getPlayerMainHarbor() const { return player->getMainHarbor(); }
    
    int PlayerBuyShip(char t);
    int PlayerSellShip(int id);
    
    virtual ~Game();
};

#endif