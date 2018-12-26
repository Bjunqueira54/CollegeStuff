#include "Special.h"

/*Special::Special() {}

Special::Special(const Special& orig) {}*/

Special::Special(Player* o, int x, int y): Ship(o, x, y, 5, 500, 5000, 0) {}

Special::~Special() {}