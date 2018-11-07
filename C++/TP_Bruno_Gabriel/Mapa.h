#ifndef MAPA_H
#define MAPA_H

#include "libs.h"
#include "Oceano.h"
#include "Terra.h"

using namespace std;

class Mapa
{
    vector <Oceano> ocean;
    vector <Terra> land;
    
public:
    
    Mapa();
};

#endif /* MAPA_H */

