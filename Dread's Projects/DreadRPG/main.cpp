#include "Game.h"

int main(int argc, char** argv)
{
    Game* game = new Game();
    
    game->Start();
    
    return 0;
}

//keeping this here to remember for the next time I pick this up
//PS: DO NOT LEAVE THIS HERE DUMBASS!

template<typename Base, typename T>
    inline bool instanceof(const T *ptr) {
        return dynamic_cast<const Base*>(ptr) != nullptr;
    }