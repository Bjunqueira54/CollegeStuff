#ifndef POWERUP_H
#define POWERUP_H

#include "includes.h"

typedef struct PowerUpEntity
{
	double x;
	double y;

	int type; //Tells what type it is. DEFINE LATER
} PowerUp, *pPowerUp;

#endif