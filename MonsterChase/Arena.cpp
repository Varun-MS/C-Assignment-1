#include <stdio.h>
#include "Arena.h"

Arena::Arena()
{
	int ArenaArray[10][10] = { 0 };
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			ArenaArray[i][j] = -1;
	
	printf("\nAn Empty Arena has been Initalised!");
	
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			printf(" %d", ArenaArray[i][j]);
}