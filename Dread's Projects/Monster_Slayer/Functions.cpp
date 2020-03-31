#include "Functions.h"

void PrintMenu()
{
    cout << "1 - Attack" << endl;
    cout << "2 - Block" << endl;
    cout << "3 - Heal" << endl;
    cout << "4 - Give Up" << endl;
}

void Attack(Player* player, Monster* monster)
{
    int playerDmg = getRandom(15, 40);
    int monsterDmg = getRandom(25, 35);
    
    cout << player->getName() << " deals " << playerDmg << " damage to the monster" << endl;
    cout << "The monster deals " << monsterDmg << " damage to " << player->getName() << endl;
    
    monster->takeDamage(playerDmg);
    player->takeDamage(monsterDmg);
    
    getchar();
}

void Block(Player* player, Monster* monster)
{
    
}

void Heal(Player* player, Monster* monster)
{
    
}

void GiveUp(Player* player)
{
    
}

int getRandom(int min, int max)
{
    mt19937 rand(time(0));
    uniform_int_distribution<int> rng(min, max);
    
    return rng(rand);
}