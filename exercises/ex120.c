/*
 * Exercise 1-20. Write a program entab that replace strings of blanks
 * by the proper number of blanks to spaces to the next tab stop. 
 * Assume a fixed a fixed set of tab stops, say n columns. Should n be a
 * variable or a symbolic parameter?
 */

#include <stdio.h>
#include <stdlib.h>

#define TABSIZE 8

int cursor;
int tabsize;

void _putchar(int c); 		/* alternative implementation of putchar
				 * that updates the cursor
				 */

int is_tabstop();		/* returns
				 * 	1 if the cursor is at an tabstop
				 * 	0 if not
				 */

int main(int argc, char** argv)
{
	int c;
	extern int cursor, tabsize;

	cursor = 1;
	tabsize = argc == 2 ? atol(argv[1]) : TABSIZE;

	while ((c = getchar()) != EOF)
		if (c == '\t')
			do { _putchar(' '); } while (!is_tabstop());
		else
			_putchar(c);
		

	return 0;
}

void _putchar(int c)
{
	extern int cursor;
	
	putchar(c);
	if (c == '\n')
		cursor = 1;
	else
		++cursor;
}

int is_tabstop()
{
	extern int cursor, tabsize;

	return cursor % tabsize == 1;
}

