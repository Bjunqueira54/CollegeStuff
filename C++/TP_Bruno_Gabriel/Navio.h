#ifndef NAVIO_H
#define NAVIO_H

#include "libs.h"

using namespace std;

class Navio
{
    const int id; //Number ID
    const int type, price, moves;
    const int maxload;
    int load, fish;
    const int maxwater;
    int water;
    const int maxcrew;
    int crew;
    
public:
    
    Navio(int i, int t, int p, int m, int l, int w, int c);
    
};

#endif /* NAVIO_H */

