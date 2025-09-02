/*
 * Exercise 1-6. Verify that the expression getchar() != EOF is 0 or 1.
 */

#include <stdio.h>

int main(int argc, char** argv)
{
	int c;

	c = 1;
	while (1) {
		c = getchar() != EOF;
		printf("%d", c);

		if (!c)
			break;
	}

	putchar('\n');

	return 0;
}

