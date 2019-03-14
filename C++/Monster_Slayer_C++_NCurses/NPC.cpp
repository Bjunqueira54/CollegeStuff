#include "NPC.h"

NPC::NPC()
{
    hp = 500;
    damage = 0;
    
    isStunned = false;
    
    StunRound = 0;
}

NPC::~NPC() {}