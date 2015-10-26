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
		printf("Rejected: Invalid password length.\n");
		return valid_password;
	}

	/* Check that all the requirements are met for the currently entered
	password */
	if(check_upper(new_pass) && check_lower(new_pass) && check_digit(new_pass)
		&& check_special(new_pass) && check_no_space(new_pass)
		&& !check_similar(new_pass, cur_pass, pre_pass)) {
		valid_password = TRUE;
	}

	return valid_password;
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

/*
 * Begins checking the passwords to see if they contain a 5 character
 * substring. If a matching character is found, then it calls the other
 * checking functions.
*/
int check_similar(const char* new_pass, const char* cur_pass,
		const char* pre_pass)
{
	int similar = FALSE;
	int count, i, j;
	size_t newlen, curlen, prelen;
	
	newlen = strlen(new_pass);
	curlen = strlen(cur_pass);
	prelen = strlen(pre_pass);

	for(i = 0; i < newlen; i++) {
	
		for(j = 0; j < curlen; j++) {

			/* detect a matching letter */
			if((isalpha(new_pass[i])) && (isalpha(cur_pass[j]))) {
				if(lettercmp(new_pass, i, cur_pass, j)) {
					similar = found_match_char(new_pass,
						newlen, i, cur_pass, curlen, j);
				}
			} else {
				/* detect a matching non-letter*/
				if(!strncmp(&new_pass[i],
				&cur_pass[j], sizeof(char))) {
					similar = found_match_char(new_pass,
						newlen, i, cur_pass, curlen, j);
				}
			}
			if(similar) {
				printf("Rejected: passwords too similar.\n");
				return TRUE;
			}
		}

		for(j = 0; j < prelen; j++) {
		
			/* detect a matching letter */
			if((isalpha(new_pass[i])) && (isalpha(pre_pass[j]))) {
				if(lettercmp(new_pass, i, pre_pass, j)) {
					similar = found_match_char(new_pass,
						newlen, i, pre_pass, prelen, j);
				}
			} else {
				/* detect a matching non-letter*/
				if(!strncmp(&new_pass[i],
				&pre_pass[j], sizeof(char))) {
					similar = found_match_char(new_pass,
						newlen, i, pre_pass, prelen, j);
				}
			}
			if(similar) {
				printf("Rejected: passwords too similar.\n");
				return TRUE;
			}
		}
	}

	return FALSE;
}

/*
 *
*/
int found_match_char(const char* new_pass, int newlen, int new_index,
		const char* old_pass, int oldlen, int old_index)
{
	if(chk_forward(new_pass, newlen, new_index, old_pass,
	oldlen, old_index) || chk_backward(new_pass, newlen, new_index,
	old_pass, oldlen, old_index) || chk_bforward(new_pass, newlen,
	new_index, old_pass, oldlen, old_index) || chk_fbackward(new_pass,
	newlen, new_index, old_pass, oldlen, old_index)) {
		
		return TRUE;
	} else {
		return FALSE;
	}
}

/*
 *
*/
int chk_forward(const char* new_pass, int newlen, int new_index,
		const char* old_pass, int oldlen, int old_index)
{
	int i;
	int same = FALSE;
	int count = 1;
	const int substrlen = 5;
	new_index++; old_index++;

	for(i = 1; i < substrlen; i++) {

		if((isalpha(new_pass[new_index])) &&
		(isalpha(old_pass[old_index]))) {
			if(lettercmp(new_pass, new_index, old_pass,
			old_index)) {
				count++;
			} else {
				count = 1;
			}
		} else {

			if(!strncmp(&new_pass[new_index],
			&old_pass[old_index], sizeof(char))) {
				count++;
			} else {
				count = 1;
			}
		}
		old_index = (old_index + 1) % oldlen;
		new_index = (new_index + 1) % newlen;
	}

	if(count >= 5) {
		same = TRUE;
	}
	
	return same;
}

int chk_backward(const char* new_pass, int newlen, int new_index,
		const char* old_pass, int oldlen, int old_index)
{
	int i;
	int same = FALSE;
	int count = 1;
	const int substrlen = 5;
	new_index--; old_index--;

	for(i = 1; i < substrlen; i++) {

		if((isalpha(new_pass[new_index])) &&
		(isalpha(old_pass[old_index]))) {
			if(lettercmp(new_pass, new_index, old_pass,
			old_index)) {
				count++;
			} else {
				count = 1;
			}
		} else {

			if(!strncmp(&new_pass[new_index],
			&old_pass[old_index], sizeof(char))) {
				count++;
			} else {
				count = 1;
			}
		}
		old_index = (old_index - 1) % oldlen;
		new_index = (new_index - 1) % newlen;

		if(old_index < 0) {
			old_index = oldlen - 1;
		}
		if(new_index < 0) {
			new_index = newlen - 1;
		}
	}

	if(count >= 5) {
		same = TRUE;
	}
	
	return same;

}

int chk_bforward(const char* new_pass, int newlen, int new_index,
		const char* old_pass, int oldlen, int old_index)
{
	int i;
	int same = FALSE;
	int count = 1;
	const int substrlen = 5;
	new_index++; old_index--;

	for(i = 1; i < substrlen; i++) {

		if((isalpha(new_pass[new_index])) &&
		(isalpha(old_pass[old_index]))) {
			if(lettercmp(new_pass, new_index, old_pass,
			old_index)) {
				count++;
			} else {
				count = 1;
			}
		} else {

			if(!strncmp(&new_pass[new_index],
			&old_pass[old_index], sizeof(char))) {
				count++;
			} else {
				count = 1;
			}
		}
		old_index = (old_index - 1) % oldlen;
		new_index = (new_index + 1) % newlen;

		if(old_index < 0) {
			old_index = oldlen -1;
		}
	}

	if(count >= 5) {
		same = TRUE;
	}
	
	return same;
}

int chk_fbackward(const char* new_pass, int newlen, int new_index,
		const char* old_pass, int oldlen, int old_index)
{
	int i;
	int same = FALSE;
	int count = 1;
	const int substrlen = 5;
	new_index--; old_index++;

	for(i = 1; i < substrlen; i++) {

		if((isalpha(new_pass[new_index])) &&
		(isalpha(old_pass[old_index]))) {
			if(lettercmp(new_pass, new_index, old_pass,
			old_index)) {
				count++;
			} else {
				count = 1;
			}
		} else {

			if(!strncmp(&new_pass[new_index],
			&old_pass[old_index], sizeof(char))) {
				count++;
			} else {
				count = 1;
			}
		}
		old_index = (old_index + 1) % oldlen;
		new_index = (new_index - 1) % newlen;

		if(new_index < 0) {
			new_index = newlen - 1;
		}
	}

	if(count >= 5) {
		same = TRUE;
	}
	
	return same;
}

/*
 * Function used to compare letter to see if they are the same.
 * It will pull one character each from both of the strings and convert
 * them into lower case, and then see if they are the same letter.
 * returns: true if they are the same, false if not
*/
int lettercmp(const char* new_pass, int new_index, const char* old_pass,
		int old_index)
{
	char a, b;

	a = tolower(new_pass[new_index]);
	b = tolower(old_pass[old_index]);

	if( a == b) {
		return TRUE;
	} else {
		return FALSE;
	}
}
