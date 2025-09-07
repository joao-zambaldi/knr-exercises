/*
 * Exercise 1-16. Revise the main routine of the longest-line program
 * to correctly print the length of arbitrarily long lines, and as much
 * as possible of the text.
 */

#include <stdio.h>
#define MAXLINE 100

int _getline(char line[], int maxline);
void _copy(char from[], char to[], int lim);

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
			_copy(line, longestline, MAXLINE);
		}

	if (max > 0)
		printf("%s", longestline);

	return 0;
}

int _getline(char line[], int lim)
{
	int c, len;

	len = 0;
	while ((c = getchar()) != EOF) {
		if (len + 1 < lim)
			line[len++] = c;
		if (c == '\n')
			break;
	}	

	line[len >= lim ? lim - 1 : len] = '\0';

	return len;
}

void _copy(char from[], char to[], int lim)
{
	int i;

	i = 0;
	while (i < lim && (to[i] = from[i]) != '\0')
		++i;
}

