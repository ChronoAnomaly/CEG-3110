/*
 * Brett Worley
 * CEG-3110-01
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "dice.h"

/*
 * Testing function for the dice rolling program.
 * The user is asked to input how many dice to roll, then the program
 * will return the values of the dices rolls on a new line.
 */
int main(int argc, char* argv[])
{

	int num = 0;
	char c;

	printf("Enter the number of dice to roll: ");
	
	/* input validation: check through each character, pulling each number
	until we reach an invalid character. */
	while( (c = fgetc(stdin)) != EOF && isdigit(c)) {
		num *= 10;
		num += atoi(&c);
	}

	dice(num);

	return EXIT_SUCCESS;
}
