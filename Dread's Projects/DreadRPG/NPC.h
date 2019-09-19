#ifndef NPC_H
#define NPC_H

class NPC
{
    int HP;
public:

    NPC();
    NPC(const NPC& orig);
    
    int getDamage();

    virtual ~NPC();
};

#endif