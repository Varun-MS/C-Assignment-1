#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Monster.h"

//Monster Constructor
Monster::Monster(int numMonsters)
{
	//For Random Number Generation
	srand(time(NULL));
	
	//Monster Traits
	int _numMonsters = numMonsters;
	int MonsterposX[100] = { 0 };
	int MonsterposY[100] = { 0 };
	std::vector<std::string> monsterNames(_numMonsters);

	//Initializes the Monsters Positions. A Position of -1 means they are not on the grid.
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			MonsterposX[i] = -1;
			MonsterposY[i] = -1;
		}
	}

	//Randomly A Monster Position on the Grid
	for (int i = 0; i < _numMonsters; i++)
	{
		MonsterposX[i] = rand() % 10 + 1;
		MonsterposY[i] = rand() % 10 + 1;
	}

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

	for (int i = 0; i < _numMonsters; i++)
	{
		monsterNames[i] = nameArray[rand() % 7775];
	}

	//Inputs the Randomly Selected Monster Names
	for (int i = 0; i < _numMonsters; i++)
	{
		std::cout << "Here is the name of monster " << i+1 <<": " << monsterNames[i] << std::endl;
	}
	
	//Outputs the Positions of All the Monsters
	printf("\n");
	for (int i = 0; i < _numMonsters; i++)
	{
		printf("\nMonster %d is at position %d,%d", i+1,MonsterposX[i],MonsterposY[i]);
	}

	printf("\n\n**********************************************\n");

	getchar();
}