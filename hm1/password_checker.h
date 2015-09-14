#ifndef __PASSWORD__
#define __PASSWORD__

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

void password_checker();
int check_upper(const char* str);
int check_lower(const char* str, int len);
int check_digit(const char* str, int len);
int check_special(const char* str, int len);

#endif
