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
	//static Player* abandoned;
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
    
	//Returns a string with the format "Y X".
	const string getHarborCoord(int i) const { return map->getHarborCoord(i); }
	//Returns a string with the format "Y X".
	const string getOceanCoord(int i) const { return map->getOceanCoord(i); }
	//Return a string in the format of "HEIGHT WIDTH".
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
	int PlayerShipMoveTo(int id, int xx, int yy);
	int PlayerShipMoveTo(int id, char hid);
	int PlayerShipMove(int id, string dir);
	int PlayerShipStop(int id) { return player->ShipStop(id); }
	int PlayerSellShip(int id);
	int PlayerBuyCargo(int id, int cargo);
	int PlayerBuyCrew(int id, int crew);
	int PlayerBuyShip(char t);
	int PlayerSell(int id);
    
                    /////////////////////////////////////
                    ///Player Related Getter Functions///
                    /////////////////////////////////////
    
	//Returns a string with the format "Y X".
	const string getPlayerMainHarborCoord() const { return player->getMainHarborCoord(); }
	//Returns a string with the format "Y X".
	const string getPlayerShipCoord(int i) const { return player->getShipCoord(i); }
	//Returns the full information about the ship with the ID number <id>. 
	//Use this for stats printing.\n
	//Format: id typeNum Y X Crew maxCrew Water maxWater Fish Cargo maxLoad
	const string getPlayerShipInfo(int id) const { return player->getShipInfo(id); }
	const string getPlayerName() const { return player->getName(); }
	const bool getPlayerShipInHarbor(int id) const { return player->getShipInHarbor(id); }
	const int getPlayerFleetSize() const { return player->getNships(); }
	const int getPlayerShipType(int id) const { return player->getShipType(id); }
	const int getPlayerShipID(int i) const { return player->getShipID(i);}
	const int getPlayerMoney() const { return player->getMoney(); }

	virtual ~Game();
    
private:

	string getDestCoord(string curCoord, string dir);
	
	//Returns a valid coordinate string of format "Y X" to move the ship to.
	//Returns an empty string in case an error occurs.
	string nextTurnMoveShip(int i);
};

#endif