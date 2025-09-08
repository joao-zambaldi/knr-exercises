/*
 * Exercise 1-23. Write a program to remove all comments froma C 
 * program. Don't forget to handle quoted strings and characters 
 * constants properly. C comments do not nest.
 *
 * OBS: We'll remove only multi-line comments.
 */

#include <stdio.h>
#include <stdlib.h>

#define OUTSIDE 0
#define IN_STRING 1
#define IN_COMMENT 2

int next_char;
int current_char;
int _getchar(void);

int main(int argc, char** argv)
{
	int state;
	extern int current_char, next_char;

	_getchar();

	state = OUTSIDE;
	while (_getchar() != EOF) {

		if (state == OUTSIDE && current_char == '/' 
			             && next_char == '*') {
			_getchar();
			state = IN_COMMENT;
			continue;
		}

		if (state == OUTSIDE && current_char == '"') {
			state = IN_STRING;
			putchar(current_char);
			continue;
		}

		if (state == IN_STRING && current_char == '"') {
			state = OUTSIDE;
			putchar(current_char);
			continue;
		}

		if (state == IN_COMMENT && current_char == '*'
				        && next_char == '/') {
			_getchar();
			state = OUTSIDE;
			continue;
		}

		if (state != IN_COMMENT)
			putchar(current_char);
	}

	return 0;
}

int _getchar(void)
{
	extern int current_char, next_char;

	current_char = next_char;	
	if (current_char != EOF) 
		next_char = getchar();

	return current_char;
}

