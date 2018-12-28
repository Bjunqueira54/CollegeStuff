#ifndef SETTINGS_H
#define SETTINGS_H

#include "headers.h"

class Settings
{
    const int *lines;
    const int *columns;
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
    
    vector <string> map;
    
public:
    
    Settings();
    Settings(const Settings& orig);
    Settings(ifstream& file);
    
    //Getter Functions
    
    const int GetCalm() const { return *calm; }
    const int GetCargobuy() const { return *cargobuy; }
    const int GetCargosell() const { return *cargosell; }
    const int GetCrewprice() const { return *crewprice; }
    const int GetEventprob() const { return *eventprob; }
    const int GetFishprice() const { return *fishprice; }
    const int GetHarborcrew() const { return *harborcrew; }
    const int GetPirateprob() const { return *pirateprob; }
    const int GetRiot() const { return *riot; }
    const int GetShipprice() const { return *shipprice; }
    const int GetSirens() const { return *sirens; }
    const int GetStartmoney() const { return *startmoney; }
    const int GetStorm() const { return *storm; }
    const vector<string> getMap() const { return map;}
    
    virtual ~Settings();
};

#endif