#ifndef HARBOR_H
#define HARBOR_H

#include "headers.h"

class Player;

class Harbor
{
    const int y, x;
    const char id;
    int soldiers;
    bool PFriend;
    
public:
    Harbor(int yy, int xx, char a);
    Harbor(const Harbor& other) :
    y(other.y), x(other.x), id(other.id), soldiers(other.soldiers), PFriend(other.PFriend) {}

    const char getId() const
    {return id;}

    string getCoord() const;
    bool isFriend() const;
    void becomeMain(Player *player);
    
    ~Harbor();
};

#endif