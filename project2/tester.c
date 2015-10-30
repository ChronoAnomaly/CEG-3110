/*
 * Brett Worley
 * CEG-3110-01
 */
#include <stdio.h>
#include <stdlib.h>
#include "password_checker.h"

#define BUFFER 128

void process_file(char* argv[], char* new_pass, char* cur_pass, char* pre_pass);
void process_manual(char* new_pass, char* cur_pass, char* pre_pass);
void read_line(FILE* fp, char* line);

int main(int argc, char* argv[])
{
	char new_pass[BUFFER] = {'\0'};
	char cur_pass[BUFFER] = {'\0'};
	char pre_pass[BUFFER] = {'\0'};

	if(argc < 2 ) {
		process_manual(new_pass, cur_pass, pre_pass);
	} else if(argc == 2) {
		process_file(argv, new_pass, cur_pass, pre_pass);
	}

	return EXIT_SUCCESS;
}

/*
 * Remove the newline ('\n') character from the end of
 * the string read in from the buffer
*/
void rm_newline(char* buff)
{
	size_t len = 0;

	len = strlen(buff);

	if(len > 0 && buff[len-1] == '\n') {
		buff[--len] = '\0';
	}
}

/*
 * Processes a file if the program is passed command line arguments.
 *
 * Format for the file: 
 * 			new password
 *			current password
 *			previous password
 *			A or R ( for accepted or rejected) and comment section
 * NOTE: the comment section is read in but just discarded, as it is only
 * used for the user to help keep track of what the test case is for/used
 * to test against.
 *
 * This function will scan through the file for each test case and continue
 * to read in the test cases until it reaches the end of the file.
*/
void process_file(char* argv[], char* new_pass, char* cur_pass, char* pre_pass)
{
	char expected_result = NULL;
	int test_case, result;
	char discard[BUFFER];
	FILE* fp;

	test_case = result = 0;

	fp = fopen(argv[1], "r");

	if(fp == NULL) {
		fprintf(stderr, "ERROR: Can't open this file.\n");
		exit(EXIT_FAILURE);
	}

	while(fgets(new_pass, BUFFER, fp)) {
		fgets(cur_pass, BUFFER, fp);
		fgets(pre_pass, BUFFER, fp);

		/* remove '\n' from each string */
		rm_newline(new_pass);
		rm_newline(cur_pass);
		rm_newline(pre_pass);

		/*fscanf(fp, "%s", expected_result);*/
		expected_result = fgetc(fp);
		fgets(discard, BUFFER, fp);
		/*fgetc(fp);*/ /* clear the \n char from the buffer */
		test_case++;

		/* begin checking the passwords */
		result = password_checker(new_pass, cur_pass, pre_pass);
		
		/* compare expected result with the actual result */
		if(expected_result == 'a' || expected_result == 'A') {
			
			if(result) {
				printf("Test case #%d passed.\n", test_case);
			} else {
				printf("Test case #%d failed.\n",test_case);
			}

		} else if(expected_result == 'r' || expected_result == 'R') {

			if(result) {
				printf("Test case #%d failed.\n", test_case);
			} else {
				printf("Test case #%d passed.\n",test_case);
			}
		}
	}
}

/*
 * Processes manual input from the users if no command line args
 * are passed while running.
*/
void process_manual(char* new_pass, char* cur_pass, char* pre_pass)
{
	char line[BUFFER];
	size_t len = 0;

	printf("Entering manual mode. (Enter exit to stop)\n");

	printf("Enter your new password: \n");
	fgets(line, BUFFER, stdin);

	/* loop through manual mode until the user wants to exit */
	while(strcmp(line, "exit")) {
		
		rm_newline(line);
		strcpy(new_pass, line);

		printf("Enter your current password: \n");
		fgets(line, BUFFER, stdin);
		rm_newline(line);
		strcpy(cur_pass, line);

		printf("Enter your previous password: \n");
		fgets(line, BUFFER, stdin);
		rm_newline(line);
		strcpy(pre_pass, line);

		if(password_checker(new_pass, cur_pass, pre_pass)) {
			printf("Accepted.\n");
		}
	
		/* Begins reading password loop again */
		printf("Enter your new password: \n");
		fgets(line, BUFFER, stdin);
	}
}

