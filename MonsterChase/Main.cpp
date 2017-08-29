#include <stdio.h>

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
	
	Monster monsters(numMonsters);

	//Let the Games Begin!

	getchar();

	return(0);
}