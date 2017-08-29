#pragma once

#include "Character.h"

#include <string>



class Monster : public Character
{
	public:
		Monster();

		int Move();

		void SetName(std::string name);

		int turnsRemaining;
};