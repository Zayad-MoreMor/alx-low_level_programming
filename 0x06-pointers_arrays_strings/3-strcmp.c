#include "main.h"
/**
 * _strcmp - compare string values
 * @s1: input value
 * @s2: input value
 * Return: s1[c] = s2[c]
 */

int _strcmp(char *s1, char *s2)
{
	while (((*s1 != '\0') && (*s2 != '\0')) && (*s1 == *s2))
	{
		s1++;
		s2++;
	}

	if (*s1 == *s2)
	{
		return (0);
	}

	else
	{
		return (*s1 - *s2);
	}
}
