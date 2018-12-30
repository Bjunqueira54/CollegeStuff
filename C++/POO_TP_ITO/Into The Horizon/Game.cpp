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
        nextCoord = nextTurnMoveShip(i);
        
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
            case 'e':
                destx = destx - 1;
            case 'b':
                desty = desty + 1;
            case 'd':
                destx = destx + 1;
            default:
                break;
        }
    }
    
    os << desty << " " << destx;
    
    return os.str();
}

int Game::PlayerShipMove(int id, string dir)
{
    string destCoord;
    bool isDestHarbor = false;
    destCoord = getDestCoord(player->getShipCoord(id), dir);
    
    if(destCoord == "")
        return -1;
    
    for(int i=0; i<map->getTotalHarborTiles(); i++)
    {
        if(map->getHarborCoord(i) == destCoord)
        {
            isDestHarbor = true;
            break;
        }
    }
    
    return player->ShipSetDestination(id, destCoord, isDestHarbor);
}

string Game::nextTurnMoveShip(int i)
{
    int y, x, desty, destx, newy, newx, maxy, maxx;
    int id;
    double val;
    bool valid = false;
    string curCoord, destCoord;
    istringstream is;
    ostringstream os;
    
    mt19937 rng(time(NULL));
    uniform_int_distribution<int> hdir(-100, 100);
    uniform_int_distribution<int> vdir(-100, 100);

    id = player->getShipID(i);

    //Standard error value. If this happens, return an empty string and let the caller handle it.
    if(id == -1)
        return "";

    curCoord = player->getShipCoord(id);
    destCoord = player->getShipDestCoord(id);

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

    do
    {
        if(x != destx)
        {
            val = hdir(rng);

            if(((x-1) + (maxx - destx)) < destx - x)
            {
                if(val - 75 > 0)
                    newx = x + 1;
                else if(val == 0)
                    newx = x;
                else
                    newx = x - 1;
            }
            else
            {
                if(val + 75 < 0)
                    newx = x - 1;
                else if(val == 0)
                    newx = x;
                else
                    newx = x + 1;
            }
        }

        if(y != desty)
        {
            val = vdir(rng);

            if(((y-1) + (maxy - desty)) < desty - y)
            {
                if(val - 75 > 0)
                    newy = y + 1;
                else if(val == 0)
                    newy = y;
                else
                    newy = y - 1;
            }
            else
            {
                if(val + 75 < 0)
                    newy = y - 1;
                else if(val == 0)
                    newy = y;
                else
                    newy = y + 1;
            }
        }
        os.str("");
        os.clear();
        os << newy << " " << newx;
        
        for(int i=0; i<map->getTotalOceanTiles(); i++)
        {
            if(map->getOceanCoord(i) == os.str())
            {
                valid = true;
                break;
            }
        }
        
        if(!valid)
        {
            for(int i=0; i<map->getTotalHarborTiles(); i++)
            {
                if(destCoord == map->getHarborCoord(i) && os.str() == map->getHarborCoord(1))
                {
                    valid = true;
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