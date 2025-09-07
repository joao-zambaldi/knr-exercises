/*
 * Exercise 1-18. Write a program to remove trailling blanks and tabs
 * from each line of input, and to delete entirely blank lines.
 */

#include <stdio.h>
#define MAXLINE 1000

int get_trimmed_line(char line[], int lim);

int main(int argc, char** argv)
{
	int len;
	char line[MAXLINE];

	while ((len = get_trimmed_line(line, MAXLINE)) > 0)
		if (len > 1)
			printf("%s", line);

	return 0;
}

int get_trimmed_line(char line[], int lim)
{
	int i, c;

	/* ignore white space */
	while ((c = getchar()) == ' ' || c == '\t')
		;

	if (c == EOF) {
		line[0] = '\0';
		return 0;
	}

	ungetc(c, stdin);

	/* copy line */	
	i = 0;
	while ((c = getchar()) != EOF && c != '\n')
		line[i++] = c;


	/* remove white space at the end, if any */
	if (i > 0 && line[i] == ' ' || line[i] == '\t')
		--i;

	line[i] = '\n';
	line[i + 1] = '\0';

	return i + 1;
}

