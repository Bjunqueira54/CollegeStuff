#ifndef SETTINGS_H
#define SETTINGS_H

#include "headers.h"

class Settings
{
    const int *startmoney;
    const int *pirateprob;
    const int *shipprice;
    const int *crewprice;
    const int *fishprice;
    const int *cargobuy;
    const int *cargosell;
    const int *harborcrew;
    const int *eventprob;
    const int *storm;
    const int *sirens;
    const int *calm;
    const int *riot;
    
public:
    
    Settings();
    Settings(const Settings& orig);
    virtual ~Settings();
};

#endif