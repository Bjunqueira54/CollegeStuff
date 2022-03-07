#pragma once
#include <cstdlib>
#include <string>

#include "Entity.h"
class Player : public Entity
{
	std::string name;

public:
	Player(std::string name) : Entity(100, 30)
	{
		this->name = name;
	}

	std::string getName() { return this->name; }
};