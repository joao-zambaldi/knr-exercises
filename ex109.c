/*
 * Exercise 1-9. Write a program to copy its input to its output, 
 * replacing each string of one or more blanks by a single blank.
 */

#include <stdio.h>

int main(int argc, char** argv)
{
	int c, pc_isblank;

	pc_isblank = 0;
	while ((c = getchar()) != EOF) {
		if (c != ' ' || !pc_isblank)
			putchar(c);
		pc_isblank = c == ' ';
	}
	
	return 0;
}

