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

int password_checker(const char* new_pass, const char* cur_pass,
		const char* pre_pass);
int check_upper(const char* str);
int check_lower(const char* str);
int check_digit(const char* str);
int check_no_space(const char* str);
int check_special(const char* str);
int check_similar(const char* new_pass, const char* cur_pass,
		const char* pre_pass);
int chk_forward(const char* new_pass, int newlen, int new_index,
                const char* old_pass, int oldlen, int old_index);
int chk_bforward(const char* new_pass, int newlen, int new_index,
                const char* old_pass, int oldlen, int old_index);
int chk_fbackward(const char* new_pass, int newlen, int new_index,
                const char* old_pass, int oldlen, int old_index);
int chk_backward(const char* new_pass, int newlen, int new_index,
                const char* old_pass, int oldlen, int old_index);
int found_match_char(const char* new_pass, int newlen, int new_index,
                const char* old_pass, int oldlen, int old_index);
int lettercmp(const char* new_pass, int new_index, const char* old_pass,
		int old_index);
int othercmp(const char* new_pass, int new_index, const char* old_pass,
		int old_index);
#endif
