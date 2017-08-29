#include <stdio.h>
#include "Arena.h"

//Arena Constructor
Arena::Arena()
{
	//Creates a 10x10 Arena
	int ArenaArray[10][10] = { 0 };
	
	//Initializes an Empty Arena. A tile in the arena is considered empty if its value is '-1'
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			ArenaArray[i][j] = -1;
	
	printf("\nAn Empty Arena has been Initalised!");
	printf("\n\n**********************************************\n");
}