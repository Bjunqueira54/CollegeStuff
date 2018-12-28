#include "Schooner.h"

/*Schooner::Schooner() {}

Schooner::Schooner(const Schooner& orig) {}*/

Schooner::Schooner(Player* o, int id, int x, int y): Ship(o, id, x, y, 1, 10, 100, 20) {}

Schooner::~Schooner() {}