/*
 * Exercise 1-21. Write a program entab that replaces strings of blanks
 * by the minimum numbers of tabs and blanks to acheive the same spacing.
 * Use the same tab stops as for detab. When either a tab or a single 
 * blank would suffice to reach a tab stop, which should be given 
 * preference?
 */

#include <stdio.h>
#include <stdlib.h>

#define TABSIZE 8

int cursor, ws_cursor, tabsize;

void _putchar(int c);	/* an alternative implementation of putchar()
			 * that will move the cursor and the ws_cursor
			 */

int next_tabstop(int cursor); 	/* returns the position of the 
				 * next tabstop 
				 */


int main(int argc, char** argv)
{
	int c;
	extern int cursor, ws_cursor, tabsize;

	cursor = ws_cursor = 1;
	tabsize = argc == 2 ? atol(argv[1]) : TABSIZE;

	while ((c = getchar()) != EOF)
		if (c == ' ')
			++ws_cursor;
		else if (c == '\t')
			ws_cursor = next_tabstop(ws_cursor);
		else {
			while (next_tabstop(cursor) < ws_cursor)
				_putchar('\t');
			while (cursor < ws_cursor)
				_putchar(' ');
			_putchar(c);
		}

	return 0;
}

void _putchar(int c)
{
	extern int cursor, ws_cursor, tabsize;

	if (c == '\n')
		cursor = ws_cursor = 1;
	else if (c == ' ')
		++cursor;
	else if (c == '\t')
		cursor = next_tabstop(cursor);
	else
		ws_cursor = ++cursor;

	putchar(c);	
}

int next_tabstop(int cursor)
{
	extern int tabsize;

	return cursor - (cursor % tabsize) + tabsize + 1;
}

