#include "Harbor.h"

/*Harbor::Harbor() {}

Harbor::Harbor(const Harbor& orig) {}*/

Harbor::Harbor(char i, int yy, int xx): id(i), Tile(yy, xx)
{
    if(i >= 'a' && i <= 'z')
        friendly = false;
    else if(i >= 'A' && i <= 'Z')
        friendly = true;
}

Harbor::~Harbor() {}