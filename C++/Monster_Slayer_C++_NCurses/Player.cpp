#include "Player.h"

Player::Player(const string PlayerName): name(PlayerName)
{
    hp = 100;
    damage = 0;
    heal = 0;
    block = 0;
    
    isBlocking = false;
    isFirstRound = true;
    isHealing = false;
}

int Player::DamageRoll()
{
    mt19937 rand(time(0));
    uniform_int_distribution<int> dmgRoll(25, 35);
    
    if(CritRoll())
	return (dmgRoll(rand) * 2.5);
    else
	return dmgRoll(rand);
}

int Player::SpecialDamage()
{
    mt19937 rand(time(0));
    uniform_int_distribution<int> specialRoll(30, 40);
    
    return specialRoll(rand);
}

bool Player::CritRoll()
{
    mt19937 rand(time(0));
    uniform_int_distribution<int> crit(1, 100);
    
    return (crit(rand) <= 20);
}

bool Player::MissRoll()
{
    mt19937 rand(time(0));
    uniform_int_distribution<int> miss(1, 100);
    
    return (miss(rand) <= 5);
}

void Player::TakeDamage(int MonsterDamage)
{
    if(hp - MonsterDamage < MIN_HP)
	hp = MIN_HP;
    else
	hp -= MonsterDamage;
}

void Player::HealDamage()
{
    int recovery = HealRoll();
    if((this->hp + recovery) > MAX_HP)
	this->hp = MAX_HP;
    else
	this->hp += recovery;
}

void Player::BlockDamage(int MonsterDamage)
{
    int UnblockedDamage = MonsterDamage - (MonsterDamage * BlockRoll());
    TakeDamage(UnblockedDamage);
}

const double Player::BlockRoll()
{
    mt19937 rand(time(0));
    uniform_real_distribution<double> PercentageRange(0.35, 0.50);
    
    return PercentageRange(rand);
}

const int Player::HealRoll()
{
    mt19937 rand(time(0));
    uniform_int_distribution<int> Heal(20, 30);
    
    return Heal(rand);
}

void Player::NextRound()
{
    if(isFirstRound)
	isFirstRound = false;
    
    isBlocking = isHealing = false;
}

Player::~Player()
{
    
}