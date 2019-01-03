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
    int y, x, id, faultruns = 0;
    
    //Player Auto algorith
    for(int i = 0; i<player->getNships(); i++)
    {
        id = player->getShipID(i);
        
        if(player->getShipAuto(id))
        {
            switch(player->getShipType(id))
            {
                case 1:
                {
                    if(player->getShipCoord(id) != player->getShipDestCoord(id))
                            break;
                    else if(player->getShipIsFull(id) && (player->getShipCoord(id) != player->getMainHarborCoord()))
                    {
                        player->ShipSetDestination(id, player->getMainHarborCoord(), true);
                    }
                    else if(player->getShipIsFull(id) && (player->getShipCoord(id) == player->getMainHarborCoord()))
                    {
                        PlayerSell(id);
                    }
                    
                    int id2 = 0;
                    bool valid = false;
                    string schCoord;
                    ostringstream os;
                    
                    for(int j=0; j<player->getNships(); j++)
                    {
                        id2 = player->getShipID(j);
                        if(player->getShipType(id2) == 3)
                        {
                            if(!player->getShipInHarbor(id2))
                                break;
                        }
                    }
                    
                    if(id2 != 0)
                    {
                        schCoord = player->getShipCoord(id2);
                        is.clear();
                        is.str(schCoord);
                        is >> y;
                        is >> x;
                        
                        if(y == 0 || x == 0)
                            break;
                        
                        do
                        {
                            mt19937 rng(time(NULL));
                            uniform_int_distribution<int> rand_dir(0,2);
                            int newx=x, newy=y, r;
                            
                            r = rand_dir(rng);
                            
                            if(r > 1)
                                newx++;
                            else if(r < 1)
                                newx--;
                            
                            r = rand_dir(rng);
                            
                            if(r > 1)
                                newy++;
                            else if(r < 1)
                                newy--;
                            
                            os << newy << " " << newx;
                            
                            for(int k=0; k<map->getTotalOceanTiles(); i++)
                            {
                                if(map->getOceanCoord(k) == os.str())
                                {
                                    valid = true;
                                    break;
                                }
                            }
                        }
                        while(!valid);
                        
                        player->ShipSetDestination(id, os.str(), false);
                    }
                    else
                    {
                        player->ShipStop(id);
                    }
                    
                    break;
                }
                case 2:
                {
                    player->ShipStop(id);
                    break;
                }
                case 3:
                {
                    string curCoord;
                    ostringstream os;
                    int count = 0;
                    bool valid = false;
                    
                    if(player->getShipCoord(id) != player->getShipDestCoord(id))
                    {
                        break;
                    }
                    else if(player->getShipIsFull(id) && (player->getShipDestCoord(id) != player->getMainHarborCoord()))
                    {
                        player->ShipSetDestination(id, player->getMainHarborCoord(), true);
                    }
                    else if(player->getShipIsFull(id) && (player->getShipDestCoord(id) == player->getMainHarborCoord()))
                    {
                        PlayerSell(id);
                        player->toggleShipAuto(id);
                    }
                    else if(!player->getShipIsFull(id) && (player->getShipDestCoord(id) == player->getMainHarborCoord()))
                    {
                        player->toggleShipAuto(id);
                    }
                    else if(player->getShipWater(id) < 25)
                    {
                        player->ShipSetDestination(id, player->getMainHarborCoord(), true);
                    }
                    
                    curCoord = player->getShipCoord(id);
                    
                    is.clear();
                    is.str(curCoord);
                    
                    is >> y;
                    is >> x;
                    
                    if(y == 0 || x == 0)
                        break;
                    
                    do
                    {
                        mt19937 rng(time(NULL));
                        uniform_int_distribution<int> rand_dir(0,4);
                        int newx=x, newy=y, r;

                        r = rand_dir(rng);

                        if(r > 2)
                        {
                            if(r > 3)
                                newx += 2;
                            else
                                newx++;
                        }
                        else if(r < 2)
                        {
                            if(r<1)
                                newx -= 2;
                            else
                                newx--;
                        }

                        r = rand_dir(rng);

                        if(r > 2)
                        {
                            if(r > 3)
                                newy += 2;
                            else
                                newy++;
                        }
                        else if(r < 2)
                        {
                            if(r<1)
                                newy -= 2;
                            else
                                newy--;
                        }

                        os << newy << " " << newx;

                        for(int k=0; k<map->getTotalOceanTiles(); k++)
                        {
                            if(map->getOceanCoord(k) == os.str())
                            {
                                if(map->getOceanFish(i) == 1)
                                {
                                    valid = true;
                                    break;
                                }
                            }
                        }
                        count++;
                        
                        if(count >= 24)
                        {
                            player->ShipSetDestination(id, player->getMainHarborCoord(), true);
                            valid = true;
                            player->toggleShipAuto(id);
                        }
                    }
                    while(!valid);
                    
                    if(player->getShipAuto(id))
                        player->ShipSetDestination(id, os.str(), false);

                    break;
                }
                case 4:
                {
                    string pirCoord, harCoord;
                    bool valid;
                    ostringstream os;
                    
                    if(pirate->getNships() > 0)
                    {
                        for(int j=0; j < pirate->getNships(); j++)
                        {
                            pirCoord = pirate->getShipCoord(pirate->getShipID(j));
                        }
                        
                        is.clear();
                        is.str(pirCoord);

                        is >> y;
                        is >> x;
                    }
                    else
                    {
                        for(int j=0; j < map->getTotalHarborTiles(); j++)
                        {
                            if(!map->harborIsFriendly(j))
                                harCoord = map->getHarborCoord(j);
                        }
                        
                        is.clear();
                        is.str(harCoord);

                        is >> y;
                        is >> x;
                    }
                    
                    do
                    {
                        mt19937 rng(time(NULL));
                        uniform_int_distribution<int> rand_dir(0,2);
                        int newx=x, newy=y, r;

                        r = rand_dir(rng);

                        if(r > 1)
                            newx++;
                        else if(r < 1)
                            newx--;

                        r = rand_dir(rng);

                        if(r > 1)
                            newy++;
                        else if(r < 1)
                            newy--;

                        os << newy << " " << newx;

                        for(int k=0; k<map->getTotalOceanTiles(); i++)
                        {
                            if(map->getOceanCoord(k) == os.str())
                            {
                                valid = true;
                                break;
                            }
                        }
                    }
                    while(!valid);
                    
                    player->ShipSetDestination(id, os.str(), false);
                    
                    break;
                }
                case 5:
                    break;
            }
        }
    }
    
    //Player Moving Algorithm
    for(int i=0; i<player->getNships(); i++)
    {
        id = player->getShipID(i);
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
        
        if(player->getShipType(id) == 3)
        {
            for(int j=0; j < map->getTotalOceanTiles(); j++)
            {
                if(map->getOceanCoord(j) == player->getShipCoord(id))
                {
                    if(map->getOceanFish(j) == 1)
                    {
                        player->ShipFish(id);
                        map->OceanFished(map->getOceanCoord(j));
                    }
                }
            }
        }
    }
    
    //Pirate Auto Algorithm
    for(int i=0; i<pirate->getNships(); i++)
    {
        id = pirate->getShipID(i);
        
        if(pirate->getShipAuto(id))
        {
            string plCoord, harCoord;
            bool valid;
            ostringstream os;
            
            if(pirate->getShipCoord(id) != pirate->getShipDestCoord(id))
            {
                break;
            }
            else if(pirate->getCrew(id) < (pirate->getShipmaxCrew(id) / 2))
            {
                for(int j = 0; j < map->getTotalHarborTiles(); j++)
                {
                    if(!map->harborIsFriendly(j))
                    {
                        harCoord = map->getHarborCoord(j);
                        break;
                    }
                }
                
                pirate->ShipSetDestination(id, harCoord, true);
            }
            
            mt19937 rng(time(NULL));
            uniform_int_distribution<int> porh(0, 1);
            uniform_int_distribution<int> rship(1, player->getNships());

            if(porh(rng) == 1)
            {
                plCoord = player->getShipCoord(player->getShipID(rship(rng)));

                is.clear();
                is.str(plCoord);
            }
            else
            {
                for(int j=0; j < map->getTotalHarborTiles(); j++)
                {
                    if(map->harborIsFriendly(j))
                    {
                        harCoord = map->getHarborCoord(j);
                        break;
                    }
                }
                
                is.clear();
                is.str(harCoord);
            }
            
            is >> y;
            is >> x;

            if(y == 0 || x == 0)
                break;

            do
            {
                mt19937 rng(time(NULL));
                uniform_int_distribution<int> rand_dir(0,2);
                int newx=x, newy=y, r;

                r = rand_dir(rng);

                if(r > 1)
                    newx++;
                else if(r < 1)
                    newx--;

                r = rand_dir(rng);

                if(r > 1)
                    newy++;
                else if(r < 1)
                    newy--;

                os << newy << " " << newx;

                for(int k=0; k<map->getTotalOceanTiles(); i++)
                {
                    if(map->getOceanCoord(k) == os.str())
                    {
                        valid = true;
                        break;
                    }
                }
            }
            while(!valid);
            
            pirate->ShipSetDestination(id, os.str(), false);
        }
    }
    
    //Pirate Moving Algorithm
    for(int i=0; i<pirate->getNships(); i++)
    {
        id = pirate->getShipID(i);
        int moves = pirate->getShipMoves(id);
        
        if(pirate->getShipCoord(id) == pirate->getShipDestCoord(id))
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

            if(pirate->ShipMove(pirate->getShipID(i), y, x) == -1)
            {
                faultruns++;

                if(faultruns >= 3)
                    break;
                continue;
            }
            
            moves--;
        }
        while((moves > 0) && (faultruns < 3));
    }
    
    map->OceanTurnUpdate();
    
    //New Pirate Chance
    {
        mt19937 rng(time(NULL));
        uniform_int_distribution<int> piratespawn(0, 100);
        uniform_int_distribution<int> randx(1, 20);
        uniform_int_distribution<int> randy(1, 10);
        bool valid = false, sih = false;

        if(piratespawn(rng) > settings->GetPirateprob())
        {
            do
            {
                ostringstream os;
                
                x = randx(rng);
                y = randy(rng);
                
                os << y << " " << x;
                
                for(int i=0; i<map->getTotalOceanTiles(); i++)
                {
                    if(map->getOceanCoord(i) == os.str())
                    {
                        valid = true;
                        sih = false;
                        break;
                    }
                }
                if(!valid)
                {
                    for(int i=0; i<map->getTotalHarborTiles(); i++)
                    {
                        if(map->getHarborCoord(i) == os.str())
                        {
                            valid = true;
                            sih = true;
                            break;
                        }
                    }
                }
                
                if(player->CoordExists(os.str()))
                    valid = false;
                else if(pirate->CoordExists(os.str()))
                    valid = false;
            }
            while(!valid);

            if(piratespawn(rng) > 50)
            {
                pirate->spawnship(1, x, y, sih);
            }
            else
            {
                pirate->spawnship(4, x, y, sih);
            }
        }
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

int Game::PlayerShipMoveTo(int id, int xx, int yy, int faction)
{
    ostringstream os;
    
    os << yy << " " << xx;
    
    for(int i=0; i<map->getTotalOceanTiles(); i++)
    {
        if(map->getOceanCoord(i) == os.str())
        {
            if(faction == 1)
                player->ShipSetDestination(id, os.str(), 0);
            else if(faction == 2)
                pirate->ShipSetDestination(id, os.str(), 0);
            return 0;
        }
    }
    
    for(int i=0; i<map->getTotalHarborTiles(); i++)
    {
        if(map->getHarborCoord(i) == os.str())
        {
            if(faction == 1)
            {
                if(map->harborIsFriendly(i))
                {
                    player->ShipSetDestination(id, os.str(), 1);
                }
            }
            else if(faction == 2)
            {
                if(!map->harborIsFriendly(i))
                {
                    player->ShipSetDestination(id, os.str(), 1);
                }
            }
        }
    }
    
    return -1;
}

int Game::PlayerShipMoveTo(int id, char hid, int faction)
{
    string destCoord;
    
    for(int i=0; i<map->getTotalHarborTiles(); i++)
    {
        if(map->getHarborID(i) == hid)
        {
            destCoord = map->getHarborCoord(i);
            
            if(faction == 1)
            {
                if(map->harborIsFriendly(i))
                {
                    player->ShipSetDestination(id, destCoord, 1);
                }
            }
            else if(faction == 2)
            {
                if(!map->harborIsFriendly(i))
                {
                    player->ShipSetDestination(id, destCoord, 1);
                }
            }
            
            return 0;
        }
    }
    
    return -1;
}

int Game::PlayerShipMove(int id, string dir)
{
    string destCoord;
    int regmove, retval;
    bool isDestHarbor = false;
    bool valid = false;
    
    if(player->getShipAuto(id))
        player->toggleShipAuto(id);
    
    if(player->getShipSpecMoving(id))
    {
        destCoord = getDestCoord(player->getShipCoord(id), dir);
        player->toggleShipSpecMoving(id);
    }
    else
    {
        destCoord = getDestCoord(player->getShipDestCoord(id), dir);
        
        //I need this var here to know whether the ship is trying to move
        //while the SpecMoving bool was set or not.
        //In earlier versions, the command combo "move <id> <dir>" x2
        //would get overwriten because of the SpecMoving boolean, resulting
        //in all of the ships only moving once regardless of their moves.
        regmove = 1;
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
    {
        retval = player->ShipSetDestination(id, destCoord, isDestHarbor);
        
        if(regmove == 1)
            player->toggleShipSpecMoving(id);

        return retval;
    }
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

int Game::PirateAddShip(char t, int y, int x)
{
    int sih = -1;
    ostringstream os;
    os << y << " " << x;
    
    for(int i=0; i<map->getTotalHarborTiles(); i++)
    {
        if(map->getHarborCoord(i) == os.str())
        {
            sih = 1;
            break;
        }
    }
    
    if(sih != 1 && sih != 0)
    {
        for(int i=0; i<map->getTotalOceanTiles(); i++)
        {
            if(map->getOceanCoord(i) == os.str())
            {
                sih = 0;
                break;
            }
        }
    }
    
    if(sih == -1)
        return -1;
    
    switch(tolower(t))
    {
        case 'v':
            pirate->spawnship(1, y, x, sih);
            break;
        case 'f':
            pirate->spawnship(4, y, x, sih);
            break;
        default:
            return -1;
    }
    
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

const string Game::getPlayerShipCoord(int id, int faction) const
{
    if(faction == 1)
        return player->getShipCoord(id);
    else if(faction == 2)
        return pirate->getShipCoord(id);
}

const string Game::getPlayerShipInfo(int id, int faction) const
{
    if(faction == 1)
        return player->getShipInfo(id);
    else if(faction == 2)
        return pirate->getShipInfo(id);
}

const bool Game::getPlayerShipInHarbor(int id, int faction) const
{
    if(faction == 1)
        return player->getShipInHarbor(id);
    else if(faction == 2)
        return pirate->getShipInHarbor(id);
}

const int Game::getPlayerFleetSize(int faction) const
{
    if(faction == 1)
        return player->getNships();
    else if(faction == 2)
        return pirate->getNships();
}

const int Game::getPlayerShipType(int id, int faction) const
{
    if(faction == 1)
        return player->getShipType(id);
    else if(faction == 2)
        return pirate->getShipType(id);
}

const int Game::getPlayerShipID(int i, int faction) const
{
    if(faction == 1)
        return player->getShipID(i);
    else if(faction == 2)
        return pirate->getShipID(i);
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