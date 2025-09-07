/*
 * Exercise 1-17. Write a program to print all input lines that are
 * longer than 80 characters.
 */

#include <stdio.h>
#define MAXLINE 1000

int _getline(char line[], int maxline);

int main(int argc, char** argv)
{
	int len;
	char line[MAXLINE];

	len = 0;
	while ((len = _getline(line, MAXLINE)) > 0)
		if (len > 80)
			printf("%s", line);

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

