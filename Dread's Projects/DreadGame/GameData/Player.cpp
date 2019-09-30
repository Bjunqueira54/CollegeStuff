#include "Player.h"

Player::Player(string name): pName(name)
{
    HP = 100;
    
    MP = STR = DEX = INT = 0;
}


Player::~Player() {}