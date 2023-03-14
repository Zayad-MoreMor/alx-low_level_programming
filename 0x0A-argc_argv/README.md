## C - argc, argv
		

		
## TASKS
		

		
[0. It ain't what they call you, it's what you answer to](0-whatsmyname.c)
		

		
Write a program that prints its name, followed by a new line.
		

		
If you rename the program, it will print the new name, without having to compile it again
		
You should not remove the path before the name of the program
		

		
[1. Silence is argument carried out by other means](1-args.c)
		

		
Write a program that prints the number of arguments passed into it.
		

		
Your program should print a number, followed by a new line
		

		

		
[2. The best argument against democracy is a five-minute conversation with the average voter](2-args.c)
		

		
Write a program that prints all arguments it receives.
		

		
All arguments should be printed, including the first one
		
Only print one argument per line, ending with a new line
		

		
[3. Neither irony nor sarcasm is argument](3-mul.c)
		

		
Write a program that multiplies two numbers.
		

		
Your program should print the result of the multiplication, followed by a new line
		
You can assume that the two numbers and result of the multiplication can be stored in an integer
		
If the program does not receive two arguments, your program should print Error, followed by a new line, and return 1
		

		
[4. To infinity and beyond](4-add.c)
		

		
Write a program that adds positive numbers.
		

		
Print the result, followed by a new line
		
If no number is passed to the program, print 0, followed by a new line
		
If one of the number contains symbols that are not digits, print Error, followed by a new line, and return 1
		
You can assume that numbers and the addition of all the numbers can be stored in an int
		

		
[5. Minimal Number of Coins for Change](100-change.c)
		

		
Write a program that prints the minimum number of coins to make change for an amount of money.
		

		
Usage: ./change cents
		
where cents is the amount of cents you need to give back
		
if the number of arguments passed to your program is not exactly 1, print Error, followed by a new line, and return 1
		
you should use atoi to parse the parameter passed to your program
		
If the number passed as the argument is negative, print 0, followed by a new line
		
You can use an unlimited number of coins of values 25, 10, 5, 2, and 1 cent
MAIN.H code


#ifndef MAIN_H
		
#define MAIN_H
		

		
int _putchar(char c);
		
int _atoi(char *s);
		

		
#endif


=========================


-putchar code


#include <stdio.h>
		
#include "main.h"
		

		
/**
		
 * _putchar - writes the character c to stdout
		
 * @c:Ther character to print
		
 *
		
 * Return: On success 1.
		
 * On error, -1 is returned and errno is set appropriately.
		
 */
		
int _putchar(char c)
		
{
		
return (write(1, &c, 1));
		
}



=============================



0-whatsmyname.c code


#include <stdio.h>
		
#include "main.h"
		

		
/**
		
 * main - prints the name of the program
		
 * @argc: number of arguments
		
 * @argv: array of arguments
		
 *
		
 * Return: Always 0 (Success)
		
 */
		
int main(int argc __attribute__((unused)), char *argv[])
		
{
		
	printf("%s\n", *argv);
		

		
	return (0);
		
}




==============================


1-args.c code


#include <stdio.h>
		
#include "main.h"
		

		
/**
		
 * main - print the number of arguments passed to the program
		
 * @argc: number of arguments
		
 * @argv: array of arguments
		
 *
		
 * Return: Always 0 (Success)
		
 */
		

		
int main(int argc, char *argv[])
		
{
		
(void) argv; /*Ignore argv*/
		
	printf("%d\n", argc - 1);
		

		
	return (0);
		
}



============================



2-args.c code



#include <stdio.h>
		
#include "main.h"
		

		
/**
		
 * main - prints all arguments it receives
		
 * @argc: number of arguments
		
 * @argv: array of arguments
		
 *
		
 * Return: Always 0 (Success)
		
 */
		
int main(int argc, char *argv[])
		
{
		
	int i;
		

		
	for (i = 0; i < argc; i++)
		
	{
		
		printf("%s\n", argv[i]);
		
	}
		

		
	return (0);
		
}



==============================


3-mul.c code



#include <stdio.h>
		
