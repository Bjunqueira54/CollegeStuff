#ifndef PLAYER_H
#define PLAYER_H

#include "includes.h"

class Player
{
#define MAX_HP 100
#define MIN_HP 0
    
    const string name;
    
    int hp;
    int damage;
    int heal;
    int block;
    
    bool isBlocking;
    bool isFirstRound;
    bool isHealing;
    
public:
    
    Player() = delete;
    Player(const Player& orig) = delete;
    Player(const string PlayerName);
    
    string getPlayerName() { return name; }
    int getHP() { return hp; }
    
    int getDamage() { return DamageRoll(); }
    int SpecialAttackDamage() { return SpecialDamage(); }
    
    bool getBlockState() { return isBlocking; }
    bool getHealState() { return isHealing; }
    
    //Input the monster's attack damage to subtract to the player's HP.
    //If the player was blocking, use BlockDamage() instead.
    void TakeDamage(int MonsterDamage);
    
    //Rolls a random value and adds it to the player's current HP
    void HealDamage();
    
    //Input the Monster's damage to subtract from the player's HP
    //after rolling the block percentage.
    //If the player wasn't blocking, use TakeDamage() instead.
    void BlockDamage(int MonsterDamage);
    
    //Resets some variables for the next game round.
    void NextRound();
    
    virtual ~Player();
    
private:
    
    const bool CritRoll(); //done
    const int DamageRoll(); //done
    const int HealRoll();   //done
    const double BlockRoll(); //done
    const int SpecialDamage(); //done
    const bool MissRoll(); //done
};

#endif