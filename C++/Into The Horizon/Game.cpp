#include "Game.h"

int Game::turn;
Player* Game::pirate;
Player* Game::player;
Settings* Game::settings;
Map* Game::map;

Game::Game() {}

Game::Game(const Game& orig) {}

Game::Game(string n): playername(n)
{
    turn = 1;
}

void Game::startGame()
{
    vector<int> fh;
    
    for(int i=0; i<map->getTotalHarborTiles(); i++)
    {
        if(map->harborIsFriendly(i))
            fh.push_back(i);
    }
    
    mt19937 rng(time(NULL));
    uniform_int_distribution<int> mh(0, fh.size()-1);
    
    player = new Player(playername, settings->GetStartmoney(), map->getHarbor(fh[mh(rng)]));
    pirate = new Player("Pirates", 0, nullptr);
}

void Game::configPhase(ifstream& file)
{
    if(phase != 0)
	return;
    
    settings = new Settings(file);
    map = new Map(settings->getMap());
    phase = 1;
}

void Game::nextTurn()
{
    string nextCoord;
    istringstream is;
    int y, x, faultruns = 0;
    
    for(int i=0; i<player->getNships(); i++)
    {
        int id = player->getShipID(i);
        int moves = player->getShipMoves(id);
        
        if(player->getShipCoord(id) == player->getShipDestCoord(id))
            continue;
        
        do
        {
            nextCoord = nextTurnMoveShip(id);

            if(nextCoord == "")
            {
                faultruns++;

                if(faultruns >= 3)
                    break;
                continue;
            }

            is.clear();
            is.str(nextCoord);

            is >> y;
            is >> x;

            if(y == 0 || x == 0)
            {
                faultruns++;

                if(faultruns >= 3)
                    break;
                continue;
            }

            if(player->ShipMove(player->getShipID(i), y, x) == -1)
            {
                faultruns++;

                if(faultruns >= 3)
                    break;
                continue;
            }
            
            moves--;
        }
        while((moves > 0) && (faultruns < 3));
        
        if(!player->getShipSpecMoving(id))
        {
            player->ShipSetDestination(id, player->getShipCoord(id), player->getShipInHarbor(id));
        }
    }
    
    for(int i=0; i<pirate->getNships(); i++)
    {
        
    }
    
    turn++;
}

int Game::PlayerBuyShip(char t)
{
    int i;
    
    if(tolower(t) == 'v')
        i = 1;
    else if(tolower(t) == 'g')
        i = 2;
    else if(tolower(t) == 'e')
        i = 3;
    else if(tolower(t) == 'f')
        i = 4;
    else if(tolower(t) == 's')
        i = 5;
    else
        return -1;
    
    player->buyShip(i);
    player->setMoney(0-settings->GetShipprice());
    return 0;
}

int Game::PlayerSellShip(int id)
{
    int crew, fish, cargo, money;
    crew = player->getCrew(id);
    fish = player->getFish(id);
    cargo = player->getCargo(id);
    
    money = (crew * settings->GetCrewprice()) + (fish * settings->GetFishprice()) + (cargo * settings->GetCargosell()) + getShipPrice();
    player->sellShip(id);
    player->setMoney(money);
}

int Game::PlayerBuyCargo(int id, int cargo)
{
    int retval, total;
    
    total = cargo * settings->GetCargobuy();
    
    if(player->getMoney() > total)
    {
        retval = player->ShipSetCargo(id, cargo);
        
        if(retval == 0)
        {
            total = total * (-1);
            player->setMoney(total);
            return 0;
        }
        else if(retval == -1)
            return -1;
        else if(retval > 0)
        {
            int aux = cargo;
            
            aux -= retval;
            total = aux * settings->GetCargobuy();
            total = total * (-1);
            player->setMoney(total);
            return 0;
        }
    }
    else
        return -1;
}

int Game::PlayerBuyCrew(int id, int crew)
{
int retval, total;
    
    total = crew * settings->GetCrewprice();
    
    if(player->getMoney() > total)
    {
        retval = player->ShipSetCrew(id, crew);
        
        if(retval == 0)
        {
            total = total * (-1);
            player->setMoney(total);
            return 0;
        }
        else if(retval == -1)
            return -1;
        else if(retval > 0)
        {
            int aux = crew;
            
            aux -= retval;
            total = aux * settings->GetCrewprice();
            total = total * (-1);
            player->setMoney(total);
            return 0;
        }
    }
    else
        return -1;
}

