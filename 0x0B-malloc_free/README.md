##C - malloc, free
		

		
####TASKS
		

		
####[0. Float like a butterfly, sting like a bee](0-create_array.c)
		

		
- Write a function that creates an array of chars, and initializes it with a specific char.
		

		
- Prototype: char *create_array(unsigned int size, char c);
		
- Returns NULL if size = 0
		
- Returns a pointer to the array, or NULL if it fails
		

		
####[1. The woman who has no imagination has no wings](1-strdup.c)
		

		
- Write a function that returns a pointer to a newly allocated space in memory, which contains a copy of the string given as a parameter.
		

		
- Prototype: char *_strdup(char *str);
		
- The _strdup() function returns a pointer to a new string which is a duplicate of the string str. Memory for the new string is obtained with malloc, and can be freed with free.
		
- Returns NULL if str = NULL
		
- On success, the _strdup function returns a pointer to the duplicated string. It returns NULL if insufficient memory was available
		

		
#### [2. He who is not courageous enough to take risks will accomplish nothing in life](2-str_concat.c)
		

		
- Write a function that concatenates two strings.
		

		
- Prototype: char str_concat(char s1, char s2);
		
- The returned pointer should point to a newly allocated space in memory which contains the contents of s1, followed by the contents of s2, and null terminated
		
if NULL is passed, treat it as an empty string
		
- The function should return NULL on failure
		

		
####[3. If you even dream of beating me you'd better wake up and apologize](3-alloc_grid.c)
		

		
- Write a function that returns a pointer to a 2 dimensional array of integers.
		

		
- Prototype: int **alloc_grid(int width, int height);
		
- Each element of the grid should be initialized to 0
		
- The function should return NULL on failure
		
- If width or height is 0 or negative, return NULL
		

		
####[4. It's not bragging if you can back it up](4-free_grid.c)
		

		
Write a function that frees a 2 dimensional grid previously created by your alloc_grid function.
		

		
Prototype: void free_grid(int **grid, int height);
		
Note that we will compile with your alloc-grid.c file. Make sure it compiles.
		

		
####[5. It isn't the mountains ahead to climb that wear you out; it's the pebble in your shoe](100-argstostr.c)
		

		
- Write a function that concatenates all the arguments of your program.
		

		
- Prototype: char *argstostr(int ac, char **av);
		
- Returns NULL if ac == 0 or av == NULL
		
- Returns a pointer to a new string, or NULL if it fails
		
- Each argument should be followed by a \n in the new string  
		

		
####[6. I will show you how great I am] (101-strtow.c)
		

		
- Write a function that splits a string into words.
		

		
- Prototype: char **strtow(char *str);
		
- The function returns a pointer to an array of strings (words)
		
- Each element of this array should contain a single word, null-terminated
		
- The last element of the returned array should be NULL
		
- Words are separated by spaces
		
- Returns NULL if str == NULL or str == ""
		
- If your function fails, it should return NULL


## _putchar


#include "main.h"
		
#include <unistd.h>
		
/**
		
 * _putchar - writes the character c to stdout
		
 * @c: The character to print
		
 *
		
 * Return: On success 1.
		
 * On error, -1 is returned, and errno is set appropriately.
		
 */
		
int _putchar(char c)
		
{
		
	return (write(1, &c, 1));
		
}


## main.h


#ifndef MAIN_H
		
#define MAIN_H
		

		
char *create_array(unsigned int size, char c);
		
int _putchar(char c);
		
char *_strdup(char *str);
		
char *str_concat(char *s1, char *s2);
		
int **alloc_grid(int width, int height);
		
void free_grid(int **grid, int height);
		
char *argstostr(int ac, char **av);
			
#endif


## 0-create_array.c


#include "main.h"
		
#include <stdlib.h>
		
/**
		
 * create_array - create array of size size and assign char c
		
 * @size: size of array
		
 * @c: char to assign
		
 * Description: creat array of size size and assign char c
		
 * Return: pointer to array, NULL if fail
		
 *
		
 */
		
char *create_array(unsigned int size, char c)
		
{
		
	char *str;
		
	unsigned int i;
		

		
	str = malloc(sizeof(char) * size);
		
	if (size == 0 || str == NULL)
		
		return (NULL);
		

		
	for (i = 0; i < size; i++)
		
		str[i] = c;
		
	return (str);
		
}


## 1-strdup.c


#include <stdio.h>
		
#include <stdlib.h>
		
#include "main.h"
		
/**
		
 * _strdup - duplicate to new memory space location
		
 * @str: char
		
 * Return: 0
		
 */
		
char *_strdup(char *str)
		
{
		
	char *aaa;
		
	int i, r = 0;
		

		
	if (str == NULL)
		
		return (NULL);
		
	i = 0;
		
	while (str[i] != '\0')
		
		i++;
		

		
	aaa = malloc(sizeof(char) * (i + 1));
		

		
	if (aaa == NULL)
		
		return (NULL);
		

		
	for (r = 0; str[r]; r++)
		
		aaa[r] = str[r];
		

		
	return (aaa);
		
}


## 2-str_concat.c


#include "main.h"
		
#include <stdlib.h>
		
/**
		
 * str_concat - get ends of input and add together for size
		
 * @s1: input one to concat
		
 * @s2: input two to concat
		
 * Return: concat of s1 and s2
		
 */
		
char *str_concat(char *s1, char *s2)
		
