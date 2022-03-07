#include <cstdlib>
#include <iostream>

#include "Player.h"
#include "Monster.h"

int main(int argc, char** argv)
{
	std::cout << "Welcome to Monster Slayer... again." << std::endl;
	std::cout << "Now with 10x more complicated code base" << std::endl;

	std::getchar();

	std::cout << "\033c";

	std::cout << "What's your name?" << std::endl;

	std::string name;

	std::getline(std::cin, name);

	Player* player = new Player(name);
	Monster* monster = new Monster();

	std::cout << "\033c";

	std::cout << "Welcome to the game " << player->getName() << std::endl;

	std::getchar();

	std::cout << "\033c";

	while (true)
	{

	}

	return 0;
}