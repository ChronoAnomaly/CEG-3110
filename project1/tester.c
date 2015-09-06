
#include <stdio.h>
#include "dice.h"

int main()
{

	int num;

	printf("Enter the number of dice to roll: ");
	scanf("%d", &num);

	dice(num);
}
