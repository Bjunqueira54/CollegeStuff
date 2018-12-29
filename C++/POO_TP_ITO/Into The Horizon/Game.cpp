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
    for(int i=0; i<player->getNships(); i++)
    {
        string destCoord, curCoord, sid;
        int y, x, desty, destx, newy, newx;
        int id;
        istringstream is;
        ostringstream os;
        
        sid = player->getShipID(i);
        is.str(sid);
        is >> id;
        if(id == 0)
            continue;
        
        curCoord = player->getShipCoord(id);
        destCoord = player->getShipDestCoord(id);
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
    int y, x, desty, destx;
    istringstream is;
    ostringstream os;
    
    is.str(curCoord);
    
    is >> y;
    is >> x;
    
    for(int i=0; i<2; i++)
    {
        switch(tolower(dir[i]))
        {
            case 'c':
                destx = x;
                desty = y - 1;
            case 'e':
                destx = x - 1;
                desty = y;
            case 'b':
                destx = x;
                desty = y + 1;
            case 'd':
                destx = x + 1;
                desty = y;
            default:
                break;
        }
    }
    
    os << y << " " << x;
    
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
    
    return player->ShipMove(id, destCoord, isDestHarbor);
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