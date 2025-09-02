/*
 * Exercise 1-8. Write a program that count blanks, tabs, and new lines.
 */

#include <stdio.h>

int main(int argc, char** argv)
{
	int bn, tn, ln, c;

	bn = tn = ln = 0;
	while ((c = getchar()) != EOF) {
		bn += c == ' ';
		tn += c == '\t';
		ln += c == '\n';
	}

	printf("Blanks: %d\n", bn);
	printf("Tabs: %d\n", tn);
	printf("Lines: %d\n", ln);

	return 0;
}

