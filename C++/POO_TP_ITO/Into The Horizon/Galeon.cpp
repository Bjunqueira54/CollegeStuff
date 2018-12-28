#include "Galeon.h"

/*Galeon::Galeon() {}

Galeon::Galeon(const Galeon& orig) {}*/

Galeon::Galeon(Player* o, int id, int x, int y): Ship(o, id, x, y, 1, 40, 400, 70) {}

Galeon::~Galeon() {}