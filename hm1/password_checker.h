/*
 * Brett Worley
 * CEG-3110-01
 */
#ifndef __PASSWORD__
#define __PASSWORD__

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
/* Max length of the buffer used for the password. Longer than the 24
character limit so we can check if the user is entering a password that
is too long for the system. */
#define BUFFER 35

void password_checker();
int check_upper(const char* str);
int check_lower(const char* str);
int check_digit(const char* str);
int check_no_space(const char* str);
int check_special(const char* str);

#endif
