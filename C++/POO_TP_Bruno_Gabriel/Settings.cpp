#include "Settings.h"

Settings::Settings()
{
    startmoney = new int;
    pirateprob = new int;
    shipprice = new int;
    crewprice = new int;
    fishprice = new int;
    cargobuy = new int;
    cargosell = new int;
    harborcrew = new int;
    eventprob = new int;
    storm = new int;
    sirens = new int;
    calm = new int;
    riot = new int;
}

Settings::Settings(ifstream& file)
{
    file.seekg(ios::beg);
    
    string input, parse;
    istringstream is;
    
    do
    {
        getline(file, input);
    }
    while(input != "");
    
    while(!file.eof())
    {
        getline(file, input);
        is.str(input);
        
        is >> parse;
        
        if(parse == "money")
        {
            int money;
            is >> money;
            if(money == 0)
                startmoney = new int(1000);
            else
                startmoney = new int(money);
        }
        else if(parse == "pirateprob")
        {
            int pp;
            is >> pp;
            if(pp == 0)
                pirateprob = new int(20);
            else
                pirateprob = new int(pp);
        }
        else if(parse == "shipprice")
        {
            int sp;
            is >> sp;
            if(sp == 0)
                shipprice = new int(100);
            else
                shipprice = new int(sp);
        }
        else if(parse == "crewprice")
        {
            int cp;
            is >> cp;
            if(cp == 0)
                crewprice = new int(1);
            else
                crewprice = new int(cp);
        }
        else if(parse == "fishprice")
        {
            int fp;
            is >> fp;
            if(fp == 0)
                fishprice = new int(1);
            else
                fishprice = new int(fp);
        }
        else if(parse == "cargobuy")
        {
            int cp;
            is >> cp;
            if(cp == 0)
                cargobuy = new int(2);
            else
                cargobuy = new int(cp);
        }
        else if(parse == "cargosell")
        {
            int cp;
            is >> cp;
            if(cp == 0)
                cargosell = new int(3);
            else
                cargosell = new int(cp);
        }
        else if(parse == "harborcrew")
        {
            int hc;
            is >> hc;
            if(hc == 0)
                harborcrew = new int(100);
            else
                harborcrew = new int(hc);
        }
        else if(parse == "eventprob")
        {
            int ep;
            is >> ep;
            if(ep == 0)
                eventprob = new int(30);
            else
                eventprob = new int(ep);
        }
        else if(parse == "stormprob")
        {
            int sp;
            is >> sp;
            if(sp == 0)
                storm = new int(30);
            else
                storm = new int(sp);
        }
        else if(parse == "sirenprob")
        {
            int sp;
            is >> sp;
            if(sp == 0)
                sirens = new int(30);
            else
                sirens = new int(sp);
        }
        else if(parse == "calmprob")
        {
            int cp;
            is >> cp;
            if(cp == 0)
                calm = new int(20);
            else
                calm = new int(cp);
        }
        else if(parse == "riotprob")
        {
            int rp;
            is >> rp;
            if(rp == 0)
                riot = new int(20);
            else
                riot = new int(rp);
        }
    }
}

Settings& Settings::operator =(const Settings& orig)
{
    if(this == &orig)
        return *this;
    
    delete startmoney;
    startmoney = new int(orig.money());
    delete pirateprob;
    pirateprob = new int(orig.pirate());
    delete shipprice;
    shipprice = new int(orig.ship());
    delete crewprice;
    crewprice = new int(orig.crew());
    delete fishprice;
    fishprice = new int(orig.fish());
    delete cargobuy;
    cargobuy = new int(orig.cargoBuyPrice());
    delete cargosell;
    cargosell = new int(orig.cargoSellPrice());
    delete harborcrew;
    harborcrew = new int(orig.harborCrew());
    delete eventprob;
    eventprob = new int(orig.eventProb());
    delete storm;
    storm = new int(orig.stormProb());
    delete sirens;
    sirens = new int(orig.sirensProb());
    delete calm;
    calm = new int(orig.calmProb());
    delete riot;
    riot = new int(orig.riotProb());
}

int Settings::money() const
{
    return *startmoney;
}

int Settings::pirate() const
{
    return *pirateprob;
}

int Settings::ship() const
{
    return *shipprice;
}

int Settings::crew() const
{
    return *crewprice;
}

int Settings::fish() const
{
    return *fishprice;
}

int Settings::cargoBuyPrice() const
{
    return *cargobuy;
}

int Settings::cargoSellPrice() const
{
    return *cargosell;
}

int Settings::harborCrew() const
{
    return *harborcrew;
}

int Settings::eventProb() const
{
    return *eventprob;
}

int Settings::stormProb() const
{
    return *storm;
}

int Settings::sirensProb() const
{
    return *sirens;
}

int Settings::calmProb() const
{
    return *calm;
}

int Settings::riotProb() const
{
    return *riot;
}

Settings::~Settings()
{
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