#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <vector>
#include <iostream>
#include <fstream>
#include <string>

#include "Player.h"
#include "Monster.h"

int main()
{
	//Initialises the Player!
	Player player1;
	
	//Creates Monsters for the Player to Face, based on Player Input
	int numMonsters;
	std::cout << "\nHow brave do you feel, " << player1.GetName() << "? How many monsters do you dare face? ";
	scanf("%d", &numMonsters);
	printf("\n");
	
	//Creates a Vector of Desired Number of Monster Objects
	std::vector<Monster> monsters(numMonsters);
	
	//Opens a file and randomly selects names from this file for Monster Names
	std::string nameArray[7775];
	std::ifstream names;
	names.open("monsterNames.dat");
	int index = 0;

	while (index < 7775)
	{
		getline(names, nameArray[index]);
		index++;
	}

	for (int i = 0; i < numMonsters; i++)
	{
		monsters[i].SetName(nameArray[rand() % 7775]);
	}

	//Inputs the Randomly Selected Monster Names
	for (int i = 0; i < numMonsters; i++)
	{
		std::cout << "\nHere is the name of monster " << i + 1 << ": " << monsters[i].GetName() << std::endl;
		std::cout << "He has " << monsters[i].turnsRemaining << " turns remaining!\n";
	}

	//Outputs the Positions of All the Monsters
	printf("\n");
	for (int i = 0; i < numMonsters; i++)
	{
		std::cout << "\nMonster " << i+1 << " is at position: [" << monsters[i].PosX()+1 << "," << monsters[i].PosY()+1 << "]";
	}

	printf("\n\n**********************************************\n");
	
	//Let the Games Begin!
	char dir = 'z';
	while (dir != 'q')
	{
		std::cout << "\nYour Move, " << player1.GetName() << ". Use WASD to Move and Q to Quit: ";
		std::cin >> dir;

		player1.Move(dir);

		std::cout << "\nYou are now at: [" << player1.PosX()+1 << "," << player1.PosY()+1 << "]\n" ;

		for (int i = 0; i < numMonsters; i++)
		{
			monsters[i].Move();
			
			if (player1.PosX() == monsters[i].PosX() && player1.PosY() == monsters[i].PosY())
			{
				player1.isAlive = false;
			}

			if (monsters[i].isAlive == false)
			{
				std::cout << "Monster " << i + 1 << "died";
			}

			else
			{
				std::cout << "\nMonster " << i + 1 << " is at position: [" << monsters[i].PosX() + 1 << "," << monsters[i].PosY() + 1 << "]";
			}
		}
		
		if (player1.isAlive == false)
		{
			printf("\n\n**********************************************\n");
			std::cout << "\nYou died!";
			getchar();
			dir = 'q';
		}

		printf("\n\n**********************************************\n");
	
	}

	getchar();

	return(0);
}