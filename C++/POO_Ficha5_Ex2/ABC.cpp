#include "ABC.h"

ABC::ABC(const char *s)
{
    p = new char[strlen(s) + 1];
    strcpy(p, s);
}

ABC::ABC(const ABC& orig)
{
    p = new char[strlen(orig.p) +1];
    strcpy(p, orig.p);
}

const char* ABC::getTxt() const
{
    return p;
}

ABC& ABC::operator=(const ABC& orig)
{
    if(this == &orig)
        return *this;
    
    delete[] p;
    
    p=new char[strlen(orig.p) + 1];
    
    strcpy(p, orig.p);
    
    return *this;
}

ABC::~ABC()
{
    delete[] p;
}