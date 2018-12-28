#include "Tile.h"

/*Tile::Tile() {}

Tile::Tile(const Tile& orig) {}*/

Tile::Tile(int yy, int xx): y(yy), x(xx) {
}

const string Tile::getCoord() const
{
    ostringstream os;
    
    os << y << " " << x;

    return os.str();
}

Tile::~Tile() {}