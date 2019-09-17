#pragma once
#include "../Spell.h"
class DamageSpell: virtual public Spell
{
	const int damage;

public:
	DamageSpell();
	virtual ~DamageSpell();
};

