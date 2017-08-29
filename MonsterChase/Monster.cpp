#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>
#include <fstream>
#include <string>

#include "Monster.h"

//Monster Constructor
Monster::Monster()
{
	srand(time(NULL));
	
	int numMonsters = 0;
	int MonsterposX[100] = { 0 };
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			MonsterposX[i] = -1;
	int MonsterposY[100] = { 0 };
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			MonsterposY[i] = -1;

	printf("\n\nHow brave do you feel, warrior? How many monsters do you dare face? ");
	scanf("%d", &numMonsters);

	for (int i = 0; i < numMonsters; i++)
		MonsterposX[i] = rand() % 10 + 1;

	for (int i = 0; i < numMonsters; i++)
		MonsterposY[i] = rand() % 10 + 1;

	//for (int i = 0; i < numMonsters; i++)
		//printf("\nEnter the name of Monster %d", i + 1);
		//MonsterposY[i] = rand() % 10 + 1;
	std::string nameArray[100];
	
	std::ifstream monsterNames;
	monsterNames.open("monsterNames.dat");

	int index = 0;

	while (index < 100)
	{
		getline(monsterNames, nameArray[index]);
		index++;
	}

	for (int i = 0; i < 100; i++)
	{
		std::cout << "Here is the name of monster " << i+1 <<": " << nameArray[i] << std::endl;
	}
	
	printf("\n");
	for (int i = 0; i < numMonsters; i++)
		printf(" %d", MonsterposX[i]);

	printf("\n");
	for (int i = 0; i < numMonsters; i++)
		printf(" %d", MonsterposY[i]);

	getchar();
}