#ifndef PLAYER_H
#define PLAYER_H

#include "headers.h"
#include "Ship.h"
//#include "Harbor.h" //Temp.
#include "Map.h"

using namespace std;

class Player
{
    const string *name; //Player's name
    int money;  //Player's money
    int fPorts; //Number of friendly Harbors
    int nShips; //Number of currently owned ships
    vector <Ship> fleet; //Fleet's vector
    const Harbor *MainHarbor;
    
public:
    
    Player();
    Player(string n);
    Player(const Player& orig);
    
    //Returns the player's name in "string" type
    string getName() const;
    
    //Returns the player's total gold in "int" type
    int getMoney() const;
    
    //Sets the player's money to n
    void setMoney(int n);
    
    //Adds (or removes) n of the player's money
    void addMoney(int n);
    
    //Attemps to create a new Ship of type t and pushes it to
    //the back to the Ship vector.
    //Return "true" if the operator succeded, else "false" with no defined error
    bool newShip(char t);
    
    //Attemps to sell a ship by finding a matching ID in
    //the fleet vector and erasing it. Restores PRICE_ship
    //coins to the player's current balance.
    bool sellShip(int id);
    
    //Gets all the current friendly harbors from the Map class
    //and randomly picks one of them to become the main harbor
    //where newly bought ships will spawn.
    void setMainHarbor(const Harbor& main);
    
    Harbor getMainHarbor() const;

    Player& operator=(const Player &orig);
    ~Player();
};

#endif