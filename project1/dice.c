
#include "dice.h"


void dice(int num)
{

	int i, roll;

	srand(time(NULL));

	for(i = 0; i < num; i++) {
		roll = (rand()%6)+1;
		printf("%d ", roll);
	}
}
