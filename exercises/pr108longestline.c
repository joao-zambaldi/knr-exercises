/*
 * Pogram 1-08. Prints the longest from its input.
 */

#include <stdio.h>
#define MAXLINE 1000

int _getline(char line[], int maxline);
void _copy(char from[], char to[]);

int main(int argc, char** argv)
{
	int len;
	int max;
	char line[MAXLINE];
	char longestline[MAXLINE];

	max = len = 0;
	while ((len = _getline(line, MAXLINE)) > 0)
		if (len > max) {
			max = len;
			_copy(line, longestline);
		}

	if (max > 0)
		printf("%s", longestline);

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

void _copy(char from[], char to[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}

