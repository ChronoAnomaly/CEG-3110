/*
 * Brett Worley
 * CEG-3110-01
 */
#include "dice.h"

/*
 * Rolls a set amount of dice, given by the the parameter num. The dice are 6
 * sided. The function will print the roll results of each dice to the
 * screen.
 */
void dice(int num)
{

	int i, roll;

	srand(time(NULL));

	for(i = 0; i < num; i++) {
		roll = (rand()%6)+1;
		printf("%d ", roll);
	}
	printf("is the result of the roll.\n");
}
