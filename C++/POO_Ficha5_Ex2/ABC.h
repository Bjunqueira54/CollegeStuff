#ifndef ABC_H
#define ABC_H

#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

class ABC
{
    char *p;
    
public:
    
    ABC(const char *p);
    ABC(const ABC &orig);
    
    const char* getTxt() const;
    
    ~ABC();
    
    ABC& operator=(const ABC &orig);
};

#endif /* ABC_H */

