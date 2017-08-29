#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#include <iostream>

#include "Player.h"

//Player Constructor
Player::Player()
{
	srand(time(NULL));

	isAlive = true;

	std::cout << "\nEnter your Name, Valiant Warrior: ";
	std::cin >> name;

	posX = rand() % 10;
	posY = rand() % 10;

	std::cout << "\nHello " << name << "!";
	std::cout << "\nIt looks like you have spawned at: [" << posX + 1 << "," << posY + 1 << "]";
	std::cout << "\n\n**********************************************\n";
	getchar();
}

int Player::Move(char dir)
{
	switch (dir)
	{
		case 'W':
		case 'w':
			posY += 1;
			break;

		case 'A':
		case 'a':
			posX -= 1;
			break;

		case 'S':
		case 's':
			posY -= 1;
			break;

		case 'D':
		case 'd':
			posX += 1;
			break;

		default:
			printf("\nEnter a Valid WASD Movement Direction!");
	}

	if (posX < 0 || posX > 9 || posY < 0 || posY > 9)
	{
		isAlive = false;
		return -1;
	}
}