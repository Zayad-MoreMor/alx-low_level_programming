#include "main.h"

/**
 * leet - encode into 1337speak
 * @n: input value
 * Return: n value
 */

char *leet(char *n)
{
	int i, l;
	char s1[] = "aAeo0tT1L";
	char s2[] = "4433007711";

	for (i = 0; n[i] != '\0'; i++)
	{
		for (l = 0; k < 10; k++)
		{
			if (n[i] == s1[k])
			{
				n[i] = s2[k];
			}
		}
	}
	return (n);
}
