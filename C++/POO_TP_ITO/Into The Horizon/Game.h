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
    
                    ////////////////////////////
                    ///Game Related Functions///
                    ////////////////////////////
    
    void configPhase(ifstream& file);
    void startGame();
    void nextTurn();
    const int getPhase() const { return phase; }
    const int getTurn() const { return turn; }
    
                    //////////////////////////////////
                    ///Map Related Getter Fucntions///
                    //////////////////////////////////
    
    const int getTotalHarborTiles() const { return map->getTotalHarborTiles(); }
    const int getTotalOceanTiles() const { return map->getTotalOceanTiles(); }
    const bool harborIsFriendly(int i) const { return map->harborIsFriendly(i); }
    const char getHarborID(int i) const { return map->getHarborID(i); }
    const string getMapDim() const { return map->getDim(); }
    const string getOceanCoord(int i) const { return map->getOceanCoord(i); }
    const string getHarborCoord(int i) const { return map->getHarborCoord(i); }
    
                    ////////////////////////////////
                    ///Settings Related Functions///
                    ////////////////////////////////
    
    const int getShipPrice() const { return settings->GetShipprice(); }
    const int getCrewPrice() const { return settings->GetCrewprice(); }
    const int getFishPrice() const { return settings->GetFishprice(); }
    const int getCargoBuyPrice() const { return settings->GetCargobuy(); }
    const int getCargoSellPrice() const { return settings->GetCargosell(); }
    
                    //////////////////////////////
                    ///Player Related functions///
                    //////////////////////////////
    
    void PlayerAddMoney(int m) { player->setMoney(m); }
    int PlayerShipMove(int id, string dir) { return player->ShipMove(id, getDestCoord(player->getShipCoordByID(id), dir)); }
    int PlayerBuyShip(char t);
    int PlayerSellShip(int id);
    
                    /////////////////////////////////////
                    ///Player Related Getter Functions///
                    /////////////////////////////////////
    
    const int getPlayerMoney() const { return player->getMoney(); }
    const int getPlayerFleetSize() const { return player->getNships(); }
    const int getPlayerShipType(int i) const { return player->getShipType(i); }
    const bool getPlayerShipInHarbor(int i) const { return player->getShipInHarbor(i); }
    const string getPlayerName() const { return player->getName(); }
    const string getPlayerShipCoord(int i) const { return player->getShipCoord(i); }
    const string getPlayerShipID(int i) const { return player->getShipID(i);}
    const Harbor* getPlayerMainHarbor() const { return player->getMainHarbor(); }
    
    virtual ~Game();
    
private:
    
    string getDestCoord(string curCoord, string dir);
};

#endif