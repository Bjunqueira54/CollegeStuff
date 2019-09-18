#include "includes.h"
#include "Game.h"

int main(int argc, char** argv)
{
    Game *game = new Game();
    
    game->Start();
    
    return 0;
}