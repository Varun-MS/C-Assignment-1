#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Player.h"

//Player Constructor
Player::Player()
{
	srand(time(NULL));

	char name[20];
	int position = -1;

	printf("\nEnter your Name, Valiant Warrior: ");
	scanf("%s", name);

	int posX = rand() % 10 + 1;
	int posY = rand() % 10 + 1;

	printf("\nHello %s!", name);
	printf("\nIt looks like you have spawned at Row %d, Column %d. Good luck!", posX, posY);
	printf("\n\n**********************************************\n");
	getchar();
}