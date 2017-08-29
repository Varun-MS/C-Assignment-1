#pragma once

class Player
{
	public:
		//Player Constructor
		Player();
		
		//Function that Moves that Moves Character
		int Move(char dir);

		//Returns X Position of the Character
		int PosX();

		//Returns Y Position of the Character
		int PosY();
};

