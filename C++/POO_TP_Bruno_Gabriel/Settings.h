#ifndef SETTINGS_H
#define SETTINGS_H

#include "headers.h"
#include "Language.h"

class Settings
{
    const vector <string> Map;
    const int startmoney;
    const int pirateprob;
    const int shipprice;
    const int crewprice;
    const int fishprice;
    const int cargobuy;
    const int cargosell;
    const int harborcrew;
    const int eventprob;
    const int storm;
    const int sirens;
    const int calm;
    const int riot;
    
public:
    
    Settings(ifstream &file);
    
    vector<string> getMap() const;
    int money() const;
    int pirate() const;
    int ship() const;
    int crew() const;
    int fish() const;
    int cargoBuyPrice() const;
    int cargoSellPrice() const;
    int harborCrew() const;
    int eventProb() const;
    int stormProb() const;
    int sirensProb() const;
    int calmProb() const;
    int riotProb() const;
    
    ~Settings();
};

#endif /* SETTINGS_H */

