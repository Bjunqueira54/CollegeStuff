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
    Settings(vector<string> values);
    Settings(const Settings& orig);
    
    Settings& operator=(const Settings& orig);
    
    const int GetCalm() const
    {return *calm;}

    const int GetCargobuy() const
    {return *cargobuy;}

    const int GetCargosell() const
    {return *cargosell;}

    const int GetCrewprice() const
    {return *crewprice;}

    const int GetEventprob() const
    {return *eventprob;}

    const int GetFishprice() const
    {return *fishprice;}

    const int GetHarborcrew() const
    {return *harborcrew;}

    const int GetPirateprob() const
    {return *pirateprob;}

    const int GetRiot() const
    {return *riot;}

    const int GetShipprice() const
    {return *shipprice;}

    const int GetSirens() const
    {return *sirens;}

    const int GetStartmoney() const
    {return *startmoney;}

    const int GetStorm() const
    {return *storm;}

    virtual ~Settings();
};

#endif