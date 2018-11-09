#ifndef PLAYER_H
#define PLAYER_H

#include "headers.h"
#include "Ship.h"

using namespace std;

class Player
{
    const string name;
    int money;  //Dinheiro do jogador
    int fPorts; //Portos amigos
    int nShips; //Nº de navios
    vector <Ship> fleet; //Vetor da frota
    
public:
    
    Player(string n);
    
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
    bool NewShip(char t);

};

#endif /* PLAYER_H */

