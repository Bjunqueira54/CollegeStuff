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
    
    bool NewShip(char t);

};

#endif /* PLAYER_H */

