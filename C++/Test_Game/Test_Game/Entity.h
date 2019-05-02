#ifndef ENTITY_H
#define ENTITY_H

#include "includes.h"
#include "spells_include.h"

class Entity
{
	int HP;
	int mana;
	int armor;
	int STR;
	int DEX;
	int INT;

	double CritChance;
	int MeleeDamage;
	int SpellDamageBonus;

	vector<Spell> spells;

public:

	Entity();

	//All the Getter Functions
	inline int getHP() { return this->HP;  }
	inline int getMana() { return this->mana;  }
	inline int getArmor() { return this->armor; }

	inline int getStr() { return this->STR; }
	inline int getDex() { return this->DEX; }
	inline int getInt() { return this->INT; }

	inline double getCritChance() { return this->CritChance; }
	inline int getMeleeDamage() { return this->MeleeDamage; }
	inline int getSpellDamageBonus() { return this->SpellDamageBonus; }

	virtual ~Entity();
};

#endif // !ENTITY_H