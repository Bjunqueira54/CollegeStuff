#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "includes.h"

class Monster;
class Player;

void PrintMenu();
void Attack(Player*, Monster*);
void Block(Player*, Monster*);
void Heal(Player*, Monster*);
void GiveUp(Player*);

int getRandom(int, int);

void Victory();
void Defeat();

#endif