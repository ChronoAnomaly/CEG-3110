/*
 * Brett Worley
 * CEG-3110-01
 */
#include "password_checker.h"

/*
 * Main function for processing a password entered by the user. It runs
 * through all the requirements checks for a valid password and will
 * output if the password is valid or invalid.
 */
void password_checker(const char* pass)
{
	int valid_password = FALSE;
	int len = strlen(pass);
	int i = 0;

	/* If the password entered is not long enough or too long, then we will
	not bother to check if it's valid. */
	if(len < 9 || len > 50) {
		printf("Invalid password length.\n");
		exit(EXIT_FAILURE);
	}

	/* Check that all the requirements are met for the currently entered
	password */
	if(check_upper(pass) && check_lower(pass) && check_digit(pass)
		&& check_special(pass) && check_no_space(pass)) {
		valid_password = TRUE;
		save_passwords(pass);
	}

	if(valid_password) {
		printf("Valid password.\n");
	} else {
		printf("Invalid password.\n");
	}
}

/*
 * Checks the given string for upper case characters.
 * If two or more are found, then it returns true; else it returns false.
 */
int check_upper(const char* str)
{
	int count = 0;

	while(*str) {

		if(isupper(*str++)) {
			count++;
		}
	}

	if(count >= 2) {
		return TRUE;
	} else {
		printf("Not enough upper case letters.\n");
		return FALSE;
	}
}

/*
 * Checks the given string for lower case characters.
 * If two or more are found, then it returns true; else it returns false.
 */
int check_lower(const char* str)
{
	int count = 0;

	while(*str) {

		if(islower(*str++)) {
			count++;
		}
	}

	if(count >= 2) {
		return TRUE;
	} else {
		printf("Not enough lower case letters.\n");
		return FALSE;
	}
}

/* TODO: Fix reading the input. The \n character is being place in the
 * char array, thus causing this function to fail.
 */

/*
 * Checks the given string for any whitespace characters.
 * If one is found, it returns false; else it returns true.
 */
int check_no_space(const char* str)
{
	while(*str) {

		if(isspace(*str++)) {
			printf("Space character found.\n");
			return FALSE;
		}
	}
	return TRUE;
}

/*
 * Checks the given string for numeric digits.
 * If more than two are found, then it will return true; else it returns false.
 */
int check_digit(const char* str)
{
	int count = 0;

	while(*str) {

		if(isdigit(*str++)) {
			count++;
		}
	}

	if(count >= 2) {
		return TRUE;
	} else {
		printf("Not enough digits.\n");
		return FALSE;
	}
}

/*
 * Checks the given string against the allowed special characters.
 * If two or more are found, then it returns true; else it returns false.
 */
int check_special(const char* str)
{
	int i, len, count = 0;
	char special[] = { '!', '@', '#', '$', '%', '&', '*', ')', '(', ']', '[',
			'}', '{', '>', '<', ';', ':', '.', ',', '/', '|',
			'\\' , '~', '?', '_', '-', '+', '='};
	len = sizeof(special) / sizeof(char);

	while(*str) {
		
		for(i = 0; i < len; i++) {
			if(*str == special[i]) {
				count++;
			}
		}

		str++;
	}

	if(count >= 2) {
		return TRUE;
	} else {
		printf("Not enough special characters.\n");
		return FALSE;
	}
}

void save_passwords(const char* str)
{
	FILE* fp;

	fp = fopen("pass_storage.txt", "w+");
	
	fprintf(fp, "Testing...\n");

	fclose(fp);
}
