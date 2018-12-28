#include "Sailboat.h"

/*Sailboat::Sailboat() {}

Sailboat::Sailboat(const Sailboat& orig) {}*/

Sailboat::Sailboat(Player* o, int id, int x, int y): Ship(o, id, x, y, 2, 20, 200, 40) {}

Sailboat::~Sailboat() {}