/*
 * Brett Worley
 * CEG-3110-01
 */
#include <stdio.h>
#include <stdlib.h>
#include "password_checker.h"

#define BUFFER 48

void proccess_file(char* argv[], char* new_pass, char* cur_pass, char* pre_pass);
void process_manual();

int main(int argc, char* argv[])
{
	char new_pass[BUFFER] = {'\0'};
	char cur_pass[BUFFER] = {'\0'};
	char pre_pass[BUFFER] = {'\0'};

	if (argc < 2 ) {

	} else if (argc == 2) {
		proccess_file(argv, new_pass, cur_pass, pre_pass);
	}

	return EXIT_SUCCESS;
}


void proccess_file(char* argv[], char* new_pass, char* cur_pass, char* pre_pass)
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

void process_manual()
{

}

