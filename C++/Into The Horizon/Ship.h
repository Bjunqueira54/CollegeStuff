#ifndef SHIP_H
#define SHIP_H

#include "headers.h"

class Player;

class Ship
{
	int x, y, id;
	int destx, desty;
	const int moves, maxcrew, maxwater, maxload;
	int crew, water, cargo, fish;
	bool inHarbor = true;
	bool Auto = false;
	bool Stopped = true;
	bool DestHarbor = false;
	bool specMoving = false;

	Player* owner;
    
public:
    
	//No objects of ship please :)
	Ship() = delete;

	//Derivative Constructor
	Ship(Player* o, int id, int x, int y, int mm, int mc, int mw, int ml);

	const Player& getOwner() { return *owner; }
	void toggleSpecMoving() { specMoving = !specMoving; }
	void toggleInHarbor() { inHarbor = !inHarbor; }
	void move(int newy, int newx);
	int setDestination(int dy, int dx, bool idh);

				//////////////////////
				///Getter Functions///
				//////////////////////
	
	//Returns a string with the format "Y X".
	const string getDestCoord() const;
	//Returns a string with the format "Y X".
	const string getCoord() const;
	const bool isSpecMoving() const { return specMoving; }
	const bool isDestHarbor() const { return DestHarbor; }
	const bool isInHarbor() const { return inHarbor; }
	const bool isStopped() const { return Stopped; }
	const bool isAuto() const { return Auto; }
	const int getMoves() const { return moves; }
	const int getCargo() const { return cargo; }
	const int getWater() const { return water; }
	const int getCrew() const { return crew; }
	const int getFish() const { return fish; }
	const int getID() const { return id; }

	////////////////////////////
	///Pure Virtual Functions///
	////////////////////////////
	
	//Returns the full information about the ship. Use this for stats printing.
	//Format: id typeNum Y X Crew maxCrew Water maxWater Fish Cargo maxLoad
	virtual const string getShipInfo() const = 0;
	virtual const int getType() const = 0;

	virtual ~Ship();
    
private:
    
	void whatdir();
	
protected:
	
	const int getMaxcrew() const { return maxcrew; }
	const int getMaxload() const { return maxload; }
	const int getMaxwater() const { return maxwater; }

};

#endif