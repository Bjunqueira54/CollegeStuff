#include "Harbor.h"

/*Harbor::Harbor() {}

Harbor::Harbor(const Harbor& orig) {}*/

Harbor::Harbor(char i, int xx, int yy): id(i), y(yy), x(xx) {}

const string Harbor::getCoord() const
{
    ostringstream os;
    
    os << x << " " << y;
    
    return os.str();
}

Harbor::~Harbor() {}