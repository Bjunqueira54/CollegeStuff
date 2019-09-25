#include "NPC.h"

NPC::NPC()
{
    HP = 250;
}

int NPC::getDmg()
{
    return (int) ((random() / RAND_MAX) * 20 + 4);
}

NPC::~NPC() {}