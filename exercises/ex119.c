/*
 * Exercise 1-19. Write a function reverse(s) that reverses the 
 * character string s. Use it to write a program that reverses
 * its input a line at a time.
 */

#include <stdio.h>
#define MAXLINE 1000

int _getline(char line[], int maxline);
void _reverse(char line[]);

int main(int argc, char** argv)
{
	int len;
	char line[MAXLINE];

	len = 0;
	while ((len = _getline(line, MAXLINE)) > 0) {
		_reverse(line);
		printf("%s", line);
	}

	return 0;
}

int _getline(char line[], int lim)
{
	int c, i;

	i = 0;
	for (; i + 1 < lim && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;	

	if (c == '\n') {
		line[i] = c;
		++i;
	}

	line[i] = '\0';

	return i;
}

void _reverse(char line[])
{
	int len, i, c;

	len = 0;
	while (line[len] != '\0' && line[len] != '\n')
		++len;

	for (i = 0; i < len / 2; ++i) {
		c = line[i];
		line[i] = line[len - i];
		line[len - i] = c;
	}
}

