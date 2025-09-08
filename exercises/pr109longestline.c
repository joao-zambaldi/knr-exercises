/*
 * Program 1-09. Prints the longest line from its input.
 *
 * This is a another way to write the Program 1-08 using external 
 * variables, and an inferior one See Section 1-10.
 */

#include <stdio.h>

#define MAXLINE 1000

int max;
char line[MAXLINE];
char longest[MAXLINE];

int _getline(void);
void _copy(void);

int main(int argc, char** argv)
{
	int len;
	extern int max;
	extern char longest[];

	max = 0;
	while ((len = _getline()) > 0)
		if (len > max) {
			max = len;
			_copy();
		}

	if (max > 0)
		printf("%s", longest);

	return 0;
}

int _getline(void)
{
	int c, i;
	extern char line[];

	for (i = 0; i < MAXLINE - 1 
		&& (c = getchar()) != EOF && c != '\n'; ++i)
			line[i] = c;

	if (c == '\n')
		line[i++] = c;

	line[i] = '\0';

	return i;
}

void _copy(void)
{
	int i;
	extern char line[], longest[];

	i = 0;
	while ((longest[i] = line[i]) != '\0')
		++i;
}

