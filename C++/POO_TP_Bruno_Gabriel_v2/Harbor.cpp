#include "Harbor.h"

Harbor::Harbor(int yy, int xx, char i):y(yy), x(xx), id(i)
{
    if(id>='A' && id <='Z')
        friendly = true;
    else
        friendly = false;
}

const string Harbor::getCoord() const
{
    ostringstream os;
    
    os << y << " " << x;
    
    return os.str();
}

void Harbor::toggleState()
{
    friendly = !friendly;
}