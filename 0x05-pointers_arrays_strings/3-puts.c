#include "main.h"

/**
 * _puts - print a string to the stdout
 * @str: the string
 * Return: the length of the string
 */

void _puts(char *str)
{
	int a = 0;

	while (str[a] != '\0')
	{
		_putchar(str[a]);
		a++;
	}
	_putchar('\n');
}
