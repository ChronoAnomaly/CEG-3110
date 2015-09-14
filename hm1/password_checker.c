#include "password_checker.h"

void password_checker()
{
	char pass[BUFFER];
	int valid_password = FALSE;
	size_t len;

	len = 0;

	printf("Enter your new password: ");
	if(fgets(pass, sizeof(pass), stdin) != NULL) {
		
		len = strlen(pass);

		if(len > 0 && pass[len-1] == '\n') {
			pass[--len] = '\0';
		}
	} else {
		fprintf(stderr, "Error reading input.\n");
		exit(EXIT_FAILURE);
	}
	
	/* If the password entered is not long enough or too long, then we will
	not bother to check if it's valid. */
	if(len < 9 || len > 24) {
		printf("Invalid password length.\n");
		exit(EXIT_FAILURE);
	}

	if(check_upper(pass) && check_lower(pass) && check_digit(pass)
		&& check_special(pass)) {
		valid_password = TRUE;
	}



	if(valid_password) {
		printf("Valid password.\n");
	} else {
		printf("Invalid password.\n");
	}

	printf("Password is: %s\t length is: %ld\n", pass, len);
}

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
		return FALSE;
	}
}

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
		return FALSE;
	}
}

int check_special(const char* str)
{
	int count = 0;
	

	if(count >= 2) {
		return TRUE;
	} else {
		return FALSE;
	}
}
