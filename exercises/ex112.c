/*
 * Exercise 1-12. Write a program that prints its input on word per 
 * line.
 */

#include <stdio.h>

#define IN 1
#define OUT 0

int main(int argc, char** argv)
{
	int state, c;

	state = OUT;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			if (state == IN)
				putchar('\n');
			state = OUT;
		}
		else if (state == OUT)
			state = IN;

		if (state == IN)
			putchar(c);
	}

	return 0;
}

