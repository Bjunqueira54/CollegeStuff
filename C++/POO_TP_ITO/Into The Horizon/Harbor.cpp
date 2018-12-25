#include "Harbor.h"

/*Harbor::Harbor() {}

Harbor::Harbor(const Harbor& orig) {}*/

Harbor::Harbor(int xx, int yy): x(xx), y(yy) {}

const string Harbor::getCoord() const
{
    ostringstream os;
    
    os << x << " " << y;
    
    return os.str();
}

Harbor::~Harbor() {}