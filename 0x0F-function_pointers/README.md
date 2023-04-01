## C - Function pointers
A function pointer is a variable that stores the address of a function that can later be called through that function pointer. This is useful because functions encapsulate behavior. For instance, every time you need a particular behavior such as drawing a line, instead of writing out a bunch of code, all you need to do is call the function. But sometimes you would like to choose different behaviors at different times in essentially the same piece of code. Read on for concrete examples.

## TASKS
0. What's my name
Write a function that prints a name.

Prototype: void print_name(char *name, void (*f)(char *));

1. If you spend too much time thinking about a thing, you'll never get it done
Write a function that executes a function given as a parameter on each element of an array.

Prototype: void array_iterator(int *array, size_t size, void (*action)(int));

where size is the size of the array and action is a pointer to the function you need to use.

2. To hell with circumstances; I create opportunities
Write a function that searches for an integer.

Prototype: int int_index(int *array, int size, int (*cmp)(int));

where size is the number of elements in the array array

cmp is a pointer to the function to be used to compare values

int_index returns the index of the first element for which the cmp function does not return 0

If no element matches, return -1

If size <= 0, return -1

3. A goal is not always meant to be reached, it often serves simply as something to aim at
Write a program that performs simple operations.

You are allowed to use the standard library

Usage: calc num1 operator num2

You can assume num1 and num2 are integers, so use the atoi function to convert them from the string input to int

operator is one of the following:

+: addition
-: subtraction
*: multiplication
/: division
%: modulo
The program prints the result of the operation, followed by a new line

You can assume that the result of all operations can be stored in an int

if the number of arguments is wrong, print Error, followed by a new line, and exit with the status 98

if the operator is none of the above, print Error, followed by a new line, and exit with the status 99

if the user tries to divide (/ or %) by 0, print Error, followed by a new line, and exit with the status 100

This task requires that you create four different files.

3-calc.h
This file should contain all the function prototypes and data structures used by the program. You can use this structure:
3-op_functions.c
This file should contain the 5 following functions (not more):

op_add: returns the sum of a and b. Prototype: int op_add(int a, int b);
op_sub: returns the difference of a and b. Prototype: int op_sub(int a, int b);
op_mul: returns the product of a and b. Prototype: int op_mul(int a, int b);
op_div: returns the result of the division of a by b. Prototype: int op_div(int a, int b);
op_mod: returns the remainder of the division of a by b. Prototype: int op_mod(int a, int b);
3-get_op_func.c
This file should contain the function that selects the correct function to perform the operation asked by the user. You’re not allowed to declare any other function.

Prototype: int (*get_op_func(char *s))(int, int);
where s is the operator passed as argument to the program
This function returns a pointer to the function that corresponds to the operator given as a parameter. Example: get_op_func("+") should return a pointer to the function op_add
You are not allowed to use switch statements
You are not allowed to use for or do ... while loops
You are not allowed to use goto
You are not allowed to use else
You are not allowed to use more than one if statement in your code
You are not allowed to use more than one while loop in your code
If s does not match any of the 5 expected operators (+, -, *, /, %), return NULL
You are only allowed to declare these two variables in this function:
3-main.c
This file should contain your main function only.

You are not allowed to code any other function than main in this file
You are not allowed to directly call op_add, op_sub, op_mul, op_div or op_mod from the main function
You have to use atoi to convert arguments to int
You are not allowed to use any kind of loop -
You are allowed to use a maximum of 3 if statements
4. Most hackers are young because young people tend to be adaptable. As long as you remain adaptable, you can always be a good hacker
Write a program that prints the opcodes of its own main function.

Usage: ./main number_of_bytes

Output format:

the opcodes should be printed in hexadecimal, lowercase
each opcode is two char long
listing ends with a new line
see example
You are allowed to use printf and atoi

You have to use atoi to convert the argument to an int

If the number of argument is not the correct one, print Error, followed by a new line, and exit with the status 1

If the number of bytes is negative, print Error, followed by a new line, and exit with the status 2

You do not have to compile with any flags.


## function_pointers.h

#ifndef FUNCTION_POINTERS_H
#define FUNCTION_POINTERS_H

#include <stddef.h>
#include <stdlib.h>

void print_name(char *name, void (*f)(char *));
int _putchar(char c);
void array_iterator(int *array, size_t size, void (*action)(int));
int int_index(int *array, int size, int (*cmp)(int));

