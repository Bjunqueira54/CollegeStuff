#include "Settings.h"

Settings::Settings()
{
    startmoney = new int(0);
    pirateprob = new int(0);
    shipprice = new int(0);
    crewprice = new int(0);
    fishprice = new int(0);
    cargobuy = new int(0);
    cargosell = new int(0);
    harborcrew = new int(0);
    eventprob = new int(0);
    storm = new int(0);
    sirens = new int(0);
    calm = new int(0);
    riot = new int(0);
}

Settings::Settings(vector<string> values)
{
    for(int i=0; i<values.size(); i++)
    {
        istringstream is;
        string input;
        int val;
        is.str(values[i]);
        is >> input;
        is >> val;

        if(input == "money")
            startmoney = new int(val);
        else if(input == "pirateprob")
            pirateprob = new int(val);
        else if(input == "shipprice")
            shipprice = new int(val);
        else if(input == "crewprice")
            crewprice = new int(val);
        else if(input == "fishprice")
            fishprice = new int(val);
        else if(input == "cargobuy")
            cargobuy = new int(val);
        else if(input == "cargosell")
            cargosell = new int(val);
        else if(input == "harborcrew")
            harborcrew = new int(val);
        else if(input == "eventprob")
            eventprob = new int(val);
        else if(input == "stormprob")
            storm = new int(val);
        else if(input == "sirenprob")
            sirens = new int(val);
        else if(input == "calmprob")
            calm = new int(val);
        else if(input == "riotprob")
            riot = new int(val);
    }
}

Settings::Settings(const Settings& orig)
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
    
    startmoney = new int(orig.GetStartmoney());
    pirateprob = new int(orig.GetPirateprob());
    shipprice = new int(orig.GetShipprice());
    crewprice = new int(orig.GetCrewprice());
    fishprice = new int(orig.GetFishprice());
    cargobuy = new int(orig.GetCargobuy());
    cargosell = new int(orig.GetCargosell());
    harborcrew = new int(orig.GetHarborcrew());
    eventprob = new int(orig.GetEventprob());
    storm = new int(orig.GetStorm());
    sirens = new int(orig.GetSirens());
    calm = new int(orig.GetCalm());
    riot = new int(orig.GetRiot());
}

Settings& Settings::operator =(const Settings& orig)
{
    if(&orig == this)
        return *this;
    
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
    
    startmoney = new int(orig.GetStartmoney());
    pirateprob = new int(orig.GetPirateprob());
    shipprice = new int(orig.GetShipprice());
    crewprice = new int(orig.GetCrewprice());
    fishprice = new int(orig.GetFishprice());
    cargobuy = new int(orig.GetCargobuy());
    cargosell = new int(orig.GetCargosell());
    harborcrew = new int(orig.GetHarborcrew());
    eventprob = new int(orig.GetEventprob());
    storm = new int(orig.GetStorm());
    sirens = new int(orig.GetSirens());
    calm = new int(orig.GetCalm());
    riot = new int(orig.GetRiot());
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