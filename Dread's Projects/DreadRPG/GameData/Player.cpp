#include "Player.h"

Player::Player(string name): pName(name)
{
    HP = 100;
    
    STR = DEX = INT = MP = 0;
    
    isBlocking = isHealing = false;
}

int Player::getDamage()
{
    return (int) ((random() / RAND_MAX) * 10 + 25);
}

Player::~Player() {}