#endif


## 0-print_name.c

#include "function_pointers.h"
#include <stdio.h>
/**
 * print_name - print name using pointer to function
 * @name: string to add
 * @f: pointer to function
 * Return: nothing
 **/
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;

	f(name);
}


## 1-array_iterator.c

#include "function_pointers.h"
#include <stdio.h>
/**
 * array_iterator - prints each array elem on a newl
 * @array: array
 * @size: how many elem to print
 * @action: pointer to print in regular or hex
 * Return: void
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int i;

	if (array == NULL || action == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		action(array[i]);
	}
}


## 2-int_index.c

#include "function_pointers.h"
/**
 * int_index - return index place if comparison = true, else -1
 * @array: array
 * @size: size of elements in array
 * @cmp: pointer to func of one of the 3 in main
 * Return: 0
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || size <= 0 || cmp == NULL)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]))
			return (i);
	}
	return (-1);
}


## 3-main.c

#include "function_pointers.h"
#include <stdlib.h>
#include <stdio.h>
#include "3-calc.h"
/**
 * main - Prints the result of simple operations.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: Always 0.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	int num1, num2;
	char *op;

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	num1 = atoi(argv[1]);
	op = argv[2];
	num2 = atoi(argv[3]);

	if (get_op_func(op) == NULL || op[1] != '\0')
	{
		printf("Error\n");
		exit(99);
	}

	if ((*op == '/' && num2 == 0) ||
	    (*op == '%' && num2 == 0))
	{
		printf("Error\n");
		exit(100);
	}

	printf("%d\n", get_op_func(op)(num1, num2));

	return (0);
}


## 3-op_functions.c

#include "3-calc.h"

int op_add(int a, int b);
int op_sub(int a, int b);
int op_mul(int a, int b);
int op_div(int a, int b);
int op_mod(int a, int b);

/**
 * op_add - Returns the sum of two numbers.
 * @a: The first number.
 * @b: The second number.
 *
 * Return: The sum of a and b.
 */
int op_add(int a, int b)
{
	return (a + b);
}
/**
 * op_sub - Returns the difference of two numbers.
 * @a: The first number.
 * @b: The second number.
 *
 * Return: The difference of a and b.
 */
int op_sub(int a, int b)
{
	return (a - b);
}
/**
 * op_mul - Returns the product of two numbers.
 * @a: The first number.
 * @b: The second number.
 *
 * Return: The product of a and b.
 */
int op_mul(int a, int b)
{
	return (a * b);
}
/**
 * op_div - Returns the division of two numbers.
 * @a: The first number.
 * @b: The second number.
 *
 * Return: The quotient of a and b.
 */
int op_div(int a, int b)
{
	return (a / b);
}
/**
 * op_mod - Returns the remainder of the division of two numbers.
 * @a: The first number.
 * @b: The second number.
 *
 * Return: The remainder of the division of a by b.
 */
int op_mod(int a, int b)
{
	return (a % b);
}


## 3-get_op_func.c

#include "3-calc.h"
#include <stdlib.h>
/**
 * get_op_func - Selects the correct function to perform
 *               the operation asked by the user.
 * @s: The operator passed as argument.
 *
 * Return: A pointer to the function corresponding
 *         to the operator given as a parameter.
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL},
	};

	int i = 0;

	while (ops[i].op != NULL && *(ops[i].op) != *s)
		i++;

	return (ops[i].f);
}



## 3-calc.h

#ifndef CALC_H
#define CALC_H
/**
 * struct op - A struct op.
 * @op: The operator.
 * @f: The associated function.
 */
typedef struct op
{
	char *op;
	int (*f)(int a, int b);
} op_t;

int op_add(int a, int b);
int op_sub(int a, int b);
int op_mul(int a, int b);
int op_div(int a, int b);
int op_mod(int a, int b);
int (*get_op_func(char *s))(int, int);

#endif



## 100-main_opcodes.c

#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints its own opcodes
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	int bytes, i;
	char *arr;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	bytes = atoi(argv[1]);

	if (bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	arr = (char *)main;

	for (i = 0; i < bytes; i++)
	{
		if (i == bytes - 1)
		{
			printf("%02hhx\n", arr[i]);
			break;
		}
		printf("%02hhx ", arr[i]);
	}
	return (0);
}
