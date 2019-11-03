#include "Player.h"

Player::Player(string n, int h): name(n), HP(h) {
}

void Player::takeDamage(int damage)
{
    HP -= damage;
}


Player::~Player() {}