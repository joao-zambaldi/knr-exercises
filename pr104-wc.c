/*
 * The program counts input characters.
 */

#include <stdio.h>

int main(int argc, char** argv)
{
	int nc;

	for (nc = 0; getchar() != EOF; ++nc)
		;

	printf("%d\n", nc);

	return 0;
}

