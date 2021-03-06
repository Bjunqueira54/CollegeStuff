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
    void setMoney(int n);
    
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
	//Returns if ship is full or not.
	//Returns false even if ship doesn't exist.
	const bool getShipIsFull(int id) const;
	//Returns if a ship is currently in auto mode.
	//In case <id> does not exist, returns true.
	//Note: Check if all other booleans are also true. If they are,
	//then something went wrong.
	const bool getShipAuto(int id) const;
	//Returns the total cargo currently in ship <id>
	//Returns -1 if an error occurred.
	const int getShipCargo(int id) const;
	//Returns the amount of moves available for the ship with <id>.
	//Returns -1 if an error occurred.
	const int getShipMoves(int id) const;
	//Returns the amount of water currently in ship <id>
	//Returns -1 if the ship doesn't exist;
	const int getShipWater(int id) const;
	//Returns the total amount of fish currently in ship <id>.
	//Retuns -1 if an error occurred.
	const int getShipFish(int id) const;
	//Returns the (int) value of a ship as commented at the top of this header file.
	//Returns -1 if an error occurred.
	const int getShipType(int id) const;
	const int getShipID(int i) const;
	const int getCargo(int id) const;
    const int getCrew(int id) const;
    const int getFish(int id) const;
	
	const int getShipmaxCrew(int id) const;
	const int ShipFish(int id) const;
	const bool CoordExists(string coord) const;
	
                ////////////////////
                ///Ship Functions///
                ////////////////////

	//Sets the boolean variable "SpecMoving" to it's inverted state.
	//Check it's state before using this function to be sure you're
	//getting what you desire.
	void toggleShipSpecMoving(int id);
	
	//Sets the boolean variable "InHarbor" to it's inverted state.
	//Check it's state before using this function to be sure you're
	//getting what you desire.
	void toggleShipInHarbor(int id);
	
	void toggleShipAuto(int id);
	
	//Use this to capture a ship with no crew floating in the ocean.
    //NOTE: Pirates need to check if the ship is a sailboat or a frigate.
    void captureShip();
	
	//For the pirates: spawns a ship of type <type> to the coordinates
    //x and y. Use <sih> to control if the ship is spawning in a harbor
	//tile of not.
    int spawnship(int type, int x, int y, bool sih);
	
	//Sets the destination coordinatinates for ship <id>
	//Returns -1 if <id> does not exist.
    int ShipSetDestination(int id, string destCoord, bool isDestHarbor);
	
	//Turns on "Auto" mode for the ship with <id>
	//Returns -1 if ship was not found.
	int ShipSetAuto(int id);
	
	//Updates the (<yy>,<xx>) coordinates of the ship with ID number <id>.
	//Return values: 0 on success, -1 if an error occurred.
	int ShipMove(int id, int yy, int xx);
	
	//Completelly destroys a ship for Player::fleet vector by calling delete
    //on it's memory pointer and then erasing it from the vector.
    //Note: Do NOT use this to remove ships from Player's ownership, use
    //the abandonShip(int i) function.
    int sellShip(int id);
	
	int ShipSetCargo(int id, int cargo);
	
	int ShipSetCrew(int id, int crew);
	int ShipSetFish(int id, int fish);
    
    //For the player: buys a ship of type <type> and spawns it in the
    //player's main harbor.
    int buyShip(int type);
	
	int ShipStop(int id);
	
    virtual ~Player();
};

#endif