#pragma once
#include "../includes.h"

class Spell
{
	const string name;

public:

	Spell() = delete;

	Spell(string n);

	virtual const string getInfo() const = delete;

	virtual ~Spell();
};

