#pragma once

#include "Character.h"

class Player : public Character
{
	public:
		//Player Constructor
		Player();

		//Moves Player in Direction that they Wish to Move
		int Move(char dir);
};

