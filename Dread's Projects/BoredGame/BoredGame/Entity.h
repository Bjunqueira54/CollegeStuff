#pragma once

class Entity
{
	int hp;
	int damage;

public:

	Entity() = delete;	//cannot call this class
	int getHP() { return this->hp; }
	void heal(int amount) { hp += amount; }
	int getDamage() { return damage; }

protected:

	Entity(int hp, int damage)
	{
		this->hp = hp;
		this->damage = damage;
	}
};