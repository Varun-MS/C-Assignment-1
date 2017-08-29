#include <stdio.h>
#include "Character.h"

int Character::PosX()
{
	return posX;
	
}

void Character::PosX(int posX)
{
	this->posX = posX;
}

int Character::PosY()
{
	return posY;
}

void Character::PosY(int posY)
{
	this->posY = posY;
}

std::string Character::GetName()
{
	return name;
}