#include "Ship.h"

using namespace std;

Ship::Ship(int i, int t): id(i), type(t)
{
    if(t==0)
        price = PRICE_GALEON;
}
