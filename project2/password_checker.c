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
int password_checker(const char* new_pass, const char* cur_pass, const char* pre_pass)
{
	int valid_password = FALSE;
	int len = strlen(new_pass);

	/* If the password entered is not long enough or too long, then we will
	not bother to check if it's valid. */
	if(len < 9 || len > 50) {
		printf("Rejected: Invalied password length.\n");
		return valid_password;
	}

	/* Check that all the requirements are met for the currently entered
	password */
	if(check_upper(new_pass) && check_lower(new_pass) && check_digit(new_pass)
		&& check_special(new_pass) && check_no_space(new_pass)) {
		valid_password = TRUE;
	}

	if(valid_password) {
		return valid_password;
	} else {
		return valid_password;
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
		printf("Rejected: Not enough Upper case.\n");
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
		printf("Rejected: Not enough Lower case.\n");
		return FALSE;
	}
}

/*
 * Checks the given string for any whitespace characters.
 * If one is found, it returns false; else it returns true.
 */
int check_no_space(const char* str)
{
	while(*str) {

		if(isspace(*str++)) {
			printf("Rejected: Space found.\n");
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
		printf("Rejected: Not enough numbers.\n");
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
		printf("Rejected: Not enough special characters.\n");
		return FALSE;
	}
}