string Game::getDestCoord(string curCoord, string dir)
{
    int desty, destx;
    istringstream is;
    ostringstream os;
    
    is.str(curCoord);
    
    is >> desty;
    is >> destx;
    
    //This next block stops the player from inputing a string that makes the
    //ship move more than intended by having string with the format like "dd"
    //or "Dd" to make the ship move twice in the same direction, but the game
    //will only count it has 1 move.
    //Since the block after this one will only process at most 2 characters,
    //this code will only need to check if the string has more than 1 char. and
    //if it does, convert them both to lower case and compares them to see if
    //it's the same character. If it is, it'll enter a loop to eliminate every
    //character except the first one until the string only has 1 character.
    if(dir.size() > 1)
    {
        if(tolower(dir[0]) == tolower(dir[1]))
        {
            while(dir.size() != 1)
                dir.pop_back();
        }
    }
    
    //Processes the string <dir>, considering at most 2 characters in the string.
    //Updates the destination coordinates depending of the character processed.
    //Note: Unfortunatelly, I cannot, at least in a simple way, determine if the
    //player wrote a string in the case of "cb" (up-down). Although it won't break
    //anything within the game, it's a redundant string format that won't do anything.
    //Although if I actually could detect such strings in a simple way, I'd probably 
    //make them not do anything either, so redundat text. ¯\_(ツ)_/¯
    for(int i=0; i<2 && i<dir.size(); i++)
    {
        switch(tolower(dir[i]))
        {
            case 'c':
                desty = desty - 1;
                break;
            case 'e':
                destx = destx - 1;
                break;
            case 'b':
                desty = desty + 1;
                break;
            case 'd':
                destx = destx + 1;
                break;
            default:
                break;
        }
    }
    
    os << desty << " " << destx;
    
    return os.str();
}

int Game::PlayerShipMoveTo(int id, int xx, int yy)
{
    ostringstream os;
    
    os << yy << " " << xx;
    
    for(int i=0; i<map->getTotalOceanTiles(); i++)
    {
        if(map->getOceanCoord(i) == os.str())
        {
            player->ShipSetDestination(id, os.str(), 0);
            return 0;
        }
    }
    
    for(int i=0; i<map->getTotalHarborTiles(); i++)
    {
        if(map->getHarborCoord(i) == os.str())
        {
            if(map->harborIsFriendly(i))
                player->ShipSetDestination(id, os.str(), 1);
        }
    }
    
    return -1;
}

int Game::PlayerShipMoveTo(int id, char hid)
{
    string destCoord;
    
    for(int i=0; i<map->getTotalHarborTiles(); i++)
    {
        if(map->getHarborID(i) == hid)
        {
            destCoord = map->getHarborCoord(i);
            
            if(map->harborIsFriendly(i))
                player->ShipSetDestination(id, destCoord, 1);
            
            return 0;
        }
    }
    
    return -1;
}

int Game::PlayerShipMove(int id, string dir)
{
    string destCoord;
    bool isDestHarbor = false;
    bool valid = false;
    
    if(player->getShipSpecMoving(id))
    {
        destCoord = getDestCoord(player->getShipCoord(id), dir);
        player->toggleShipSpecMoving(id);
    }
    else
    {
        destCoord = getDestCoord(player->getShipDestCoord(id), dir);
    }
        
    
    if(destCoord == "")
        return -1;
    
    for(int i=0; i<map->getTotalOceanTiles(); i++)
    {
        if(map->getOceanCoord(i) == destCoord)
        {
            isDestHarbor = false;
            valid = true;
            break;
        }
    }
    
    if(!valid)
    {
        for(int i=0; i<map->getTotalHarborTiles(); i++)
        {
            if(map->getHarborCoord(i) == destCoord)
            {
                isDestHarbor = true;
                valid = true;
                break;
            }
        }
    }
    
    if(!valid)
        return -1;
    else
        return player->ShipSetDestination(id, destCoord, isDestHarbor);
}

int Game::PlayerSell(int id)
{
    int fish, flo, cargo, clo, total;
    
    fish = player->getShipFish(id);
    cargo = player->getShipCargo(id);
    
    if(fish == -1 || cargo == -1)
        return -1;
    
    clo = player->ShipSetCargo(id, (cargo * (-1)));
    flo = player->ShipSetFish(id, (fish * (-1)));
    
    //wtf happened? If you ask to sell whatever getShipX() returns, there should be
    //no leftovers nor should the function return -1.
    if(clo != 0 || flo != 0)
        return -1;
    
    total = fish * settings->GetFishprice();
    total += cargo * settings->GetCargosell();
    
    player->setMoney(total);
    
    return 0;
}

