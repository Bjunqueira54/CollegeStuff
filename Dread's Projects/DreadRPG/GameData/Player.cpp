#include "Player.h"

Player::Player(string name): pName(name)
{
    HP = 100;
    
    STR = DEX = INT = MP = 0;
    
    isBlocking = isHealing = false;
}

Player::~Player() {}