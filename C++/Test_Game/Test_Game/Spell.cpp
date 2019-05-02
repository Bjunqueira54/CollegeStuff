#include "Spell.h"

Spell::Spell(string n, int dmg, int hv, int d, bool id, bool ih, bool at, bool tt, bool ft, bool it, bool pt, bool hh):
	name(n), damage(dmg), heal(hv), dot(d), isDamaging(id), isHealing(ih), isArcane(at), isThunder(tt), isFire(ft), isIce(it), isPoison(pt), hasHealOverTime(hh) {}


Spell::~Spell()
{
}