string Game::nextTurnMoveShip(int id)
{
    int y, x, desty, destx, newy, newx, maxy, maxx;
    double val;
    bool valid = false;
    string curCoord, destCoord;
    istringstream is;
    ostringstream os;
    
    mt19937 rng(time(NULL));
    uniform_int_distribution<int> dir(0, 100);

    //Standard error value. If this happens, return an empty string and let the caller handle it.
    if(id == -1)
        return "";

    curCoord = player->getShipCoord(id);
    destCoord = player->getShipDestCoord(id);
    
    if(curCoord == destCoord)
        return curCoord;

    is.str(curCoord);
    is >> y;
    is >> x;

    is.clear();
    is.str(destCoord);
    is >> desty;
    is >> destx;
    
    is.clear();
    is.str(map->getDim());
    is >> maxy;
    is >> maxx;

    //These are invalid values for coordinates, so just return an empty string and let the caller handle it.
    if(x == 0 || y == 0 || destx == 0 || desty == 0 || maxx == 0 || maxy == 0)
        return "";

    //If I don't get the time to write what I'm doing here, I'll just leave it with this quote I found on
    //the internet once:
    //"If it was hard to code it, it's hard to understand it"
    do
    {
        if(x != destx)
        {
            val = dir(rng);

            if(x > destx)
            {
                if(x-destx > (maxx - x) + (destx - 1) + 1)
                {
                    (val > 15) ? (newx = x + 1) : (newx = x - 1);
                }
                else
                {
                    if(x - destx > 1)
                        (val > 15) ? (newx = x - 1) : (newx = x + 1);
                    else
                        newx = destx;
                }
            }
            else
            {
                if(destx-x > (maxx - destx) + (x - 1) + 1)
                {
                    (val > 15) ? (newx = x - 1) : (newx = x + 1);
                }
                else
                {
                    if(destx - x > 1)
                        (val > 15) ? (newx = x + 1) : (newx = x - 1);
                    else
                        newx = destx;
                }
            }
        }
        else
        {
            val = dir(rng);
            
            if(val > 5)
                newx = x;
            else
            {
                val = dir(rng);
                if(val > 50)
                    newx = x - 1;
                else
                    newx = x + 1;
            }
        }
        
        if(newx > maxx)
                newx = 1;
            else if(newx < 1)
                newx = maxx;

        if(y != desty)
        {
            val = dir(rng);

            if(y > desty)
            {
                if(y-desty > (maxy - y) + (desty - 1) + 1)
                {
                    (val > 15) ? (newy = y + 1) : (newy = y - 1);
                }
                else
                {
                    if(y - desty > 1)
                        (val > 15) ? (newy = y - 1) : (newy = y + 1);
                    else
                        newy = desty;
                }
            }
            else
            {
                if(desty-y > (maxy - desty) + (y - 1) + 1)
                {
                    (val > 15) ? (newy = y - 1) : (newy = y + 1);
                }
                else
                {
                    if(desty - y > 1)
                        (val > 15) ? (newy = y + 1) : (newy = y - 1);
                    else
                        newy = desty;
                }
            } 
        }
        else
        {
            val = dir(rng);
            
            if(val > 5)
                newy = y;
            else
            {
                val = dir(rng);
                if(val > 50)
                    newy = y - 1;
                else
                    newy = y + 1;
            }
        }
        
        if(newy > maxy)
                newy = 1;
            else if(newy < 1)
                newy = maxy;
        
        os.str("");
        os.clear();
        os << newy << " " << newx;
        
        for(int i=0; i<map->getTotalOceanTiles(); i++)
        {
            if(map->getOceanCoord(i) == os.str())
            {
                valid = true;
                
                if(player->getShipInHarbor(id))
                    player->toggleShipInHarbor(id);
                
                break;
            }
        }
        
        if(!valid)
        {
            for(int i=0; i<map->getTotalHarborTiles(); i++)
            {
                if(os.str() == map->getHarborCoord(i))
                {
                    valid = true;
                    
                    if(!player->getShipInHarbor(id))
                        player->toggleShipInHarbor(id);
                    
                    break;
                }
            }
        }
    }
    while(!valid);
    
    return os.str();
}

Game::~Game()
{
    delete player;
    player = nullptr;
    delete pirate;
    pirate = nullptr;
    delete settings;
    settings = nullptr;
    delete map;
    map = nullptr;
}