/*
 * Brett Worley
 * CEG-3110-01
 */
#include <stdio.h>
#include <stdlib.h>
#include "password_checker.h"

#define BUFFER 48

void process_file(char* argv[], char* new_pass, char* cur_pass, char* pre_pass);
void process_manual(char* new_pass, char* cur_pass, char* pre_pass);

int main(int argc, char* argv[])
{
	char new_pass[BUFFER] = {'\0'};
	char cur_pass[BUFFER] = {'\0'};
	char pre_pass[BUFFER] = {'\0'};

	if (argc < 2 ) {
		process_manual(new_pass, cur_pass, pre_pass);
	} else if (argc == 2) {
		process_file(argv, new_pass, cur_pass, pre_pass);
	}

	return EXIT_SUCCESS;
}

/*
 * Processes a file if the program is passed command line arguments.
 *
 * Format for the file: 
 * 			new password
 *			current password
 *			previous password
 *			A or R ( for accepted or rejected)
 *
 * This function will scan through the file for each test case and continue
 * to read in the test cases until it reaches the end of the file.
*/
void process_file(char* argv[], char* new_pass, char* cur_pass, char* pre_pass)
{
	char expected_result = NULL;
	FILE* fp;

	fp = fopen(argv[1], "r");

	if (fp == NULL) {
		fprintf(stderr, "ERROR: Can't open this file.\n");
		exit(EXIT_FAILURE);
	}

	while(fscanf(fp, "%s", new_pass) != EOF) {
		fscanf(fp, "%s", cur_pass);
		fscanf(fp, "%s", pre_pass);
		/*fscanf(fp, "%s", expected_result);*/
		fgetc(fp); /* clear the \n char from the buffer */
		expected_result = fgetc(fp);


	}
}

/*
 * Processes manual imput from the users if no command line args
 * are passed while running.
*/
void process_manual(char* new_pass, char* cur_pass, char* pre_pass)
{
	size_t len = 0;


	printf("Enter your new password: ");
	if(fgets(new_pass, BUFFER, stdin) != NULL) {
		len = strlen(new_pass);

		if(len > 0 && new_pass[len-1] == '\n') {
			new_pass[--len] = '\0';
		}
	} else {
		fprintf(stderr, "Error reading input.\n");
	}
}

