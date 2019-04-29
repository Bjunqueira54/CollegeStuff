#ifndef BRICK_H
#define BRICK_H

typedef struct BrickEntity
{
	double x;
	double y;

	int hits; //Normal, Magic - 1; Resistant - 2 or 4

} Brick, *pBrick;

#endif