#ifndef PLAYER_H
#define PLAYER_H

#include "libs.h"
#include "Navio.h"

using namespace std;

class Player
{
    const string name;
    int money;
    int nMain; //Nº de portos principais
    
    vector <Navio> fleet; //Vetor de navios que o jogador controla
    
public:
    
    Player(string a);
    
    bool purchaseShip();
    int getMoney() const;
    void setMoney();
};

#endif

