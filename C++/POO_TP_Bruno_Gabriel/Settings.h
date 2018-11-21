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
    Settings(ifstream& file);
    Settings& operator=(const Settings &orig);
    
    //Returns the starting money
    int money() const;
    //Returns the pirate Spawn Chance
    int pirate() const;
    //Returns the price per Ship
    int ship() const;
    //Returns the price per crew member
    int crew() const;
    //Returns the fish sell price
    int fish() const;
    //Returns the cargo buy price
    int cargoBuyPrice() const;
    //Returns the cargo sell price
    int cargoSellPrice() const;
    //Returns the number of soldiers per harbor
    int harborCrew() const;
    //Returns the chance for an event
    int eventProb() const;
    //Returns the chance for a storm
    int stormProb() const;
    //Returns the chance for sirens
    int sirensProb() const;
    //Returns the chance for calm
    int calmProb() const;
    //Returns the chance for a riot
    int riotProb() const;
    
    ~Settings();
};

#endif /* SETTINGS_H */

