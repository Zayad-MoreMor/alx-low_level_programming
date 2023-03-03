#include "main.h"

/**
 * _strncpy - copies a  string
 * @dest: input value
 * @src: input value
 * @n: input value
 * Return: dest
 */

char *_strncpy(char *dest, char *src, int n)
{
	int e;

	e = 0;
	while (e < n && src[e] != '\0')
	{
		dest[e] = src[e];
		e++;
	}
	while (e < n)
	{
		dest[e] = '\0';
		e++;
	}
	return (dest);
}
