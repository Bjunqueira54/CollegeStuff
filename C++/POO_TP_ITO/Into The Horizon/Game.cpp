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
    
    player = new Player(playername, settings->GetStartmoney(), map->getHarbor(mh(rng)));
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
    
    player->buyShip(i);
    player->setMoney(0-settings->GetShipprice());
}

int Game::PlayerSellShip(int id)
{
    int crew, fish, cargo, money;
    crew = player->getCrew(id);
    fish = player->getFish(id);
    cargo = player->getCargo(id);
    
    money = (crew * settings->GetCrewprice()) + (fish * settings->GetFishprice()) + (cargo * settings->GetCargosell());
    player->sellShip(id);
    player->setMoney(money);
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