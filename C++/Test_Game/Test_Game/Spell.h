#ifndef SPELL_H
#define SPELL_H

#include "includes.h"

class Spell
{
	const string name;

	const int damage;
	const int heal;
	const int dot;

	const bool isDamaging;
	const bool isHealing;

	const bool isArcane;
	const bool isThunder;
	const bool isFire;
	const bool isIce;
	const bool isPoison;

	const bool hasHealOverTime;

public:

	Spell() = delete;

	Spell(string n, int dmg, int hv, int d,
		bool id, bool ih,
		bool at, bool tt, bool ft, bool it, bool pt,
		bool hh);

	inline int getDamage() const { return this->damage; }
	inline int getHeal() const { return this->heal; }
	inline int getDoT() { return this->dot; }

	inline bool isDamaging() const { return this->isDamaging; }
	inline bool isHealing() const { return this->isHealing; }

	inline bool isArcane() const { return this->isArcane; }
	inline bool isThunder() const { return this->isThunder; }
	inline bool isFire() const { return this->isFire; }
	inline bool isIce() const { return this->isIce; }
	inline bool isPoison() const { return this->isPoison; }

	virtual ~Spell();

};

#endif