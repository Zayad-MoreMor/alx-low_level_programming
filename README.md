README.md file


C - More malloc, free
		
TASKS
		
0. Trust no one
		
Write a function that allocates memory using malloc.
		

		
Prototype: void *malloc_checked(unsigned int b);
		

		
Returns a pointer to the allocated memory
		

		
if malloc fails, the malloc_checked function should cause normal process termination with a status value of 98
		

		
1. string_nconcat
		
Write a function that concatenates two strings.
		

		
Prototype: char *string_nconcat(char *s1, char *s2, unsigned int n);
		

		
The returned pointer shall point to a newly allocated space in memory, which contains s1, followed by the first n bytes of s2, and null terminated
		

		
If the function fails, it should return NULL
		

		
If n is greater or equal to the length of s2 then use the entire string s2
		

		
if NULL is passed, treat it as an empty string
		

		
2. calloc
		
Write a function that allocates memory for an array, using malloc.
		

		
Prototype: void *_calloc(unsigned int nmemb, unsigned int size);
		

		
The _calloc function allocates memory for an array of nmemb elements of size bytes each and returns a pointer to the allocated memory.
		

		
The memory is set to zero
		

		
If nmemb or size is 0, then _calloc returns NULL
		

		
If malloc fails, then _calloc returns NULL
		

		
3. array_range
		
Write a function that creates an array of integers.
		

		
Prototype: int *array_range(int min, int max);
		

		
The array created should contain all the values from min (included) to max (included), ordered from min to max
		

		
Return: the pointer to the newly created array
		

		
If min > max, return NULL
		

		
If malloc fails, return NULL
		

		
4. realloc
		
Write a function that reallocates a memory block using malloc and free
		

		
Prototype: void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
		

		
where ptr is a pointer to the memory previously allocated with a call to malloc: malloc(old_size)
		

		
old_size is the size, in bytes, of the allocated space for ptr and new_size is the new size, in bytes of the new memory block
		

		
The contents will be copied to the newly allocated space, in the range from the start of ptr up to the minimum of the old and new sizes
		

		
If new_size > old_size, the “added” memory should not be initialized
		

		
If new_size == old_size do not do anything and return ptr
		

		
If ptr is NULL, then the call is equivalent to malloc(new_size), for all values of old_size and new_size
		

		
If new_size is equal to zero, and ptr is not NULL, then the call is equivalent to free(ptr). Return NULL
		

		
Don’t forget to free ptr when it makes sense
		

		
5. We must accept finite disappointment, but never lose infinite hope
		
Write a program that multiplies two positive numbers.
		

		
Usage: mul num1 num2
		

		
num1 and num2 will be passed in base 10
		

		
Print the result, followed by a new line
		

		
If the number of arguments is incorrect, print Error, followed by a new line, and exit with a status of 98
		

		
num1 and num2 should only be composed of digits. If not, print Error, followed by a new line, and exit with a status of 98
		

		
You are allowed to use more than 5 functions in your file
		

		
You can use bc (man bc) to check your results.


========================================


Main.h codes


#ifndef MAIN_H
	#define MAIN_H


	#include <stdio.h>
	#include <stdlib.h>
	#include <limits.h>


	int _putchar(char c);
	void *malloc_checked(unsigned int b);
	char *string_nconcat(char *s1, char *s2, unsigned int n);
	void *_calloc(unsigned int nmemb, unsigned int size);
	int *array_range(int min, int max);
	void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

	#endif


========================================


0-malloc_checked.c code


#include <stdlib.h>
		
#include "main.h"
		

		
/**
		
 * *malloc_checked - allocates memory using malloc
		
 * @b: number of bytes to allocate
		
 *
		
 * Return: a pointer to the allocated memory
		
 */
		
void *malloc_checked(unsigned int b)
		
{
		
	void *ptr;
		

		
	ptr = malloc(b);
		

		
	if (ptr == NULL)
		
		exit(98);
		

		
	return (ptr);
		
}




==========================================


1-string_nconcat.c


#include <stdlib.h>
		
#include "main.h"
		

		
/**
		
 * *string_nconcat - concatenates n bytes of a string to another string
		
 * @s1: string to append to
		
 * @s2: string to concatenate from
		
 * @n: number of bytes from s2 to concatenate to s1
		
 *
		
 * Return: pointer to the resulting string
		
 */
		
char *string_nconcat(char *s1, char *s2, unsigned int n)
		
{
		
	char *s;
		
	unsigned int i = 0, j = 0, len1 = 0, len2 = 0;
		

		
	while (s1 && s1[len1])
		
		len1++;
		
	while (s2 && s2[len2])
		
		len2++;
		

		
	if (n < len2)
		
		s = malloc(sizeof(char) * (len1 + n + 1));
		
	else
		
		s = malloc(sizeof(char) * (len1 + len2 + 1));
		

		
	if (!s)
		
		return (NULL);
		

		
	while (i < len1)
		
	{
		
		s[i] = s1[i];
		
		i++;
		
	}
		

		
	while (n < len2 && i < (len1 + n))
		
		s[i++] = s2[j++];
		

		
	while (n >= len2 && i < (len1 + len2))
		
		s[i++] = s2[j++];
		

		
	s[i] = '\0';
		

		
	return (s);
		
}


========================================


2-calloc.c code


#include <stdlib.h>
		
#include "main.h"
		

		
/**
		
 * *_memset - fills memory with a constant byte
		
 * @s: memory area to be filled
		
 * @b: char to copy
		
 * @n: number of times to copy b
		
 *
		
 * Return: pointer to the memory area s
		
 */
		
char *_memset(char *s, char b, unsigned int n)
		
