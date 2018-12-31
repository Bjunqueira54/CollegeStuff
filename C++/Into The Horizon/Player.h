#ifndef PLAYER_H
#define PLAYER_H

#include "headers.h"
#include "Harbor.h"
#include "Sailboat.h"
#include "Galeon.h"
#include "Schooner.h"
#include "Frigate.h"
#include "Special.h"

/* Ship Types(ENG/PT):
 1 - Sailboat/Veleiro
 2 - Galeon/Galeao
 3 - Schooner/Escuna
 4 - Frigate/Fragata
 5 - Special/Especial
 */

class Player
{
    const string name;
    int money;
    vector <Ship*> fleet;
    Harbor* mainharbor;
    
public:
    
    Player();
    Player(const Player& orig);
    Player(string n, int m, Harbor* h);
    
                //////////////////////
                ///Player Functions///
                //////////////////////
    
    //Adds (or subtracts) <n> to (or from) the player's total balance.
    void setMoney(int n) { money += n; }
    
                //////////////////////
                ///Getter Functions///
                //////////////////////
	
    const string getMainHarborCoord() const { return mainharbor->getCoord(); }
	const string getName() const { return name; }
	const int getNships() const { return fleet.size(); }
    const int getMoney() const { return money; }
    
                //////////////////////////
                //Ship Getter Functions///
                //////////////////////////
    
	const string getShipDestCoord(int id) const;
    const string getShipCoord(int id) const;
	//Returns the full information about the ship with the ID number <id>. 
	//Use this for stats printing.
	//Format: id typeNum Y X Crew maxCrew Water maxWater Fish Cargo maxLoad
	const string getShipInfo(int id) const;
	//Returns if the ship is moving to a specific location (eg.: a harbor).
	//In case <id> does not exist, returns true.
	//Note: Check if all other booleans are also true. If they are,
	//then something went wrong.
	const bool getShipSpecMoving(int id) const;
	//Returns if the ship is currently in a harbor.
	//In case <id> does not exist, returns true.
	//Note: Check if all other booleans are also true. If they are,
	//then something went wrong.
	const bool getShipInHarbor(int id) const;
	//Returns if a ship is currently stopped.
	//In case <id> does not exist, returns true.
	//Note: Check if all other booleans are also true. If they are,
	//then something went wrong.
	const bool getShipStopped(int id) const;
	//Returns if a ship is currently in auto mode.
	//In case <id> does not exist, returns true.
	//Note: Check if all other booleans are also true. If they are,
	//then something went wrong.
	const bool getShipAuto(int id) const;
	//Returns the amount of moves available for the ship with <id>.
	//Returns -1 if an error occurred.
	const int getShipMoves(int id) const;
	//Returns the (int) value of a ship as commented at the top of this header file.
	//Returns -1 if an error occurred.
	const int getShipType(int id) const;
	const int getShipID(int i) const;
	const int getCargo(int id) const;
    const int getCrew(int id) const;
    const int getFish(int id) const;
	
                ////////////////////
                ///Ship Functions///
                ////////////////////

    //Use this to capture a ship with no crew floating in the ocean.
    //NOTE: Pirates need to check if the ship is a sailboat or a frigate.
    void captureShip();
	
	//Sets the boolean variable "SpecMoving" to it's inverted state.
	//Check it's state before using this function to be sure you're
	//getting what you desire.
	void toggleShipSpecMoving(int id);
	
	//Sets the boolean variable "InHarbor" to it's inverted state.
	//Check it's state before using this function to be sure you're
	//getting what you desire.
	void toggleShipInHarbor(int id);
	
	//For the pirates: spawns a ship of type <type> to the coordinates
    //x and y (make sure it's not on a land/harbor tile.
    int spawnship(int type, int x, int y);
	
	//Moves ship <id> in the direction of <dir>. Uses 1 move.
    int ShipSetDestination(int id, string destCoord, bool isDestHarbor);
	
	//Updates the (<yy>,<xx>) coordinates of the ship with ID number <id>.
	//Return values: 0 on success, -1 if an error occurred.
	int ShipMove(int id, int yy, int xx);
	
	//Completelly destroys a ship for Player::fleet vector by calling delete
    //on it's memory pointer and then erasing it from the vector.
    //Note: Do NOT use this to remove ships from Player's ownership, use
    //the abandonShip(int i) function.
    int sellShip(int id);
    
    //For the player: buys a ship of type <type> and spawns it in the
    //player's main harbor.
    int buyShip(int type);
	
    virtual ~Player();
};

#endif