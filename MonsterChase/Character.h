#pragma once

#include <string>

class Character
{
	public:
		//Returns or Sets X Position of the Character
		int PosX();
		void PosX(int posX);

		//Returns or Sets Y Position of the Character
		int PosY();
		void PosY(int posY);

		//Returns the Name of the Character
		std::string GetName();

	protected:
		//X Position of the Character
		int posX;

		//Y Position of the Character
		int posY;

		//Indicates whether the Character is Alive
		bool isAlive = false;

		//Name of the Character
		std::string name;
};
