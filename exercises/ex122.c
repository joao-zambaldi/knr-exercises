/*
 * Exercise 1-22. Write a program to "fold" long lines into two or more
 * lines after the last non-blank character that occurs before the n-th
 * column of input. Make sure your program does something inteligent 
 * with very long lines, and if there are no blanks or tabs before 
 * the specific columns.
 */

#include <stdio.h>
#include <stdlib.h>

#define TABSIZE 8
#define WIDTH 50

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

	if (cursor % WIDTH == 0) {
		putchar('\n');
		printf("------> ");
		cursor = 9;
	}
		

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