{
		
	char *conct;
		
	int i, ci;
		

		
	if (s1 == NULL)
		
		s1 = "";
		
	if (s2 == NULL)
		
		s2 = "";
		

		
		i = ci = 0;
		
	while (s1[i] != '\0')
		
		i++;
		
	while (s2[ci] != '\0')
		
		ci++;
		
	conct = malloc(sizeof(char) * (i + ci + 1));
		

		
	if (conct == NULL)
		
		return (NULL);
		
	i = ci = 0;
		
	while (s1[i] != '\0')
		
	{
		
		conct[i] = s1[i];
		
		i++;
		
	}
		

		
	while (s2[ci] != '\0')
		
	{
		
		conct[i] = s2[ci];
		
		i++, ci++;
		
	}
		
	conct[i] = '\0';
		
	return (conct);
		
}

## 3-alloc_grid.c


#include "main.h"
		
#include <stdlib.h>
		
/**
		
 * alloc_grid - nested loop to make grid
		
 * @width: width input
		
 * @height: height input
		
 * Return: pointer to 2 dim. array
		
 */
		
int **alloc_grid(int width, int height)
		
{
		
	int **mee;
		
	int x, y;
		

		
	if (width <= 0 || height <= 0)
		
		return (NULL);
		

		
	mee = malloc(sizeof(int *) * height);
		

		
	if (mee == NULL)
		
		return (NULL);
		

		
	for (x = 0; x < height; x++)
		
	{
		
		mee[x] = malloc(sizeof(int) * width);
		

		
		if (mee[x] == NULL)
		
		{
		
			for (; x >= 0; x--)
		
				free(mee[x]);
		

		
			free(mee);
		
			return (NULL);
		
		}
		
	}
		

		
	for (x = 0; x < height; x++)
		
	{
		
		for (y = 0; y < width; y++)
		
			mee[x][y] = 0;
		
	}
		

		
	return (mee);
		
}


## 4-free_grid.c


#include <stdio.h>
		
#include <stdlib.h>
		
#include "main.h"
		
/**
		
 * free_grid - frees 2d array
		
 * @grid: 2d grid
		
 * @height: height dimension of grid
		
 * Description: frees memory of grid
		
 * Return: nothing
		
 *
		
 */
		
void free_grid(int **grid, int height)
		
{
		
	int i;
		

		
	for (i = 0; i < height; i++)
		
	{
		
		free(grid[i]);
		
	}
		
	free(grid);
		
}


## 100-argstostr.c


#include "main.h"
		
#include <stdlib.h>
		
/**
		
 * argstostr - main entry
		
 * @ac: int input
		
 * @av: double pointer array
		
 * Return: 0
		
 */
		
char *argstostr(int ac, char **av)
		
{
		
	int i, n, r = 0, l = 0;
		
	char *str;
		

		
	if (ac == 0 || av == NULL)
		
		return (NULL);
		

		
	for (i = 0; i < ac; i++)
		
	{
		
		for (n = 0; av[i][n]; n++)
		
			l++;
		
	}
		
	l += ac;
		

		
	str = malloc(sizeof(char) * l + 1);
		
	if (str == NULL)
		
		return (NULL);
		
	for (i = 0; i < ac; i++)
		
	{
		
	for (n = 0; av[i][n]; n++)
		
	{
		
		str[r] = av[i][n];
		
		r++;
		
	}
		
	if (str[r] == '\0')
		
	{
		
		str[r++] = '\n';
		
	}
		
	}
		
	return (str);
		
}


## 101-strtow.c


#include <stdlib.h>
		
#include "main.h"
		

		
/**
		
 *  * count_word - helper function to count the number of words in a string
		
 *   * @s: string to evaluate
		
 *    *
		
 *     * Return: number of words
		
 *      */
		
int count_word(char *s)
		
{
		
		int flag, c, w;
		

		
			flag = 0;
		
				w = 0;
		

		
					for (c = 0; s[c] != '\0'; c++)
		
							{
		
										if (s[c] == ' ')
		
														flag = 0;
		
												else if (flag == 0)
		
															{
		
																			flag = 1;
		
																						w++;
		
																								}
		
													}
		

		
						return (w);
		
}
		
/**
		
 * **strtow - splits a string into words
		
 * @str: string to split
		
 *
		
 * Return: pointer to an array of strings (Success)
		
 * or NULL (Error)
		
 */
		
char **strtow(char *str)
		
{
		
	char **matrix, *tmp;
		
	int i, k = 0, len = 0, words, c = 0, start, end;
		

		
	while (*(str + len))
		
		len++;
		
	words = count_word(str);
		
	if (words == 0)
		
		return (NULL);
		

		
	matrix = (char **) malloc(sizeof(char *) * (words + 1));
		
	if (matrix == NULL)
		
		return (NULL);
		

		
	for (i = 0; i <= len; i++)
		
	{
		
		if (str[i] == ' ' || str[i] == '\0')
		
		{
		
			if (c)
		
			{
		
				end = i;
		
				tmp = (char *) malloc(sizeof(char) * (c + 1));
		
				if (tmp == NULL)
		
					return (NULL);
		
				while (start < end)
		
					*tmp++ = str[start++];
		
				*tmp = '\0';
		
				matrix[k] = tmp - c;
		
				k++;
		
				c = 0;
		
			}
		
		}
		
		else if (c++ == 0)
		
			start = i;
		
	}
		

		
	matrix[k] = NULL;
		

		
	return (matrix);
		
}

