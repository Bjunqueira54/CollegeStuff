#include "Harbor.h"
#include "Player.h"
#include "Functions.h"

Harbor::Harbor(int yy, int xx, char a): y(yy), x(xx), id(a), soldiers(settings.harborCrew())
{
    if(id>='A' && id <='Z')
        PFriend = true;
    else if(id>='a' && id<='z')
        PFriend = false;
}

bool Harbor::isFriend() const
{
    return PFriend;
}

string Harbor::getCoord() const
{
    ostringstream os;
    os << x << " " << y;
    return os.str();
}

void Harbor::becomeMain(Player& player)
{
    player.setMainHarbor(*this);
}

Harbor::~Harbor() {
}

