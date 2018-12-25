#ifndef PLAYER_H
#define PLAYER_H

#include "headers.h"
#include "Ship.h"
#include "Harbor.h"

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
    Player(string n, int m);
    
    //For the player: buys a ship of type <type> and spawns it in the
    //player's main harbor.
    void buyShip(char type);
    
    //For the pirates: spawns a ship of type <type> to the coordinates
    //x and y (make sure it's not on a land/harbor tile.
    int spawnship(char type, int x, int y);
    
    //Use this to capture a ship with no crew floating in the ocean.
    //NOTE: Pirates need to check if the ship is a sailboat or a frigate.
    void captureShip();
    
    //Moves ship <id> in the direction of <dir>.
    void move(int id, string dir);
    
    //Moves ship <id> to the coordinates indicated by <x> and <y>.
    void moveto(int id, int x, int y);
    
    //Moves ship <id> to the harbor with the ID <hid>.
    void moveto(int id, char hid);
    
    /*Self-Explanatory 'getter' functions*/
    
    const int getMoney() const { return money; }
    const string getName() const { return name; }
    const int getNships() const { return fleet.size(); }
    
    virtual ~Player();
};

#endif