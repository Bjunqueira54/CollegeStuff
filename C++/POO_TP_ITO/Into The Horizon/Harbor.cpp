#include "Harbor.h"

Harbor::Harbor() {}

Harbor::Harbor(const Harbor& orig) {
}

const string Harbor::getCoord() const
{
    ostringstream os;
    
    os << x << " " << y;
    
    return os.str();
}

Harbor::~Harbor() {}