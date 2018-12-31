#include "Ocean.h"

/*Ocean::Ocean() {}

Ocean::Ocean(const Ocean& orig) {}*/

Ocean::Ocean(int yy, int xx): Tile(yy, xx), tleft(0), fish(1) {}

Ocean::~Ocean() {}