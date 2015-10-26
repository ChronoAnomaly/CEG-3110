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

void read_line(FILE* fp, char* line)
{
	const int max_length = 256;
	char* line_buffer = malloc(sizeof(char) * max_length);
	char c;
	int count;

	if(fp == NULL) {
		fprintf(stderr, "Error: file pointer is null.\n");
		exit(EXIT_FAILURE);
	}

	if(line_buffer == NULL) {
		fprintf(stderr, "Error: allocating memory for line buffer.\n");
		exit(EXIT_FAILURE);
	}

	count = 0;
	c = fgetc(fp);
	while((c != '\n') && (c != EOF)) {
		line_buffer[count] = c;
		count++;
		c = fgetc(fp);
	}
	
	line_buffer[count] = '\0';
	strncpy(line, line_buffer, ++count);

}

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
 *			A or R ( for accepted or rejected)
 *
 * This function will scan through the file for each test case and continue
 * to read in the test cases until it reaches the end of the file.
*/
void process_file(char* argv[], char* new_pass, char* cur_pass, char* pre_pass)
{
	char expected_result = NULL;
	int test_case, result;
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
		fgetc(fp); /* clear the \n char from the buffer */
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
