#include "Monster.h"

Monster::Monster(int h)
{
    HP = h;
}

void Monster::takeDamage(int damage)
{
    HP -= damage;
}

Monster::~Monster() {}