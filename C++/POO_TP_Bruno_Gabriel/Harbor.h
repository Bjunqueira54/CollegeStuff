#ifndef HARBOR_H
#define HARBOR_H

#include "headers.h"

class Harbor
{
    const int y, x;
    char id;
    bool PFriend;
    
public:
    Harbor(int yy, int xx, char a);
    
    string getCoord() const;
    bool isFriend() const;
    ~Harbor();
};

#endif