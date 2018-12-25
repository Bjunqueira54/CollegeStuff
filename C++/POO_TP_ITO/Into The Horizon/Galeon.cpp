#include "Galeon.h"

Galeon::Galeon() {}

Galeon::Galeon(const Galeon& orig) {
}

Galeon::Galeon(Player &o, int x, int y): Ship(o, x, y, 1, 40, 400, 70) {}

Galeon::~Galeon() {}