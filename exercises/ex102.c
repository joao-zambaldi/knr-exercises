/*
 * Exercise 1-2. Experiment to find out what happens when printf's 
 * argument string contains \c, where c character not listed above.
 */

#include <stdio.h>

int main(int argc, char** argv)
{
	printf("a: \a\n");
	printf("b: \b\n");
	printf("e: \e\n");
	printf("f: \f\n");
	printf("n: \n\n");
	printf("r: \r\n");
	printf("t: \t\n");
	printf("v: \v\n");

	return 0;
}

