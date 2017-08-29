#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Monster.h"

//Monster Constructor
Monster::Monster()
{
	isAlive = true;

	//Initializes the Monsters Positions. A Position of -1 means they are not on the grid.
	posX = rand() % 10;
	posY = rand() % 10;

	//Sets a Random Life for the Monster
	turnsRemaining = rand() % 10;
}

int Monster::Move()
{
	//Decides whether the monster moves along the vertical or horizontal axis
	int tempDir = rand() % 4;

	if (tempDir == 0)
		posX += rand() % 2;

	else if (tempDir == 1)
		posY += rand() % 2;

	else if (tempDir == 1)
		posY -= rand() % 2;

	else
		posX -= rand() % 2;

	if (posX < 0 || posX > 9 || posY < 0 || posY > 9)
	{
		isAlive = false;
		return -1;
	}

	turnsRemaining--;
	if (turnsRemaining == 0)
		isAlive = false;
}

void Monster::SetName(std::string name)
{
	this->name = name;
}