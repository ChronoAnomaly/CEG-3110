#include "password_checker.h"

void password_checker()
{
	char pass[25];
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
	
	if(check_upper(pass)) {
		printf("FIZZ\n");
	} else {
		printf("BUZZ\n");
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

	printf("Count is: %d\n", count);
	if(count >= 2) {
		return TRUE;
	} else {
		return FALSE;
	}
}

int check_lower(const char* str, int len)
{
	int count = 0;

	if(count >= 2) {
		return TRUE;
	} else {
		return FALSE;
	}
}

int check_digit(const char* str,int len)
{
	int count = 0;

	if(count >= 2) {
		return TRUE;
	} else {
		return FALSE;
	}
}

int check_special(const char* str,int len)
{
	int count = 0;

	if(count >= 2) {
		return TRUE;
	} else {
		return FALSE;
	}
}
