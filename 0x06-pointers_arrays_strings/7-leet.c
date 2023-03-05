#include "main.h"

/**
 * leet - encode into 1337speak
 * @n: input value
 * Return: n value
 */

char *leet(char *n)
{
	int i, h;
	char s1[] = "aAeEoOtTlL";
	char s2[] = "4433007711";

	for (i = 0; n[i] != '\0'; i++)
	{
		for (h = 0; h < 10; h++)
		{
			if (n[i] == s1[h])
			{
				n[i] = s2[h];
			}
		}
	}
	return (n);
}
