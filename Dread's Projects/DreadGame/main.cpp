#include "includes.h"
#include "DreadGame.h"

int main(int argc, char** argv)
{
    DreadGame *game = new DreadGame();
    
    game->Init();
    
    return 0;
}