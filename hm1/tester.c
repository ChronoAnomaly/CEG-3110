/*
 * Brett Worley
 * CEG-3110-01
 */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "password_checker.h"

#define BUFFER 100

int main()
{
	char pass[BUFFER] = {'\0'};
	size_t len = 0;

	printf("Enter your password: ");
	if(fgets(pass, sizeof(pass), stdin) != NULL) {
		
		len = strlen(pass);

		if(len > 0 && pass[len-1] == '\n') {
			pass[--len] = '\0';
		}
	} else {
		fprintf(stderr, "Error reading input.\n");
		exit(EXIT_FAILURE);
	}

	password_checker(pass);

	return EXIT_SUCCESS;
}
