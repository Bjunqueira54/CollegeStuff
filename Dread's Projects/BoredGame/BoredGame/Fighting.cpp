#include "Entity.h"

namespace Fighting
{
	void heal(Entity* ent, int amount) {
		ent->heal(amount);
	}
}