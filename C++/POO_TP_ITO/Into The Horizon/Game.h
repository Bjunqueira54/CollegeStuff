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
    
	const int getPhase() const { return phase; }
    const int getTurn() const { return turn; }
    void configPhase(ifstream& file);
    void startGame();
    void nextTurn();
	
                    //////////////////////////////////
                    ///Map Related Getter Fucntions///
                    //////////////////////////////////
    
	const string getHarborCoord(int i) const { return map->getHarborCoord(i); }
	const string getOceanCoord(int i) const { return map->getOceanCoord(i); }
	const string getMapDim() const { return map->getDim(); }
	const bool harborIsFriendly(int i) const { return map->harborIsFriendly(i); }
    const char getHarborID(int i) const { return map->getHarborID(i); }
    const int getTotalHarborTiles() const { return map->getTotalHarborTiles(); }
    const int getTotalOceanTiles() const { return map->getTotalOceanTiles(); }

                    ////////////////////////////////
                    ///Settings Related Functions///
                    ////////////////////////////////
    
	const int getCargoSellPrice() const { return settings->GetCargosell(); }
	const int getCargoBuyPrice() const { return settings->GetCargobuy(); }
    const int getShipPrice() const { return settings->GetShipprice(); }
    const int getCrewPrice() const { return settings->GetCrewprice(); }
    const int getFishPrice() const { return settings->GetFishprice(); }

                    //////////////////////////////
                    ///Player Related functions///
                    //////////////////////////////
    
    void PlayerAddMoney(int m) { player->setMoney(m); }
    int PlayerShipMove(int id, string dir);
	int PlayerSellShip(int id);
    int PlayerBuyShip(char t);
    
                    /////////////////////////////////////
                    ///Player Related Getter Functions///
                    /////////////////////////////////////
    
	const Harbor* getPlayerMainHarbor() const { return player->getMainHarbor(); }
	const string getPlayerShipCoord(int i) const { return player->getShipCoord(i); }
	const string getPlayerName() const { return player->getName(); }
	const bool getPlayerShipInHarbor(int i) const { return player->getShipInHarbor(i); }
	const int getPlayerFleetSize() const { return player->getNships(); }
	const int getPlayerShipType(int i) const { return player->getShipType(i); }
	const int getPlayerShipID(int i) const { return player->getShipID(i);}
    const int getPlayerMoney() const { return player->getMoney(); }

    virtual ~Game();
    
private:
    
    string getDestCoord(string curCoord, string dir);
};

#endif