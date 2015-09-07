/*
 * Brett Worley
 * CEG-3110-01
 */
#include <stdio.h>
#include "dice.h"

int main(int argc, char* argv[])
{

	int num;

	printf("Enter the number of dice to roll: ");

	scanf("%d", &num);

	dice(num);

	return EXIT_SUCCESS;
}
