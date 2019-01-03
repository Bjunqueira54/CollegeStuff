#include "Ocean.h"

Ocean::Ocean(int yy, int xx): Tile(yy, xx), tleft(0), fish(1) {
}

void Ocean::TurnUpdate()
{
    if(tleft > 0)
        tleft--;
    
    if(tleft <= 0)
    {
        tleft = 0;
        fish = 1;
    }
}

void Ocean::Fished()
{
    fish = 0;
    tleft = 3;
}

Ocean::~Ocean() {}