#ifndef SHIP_H
#define SHIP_H

#include "headers.h"

class Player;

class Ship
{
    const int *id;
    const char *type;
    
    const int *maxwater;
    const int *maxcrew;
    const int *maxload;
    const int *moves;
    
    Player *owner;
    
    int water;
    int crew;
    int fish;
    int cargo;
    int movesl;
    
    int y, x;
    int dy, dx;
    
    bool inHarbor;
    bool Moving;
    
public:
    
    Ship();
    Ship(int i, char t, Player &p);
    Ship(const Ship& orig);
    Ship& operator=(const Ship& orig);
    
    //GET
    
    int GetCargo() const {return cargo;}
    int GetCrew() const {return crew;}
    int GetFish() const {return fish;}
    int GetMovesl() const {return movesl;}
    const int GetId() const {return *id;}
    const int GetMaxcrew() const {return *maxcrew;}
    const int GetMaxload() const {return *maxload;}
    const int GetMaxwater() const {return *maxwater;}
    const int GetMoves() const {return *moves;}
    const char GetType() const {return *type;}
    int GetWater() const {return water;}
    bool IsInHarbor() const {return inHarbor;}
    bool IsMoving() const {return Moving;}

    Player* getOwner() const {return owner;}
    string GetCoord() const;
    string GetDest() const;
    
    //SET
    
    void toggleHarbor() {inHarbor = !inHarbor;}
    void setOwner(const Player &player);
    void setDest(int yy, int xx);
    void setMovesl(int n);
    void turnSet();

    virtual ~Ship();
};

#endif