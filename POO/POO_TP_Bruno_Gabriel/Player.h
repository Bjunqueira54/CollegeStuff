#ifndef PLAYER_H
#define PLAYER_H

#include "headers.h"

using namespace std;

class Player
{
    const string name;
    int money;  //Dinheiro do jogador
    int fPorts; //Portos amigos
    int nShips; //Nº de navios
    /*vector <Ship> fleet*/ //Vetor da frota
    
public:
    
    Player(string n);

};

#endif /* PLAYER_H */

