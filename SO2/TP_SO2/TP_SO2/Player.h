#ifndef PLAYER_H
#define PLAYER_H

#include "includes.h"

typedef struct PlayerEntity
{
	//Client Vars
	char *name;
	int score;

	//Barrier Vars
	double x;
	double y;

	int size;


} Player, *pPlayer;

#endif