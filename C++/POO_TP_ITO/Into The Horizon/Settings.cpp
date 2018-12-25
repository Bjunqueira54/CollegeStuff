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

Settings::Settings(const Settings& orig) {}

Settings::~Settings() {}