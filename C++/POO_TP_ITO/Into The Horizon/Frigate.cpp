#include "Frigate.h"

/*Frigate::Frigate() {}

Frigate::Frigate(const Frigate& orig) {}*/

Frigate::Frigate(Player* o, int id, int x, int y): Ship(o, id, x, y, 2, 50, 500, 0) {}

Frigate::~Frigate() {}