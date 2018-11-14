#include "Ship.h"

using namespace std;

Ship::Ship(int i, char t): id(i), type(t)
{
    switch(t)
    {
        case 'V':
        {
            move = new int(2);
            maxcrew = new int(20);
            maxtons = new int(40);
            maxwater = new int(200);
            break;
        }
        case 'G':
        {
            move = new int(1);
            maxcrew = new int(40);
            maxtons = new int(70);
            maxwater = new int(400);
            break;
        }
        case 'E':
        {
            move = new int(2);
            maxcrew = new int(10);
            maxtons = new int(20);
            maxwater = new int(100);
            break;
        }
        case 'F':
        {
            move = new int(2);
            maxcrew = new int(50);
            maxtons = new int(0);
            maxwater = new int(500);
            break;
        }
        case 'S': //SHIP OF THE LINE! My precious lil' beast
        {
            move = new int(5);
            maxcrew = new int(300);
            maxtons = new int(100);
            maxwater = new int(1000);
            break;
        }
        default:
            delete this;  //Whatever t was, it doesn't exist, so delete this; How did you even get into default anyway?
    }
}

int Ship::getId() const
{
    return id;
}

Ship::~Ship()
{
    delete move;
    delete maxcrew;
    delete maxtons;
    delete maxwater;
}