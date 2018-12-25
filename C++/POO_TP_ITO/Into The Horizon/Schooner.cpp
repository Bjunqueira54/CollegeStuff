#include "Schooner.h"

Schooner::Schooner() {}

Schooner::Schooner(const Schooner& orig) {
}

Schooner::Schooner(Player &o, int x, int y): Ship(o, x, y, 1, 10, 100, 20) {}

Schooner::~Schooner() {}