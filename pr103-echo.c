/*
 * A version of the echo program.
 * Copies its input to its output one character at a time.
 *
 * See pag 16, 17.
 */

#include <stdio.h>

int main(int argc, char** argv)
{
	int c;

	while ((c = getchar()) != EOF)
		putchar(c);

	return 0;
}