{
		
	unsigned int i;
		

		
	for (i = 0; i < n; i++)
		
	{
		
		s[i] = b;
		
	}
		

		
	return (s);
		
}
		

		
/**
		
 * *_calloc - allocates memory for an array
		
 * @nmemb: number of elements in the array
		
 * @size: size of each element
		
 *
		
 * Return: pointer to allocated memory
		
 */
		
void *_calloc(unsigned int nmemb, unsigned int size)
		
{
		
	char *ptr;
		

		
	if (nmemb == 0 || size == 0)
		
		return (NULL);
		

		
	ptr = malloc(size * nmemb);
		

		
	if (ptr == NULL)
		
		return (NULL);
		

		
	_memset(ptr, 0, nmemb * size);
		

		
	return (ptr);
		
}


========================================


3-array_range.c code


#include <stdlib.h>
		
#include "main.h"
		

		
/**
		
 * *array_range - creates an array of integers
		
 * @min: minimum range of values stored
		
 * @max: maximum range of values stored and number of elements
		
 *
		
 * Return: pointer to the new array
		
 */
		
int *array_range(int min, int max)
		
{
		
	int *ptr;
		
	int i, size;
		

		
	if (min > max)
		
		return (NULL);
		

		
	size = max - min + 1;
		

		
	ptr = malloc(sizeof(int) * size);
		

		
	if (ptr == NULL)
		
		return (NULL);
		

		
	for (i = 0; min <= max; i++)
		
		ptr[i] = min++;
		

		
	return (ptr);
		
}


=========================================



100-realloc.c code


#include <stdlib.h>
		
#include "main.h"
		

		
/**
		
 * *_realloc - reallocates a memory block using malloc and free
		
 * @ptr: pointer to the memory previsouly allocated by malloc
		
 * @old_size: size of the allocated memory for ptr
		
 * @new_size: new size of the new memory block
		
 *
		
 * Return: pointer to the newly allocated memory block
		
 */
		
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
		
{
		
	char *ptr1;
		
	char *old_ptr;
		
	unsigned int i;
		

		
	if (new_size == old_size)
		
		return (ptr);
		

		
	if (new_size == 0 && ptr)
		
	{
		
		free(ptr);
		
		return (NULL);
		
	}
		

		
	if (!ptr)
		
		return (malloc(new_size));
		

		
	ptr1 = malloc(new_size);
		
	if (!ptr1)
		
		return (NULL);
		

		
	old_ptr = ptr;
		

		
	if (new_size < old_size)
		
	{
		
		for (i = 0; i < new_size; i++)
		
			ptr1[i] = old_ptr[i];
		
	}
		

		
	if (new_size > old_size)
		
	{
		
		for (i = 0; i < old_size; i++)
		
			ptr1[i] = old_ptr[i];
		
	}
		

		
	free(ptr);
		
	return (ptr1);
		
}



========================================



101-mul.c codes


#include "main.h"
		
#include <stdlib.h>
		
#include <stdio.h>
		

		
#define ERR_MSG "Error"
		

		
/**
		
 * is_digit - checks if a string contains a non-digit char
		
 * @s: string to be evaluated
		
 *
		
 * Return: 0 if a non-digit is found, 1 otherwise
		
 */
		
int is_digit(char *s)
		
{
		
	int i = 0;
		

		
	while (s[i])
		
	{
		
		if (s[i] < '0' || s[i] > '9')
		
			return (0);
		
		i++;
		
	}
		
	return (1);
		
}
		

		
/**
		
 * _strlen - returns the length of a string
		
 * @s: string to evaluate
		
 *
		
 * Return: the length of the string
		
 */
		
int _strlen(char *s)
		
{
		
	int i = 0;
		

		
	while (s[i] != '\0')
		
	{
		
		i++;
		
	}
		
	return (i);
		
}
		

		
/**
		
 * errors - handles errors for main
		
 */
		
void errors(void)
		
{
		
	printf("Error\n");
		
	exit(98);
		
}
		

		
/**
		
 * main - multiplies two positive numbers
		
 * @argc: number of arguments
		
 * @argv: array of arguments
		
 *
		
 * Return: always 0 (Success)
		
 */
		
int main(int argc, char *argv[])
		
{
		
	char *s1, *s2;
		
	int len1, len2, len, i, carry, digit1, digit2, *result, a = 0;
		

		
	s1 = argv[1], s2 = argv[2];
		
	if (argc != 3 || !is_digit(s1) || !is_digit(s2))
		
		errors();
		
	len1 = _strlen(s1);
		
	len2 = _strlen(s2);
		
	len = len1 + len2 + 1;
		
	result = malloc(sizeof(int) * len);
		
	if (!result)
		
		return (1);
		
	for (i = 0; i <= len1 + len2; i++)
		
		result[i] = 0;
		
	for (len1 = len1 - 1; len1 >= 0; len1--)
		
	{
		
		digit1 = s1[len1] - '0';
		
		carry = 0;
		
		for (len2 = _strlen(s2) - 1; len2 >= 0; len2--)
		
		{
		
			digit2 = s2[len2] - '0';
		
			carry += result[len1 + len2 + 1] + (digit1 * digit2);
		
			result[len1 + len2 + 1] = carry % 10;
		
			carry /= 10;
		
		}
		
		if (carry > 0)
		
			result[len1 + len2 + 1] += carry;
		
	}
		
	for (i = 0; i < len - 1; i++)
		
	{
		
		if (result[i])
		
			a = 1;
		
		if (a)
		
			_putchar(result[i] + '0');
		
	}
		
	if (!a)
		
		_putchar('0');
		
	_putchar('\n');
		
	free(result);
		
	return (0);
		
}
