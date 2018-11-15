#include "Settings.h"

Settings::Settings(ifstream &file)
{
    file.seekg(ios::beg);
}

vector <string> Settings::getMap() const
{
    return Map;
}

int Settings::money() const
{
    return startmoney;
}

int Settings::pirate() const
{
    return pirateprob;
}

int Settings::ship() const
{
    return shipprice;
}

int Settings::crew() const
{
    return crewprice;
}

int Settings::fish() const
{
    return fishprice;
}

int Settings::cargoBuyPrice() const
{
    return cargobuy;
}

int Settings::cargoSellPrice() const
{
    return cargosell;
}

int Settings::harborCrew() const
{
    return harborcrew;
}

int Settings::eventProb() const
{
    return eventprob;
}

int Settings::stormProb() const
{
    return storm;
}

int Settings::sirensProb() const
{
    return sirens;
}

int Settings::calmProb() const
{
    return calm;
}

int Settings::riotProb() const
{
    return riot;
}

Settings::~Settings()
{
    delete Map;
    delete startmoney;
    delete pirateprob;
    delete shipprice;
    delete crewprice;
    delete fishprice;
    delete cargobuy;
    delete cargosell;
    delete harborcrew;
    delete eventprob;
    delete storm;
    delete sirens;
    delete calm;
    delete riot;
}