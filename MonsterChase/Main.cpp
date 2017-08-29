#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <vector>
#include <iostream>
#include <fstream>
#include <string>

#include "Arena.h"
#include "Player.h"
#include "Monster.h"

int main()
{
	//Initialises the Arena!
	Arena arena;

	//Initialises the Player!
	Player player1;
	
	//Creates Monsters for the Player to Face, based on Player Input
	int numMonsters;
	printf("\nHow brave do you feel, warrior? How many monsters do you dare face? ");
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
		std::cout << "Here is the name of monster " << i + 1 << ": " << monsters[i].GetName() << std::endl;
	}

	//Outputs the Positions of All the Monsters
	printf("\n");
	for (int i = 0; i < numMonsters; i++)
	{
		printf("\nMonster %d is at position %d,%d", i + 1, monsters[i].PosX(), monsters[i].PosY());
	}

	printf("\n\n**********************************************\n");
	
	//Let the Games Begin!
	char dir = 'z';
	while (dir != 'q')
	{
		std::cout << "Your Move, " << player1.GetName() << "!" << std::endl;
		std::cin >> dir;

		player1.Move(dir);

		std::cout << "\nYour new row is: " << player1.PosY()+1;
		std::cout << "\nYour new column is: " << player1.PosX()+1;

	}

	getchar();

	return(0);
}