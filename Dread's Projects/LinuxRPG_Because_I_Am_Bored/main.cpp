#include "includes.h"
#include "Game.h"

int main(int argc, char** argv)
{
    Game *game = new Game();
    //GameLog *log = new GameLog();
    //game->setLog(log);
    
    game->Start();
    
    return 0;
}