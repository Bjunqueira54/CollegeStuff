#include "Player.h"

Player::Player(const Player& orig) {}

Player::Player(string name): pName(name)
{
    STR = 0;
    DEX = 0;
    INT = 0;
    
    HP = 100;
    MP = 0;
    
    isBlocking = false;
}

Player::~Player() {}