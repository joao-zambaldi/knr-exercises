/*
 * Exercise 1-24. Write a program to check a C program for rudimentary 
 * sysntax errors like unbalanced parenthesis, brackets and braces. 
 * Don't forget about quotes, both single and double, escape sequences,
 * and comments.
*/

#include <stdio.h>
#include <stdlib.h>

int _getchar(void);
int current_char;
int next_char;
int line;

int eat_comment(void);
int eat_string(void);
int eat_char(void);

int main(int argc, char** argv)
{
	_getchar();
	int lparen, rparen, lbrace, rbrace, lbracket, rbracket;

	lparen = rparen = lbrace = rbrace = lbracket = rbracket = 0;
	line = 1;

	while (1) {
		if (eat_char() || eat_string() || eat_comment()) {
			continue;
		}
		switch (current_char)
		{
			case '(': ++lparen; break;
			case ')': ++rparen; break;
			case '[': ++lbrace; break;
			case ']': ++rbrace; break;
			case '{': ++lbracket; break;
			case '}': ++rbracket; break;
			default: break;
		}
		_getchar();
		if (current_char == EOF)
			break;
	}

	if (lparen != rparen)
		printf("Wrong number of parenthesis.\n");	

	if (lbrace != rbrace) 
		printf("Wrong number of braces.\n");	

	if (lbracket != rbracket) 
		printf("Wrong number of brackets.\n");

	return 0;
}

int _getchar(void)
{
	current_char = next_char;
	if (current_char != EOF)
		next_char = getchar();

	if (current_char == '\n')
		++line;

	return current_char;
}

int eat_comment(void)
{
	/* returns false if there is no comment to parse */
	if (current_char != '/' || next_char != '*')
		return 0;

	_getchar();	/* now, current char is * */
	_getchar();	/* now, previous char is * */

	while (current_char != EOF)
		if (current_char == '*' && next_char == '/') {
			_getchar();
			_getchar();
			return 1;
		} else
			_getchar();

	printf("ERROR: unclosed comment.\n");
	return 1;
}

int eat_string(void)
{
	/* returns false if there is not string to eat */
	if (current_char != '\"')
		return 0;

	_getchar();
	while (current_char != EOF && current_char != '\n')
		if (current_char == '\\' && next_char == '"') {
			_getchar();
			_getchar();
		} else if (current_char == '"') {
			_getchar();
			return 1;
		}

	printf("ERROR: unclosed string literal at line %d.\n", line);
	printf("\tExpected \" and got %d\n", current_char);

	return 1;
}

int eat_char(void)
{
	if (current_char != '\'')
		return 0;

	_getchar();

	if (current_char != '\\' && next_char == '\'') {
		_getchar();
		_getchar();
		return 1;
	}

	if (current_char != '\\' && next_char != '\'') {
		printf("ER1: Mal-formed character literal on line %d.\n", line);
		_getchar();
		_getchar();
		return 1;
	}

	/* now, the current char is '\' */
	_getchar();	
	if (next_char != '\'')
		return 1;

	printf("ER2: Mal-formed character literal on line %d.\n", line);
	return 1;
}