#include "main.h"
		

		
/**
		
 * _atoi - converts a string to an integer
		
 * @s: string to be converted
		
 *
		
 * Return: the int converted from the string
		
 */
		
int _atoi(char *s)
		
{
		
	int i, d, n, len, f, digit;
		

		
	i = 0;
		
	d = 0;
		
	n = 0;
		
	len = 0;
		
	f = 0;
		
	digit = 0;
		

		
	while (s[len] != '\0')
		
		len++;
		

		
	while (i < len && f == 0)
		
	{
		
		if (s[i] == '-')
		
			++d;
		

		
		if (s[i] >= '0' && s[i] <= '9')
		
		{
		
			digit = s[i] - '0';
		
			if (d % 2)
		
				digit = -digit;
		
			n = n * 10 + digit;
		
			f = 1;
		
			if (s[i + 1] < '0' || s[i + 1] > '9')
		
				break;
		
			f = 0;
		
		}
		
		i++;
		
	}
		

		
	if (f == 0)
		
		return (0);
		

		
	return (n);
		
}
		

		
/**
		
 * main - multiplies two numbers
		
 * @argc: number of arguments
		
 * @argv: array of arguments
		
 *
		
 * Return: 0 (Success), 1 (Error)
		
 */
		
int main(int argc, char *argv[])
		
{
		
	int result, num1, num2;
		

		
	if (argc < 3 || argc > 3)
		
	{
		
		printf("Error\n");
		
		return (1);
		
	}
		

		
	num1 = _atoi(argv[1]);
		
	num2 = _atoi(argv[2]);
		
	result = num1 * num2;
		

		
	printf("%d\n", result);
		

		
	return (0);
		
}



=============================


4-add.c code


#include <stdio.h>
	#include <stdlib.h>
	#include <ctype.h>
	#include <string.h>
	/**
	 * check_num - check - string there are digit
	 * @str: array str
	 *
	 * Return: Always 0 (Success)
	 */
	int check_num(char *str)
	{
		/*Declaring variables*/
		unsigned int count;


		count = 0;
		while (count < strlen(str)) /*count string*/


		{
			if (!isdigit(str[count])) /*check if str there are digit*/
			{
				return (0);
			}


			count++;
		}
		return (1);
	}


	/**
	 * main - Print the name of the program
	 * @argc: Count arguments
	 * @argv: Arguments
	 *
	 * Return: Always 0 (Success)
	 */


	int main(int argc, char *argv[])


	{


		/*Declaring variables*/
		int count;
		int str_to_int;
		int sum = 0;


		count = 1;
		while (count < argc) /*Goes through the whole array*/
		{
			if (check_num(argv[count]))


			{
				str_to_int = atoi(argv[count]); /*ATOI --> convert string to int*/
				sum += str_to_int;
			}


			/*Condition if one of the number contains symbols that are not digits*/
			else
			{
				printf("Error\n");
				return (1);
			}


			count++;
		}


		printf("%d\n", sum); /*print sum*/


		return (0);
	}



=============================



100-change.c code


#include <stdio.h>
		
#include <stdlib.h>
		
#include "main.h"
		

		
/**
		
 * main - prints the minimum number of coins to
		
 * make change for an amount of money
		
 * @argc: number of arguments
		
 * @argv: array of arguments
		
 *
		
 * Return: 0 (Success), 1 (Error)
		
 */
		
int main(int argc, char *argv[])
		
{
		
	int num, j, result;
		
	int coins[] = {25, 10, 5, 2, 1};
		

		
	if (argc != 2)
		
	{
		
		printf("Error\n");
		
		return (1);
		
	}
		

		
	num = atoi(argv[1]);
		
	result = 0;
		

		
	if (num < 0)
		
	{
		
		printf("0\n");
		
		return (0);
		
	}
		

		
	for (j = 0; j < 5 && num >= 0; j++)
		
	{
		
		while (num >= coins[j])
		
		{
		
			result++;
		
			num -= coins[j];
		
		}
		
	}
		

		
	printf("%d\n", result);
		
	return (0);
		
}

