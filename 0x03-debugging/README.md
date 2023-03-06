0x03. C - Debugging

Debugging is the process of finding and fixing errors in software that prevents it from running correctly. As you become a more advanced programmer and an industry engineer, you will learn how to use debugging tools such as gdb or built-in tools that IDEs have. However, it’s important to understand the concepts and processes of debugging manually.

Requirements
General
* Allowed editors: vi, vim, emacs
* All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
* All your files should end with a new line
* Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
* A README.md file at the root of the repo, containing a description of the repository
* A README.md file, at the root of the folder of this project (i.e. 0x03-debugging), describing what this project is about.


#TASKS.

0. Multiple mains
mandatory
In most projects, we often give you only one main file to test with. For example, this main file is a test for a postitive_or_negative() function similar to the one you worked with in an earlier C project:

1. Like, comment, subscribe
mandatory
Copy this main file. Comment out (don’t delete it!) the part of the code that is causing the output to go into an infinite loop.

Don’t add or remove any lines of code, as we will be checking your line count. You are only allowed to comment out existing code.
You do not have to compile with -Wall -Werror -Wextra -pedantic for this task.

2. 0 > 972?
mandatory
This program prints the largest of three integers.

3. Leap year
mandatory
This program converts a date to the day of year and determines how many days are left in the year, taking leap year into consideration.



0-main.c

#include "main.h"
/**
* main - Test function for positive or negative
* Return: 0
*/
int main(void)
{
int i;
i = 0;
positive_or_negative(i);
return (0);
}


main.h

#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
void positive_or_negative(int i);
int largest_number(int a, int b, int c);
void print_remaining_days(int month, int day, int year);
int convert_day(int month, int day);
#endif


1-main.c

#include <stdio.h>
/**
* main - causes an infinite loop
* Return: 0
*/
int main(void)
{
int i;
printf("Infinite loop incoming :(\n");
i = 0;
/*while (i < 10)*/
/*{*/
/*putchar(i);*/
/*}*/
printf("Infinite loop avoided! \\o/\n");
return (0);
}



2-largest_number.c

#include "main.h"
/**
* largest_number - returns the largest of 3 numbers
* @a: first integer
* @b: second integer
* @c: third integer
* Return: largest number
*/
int largest_number(int a, int b, int c)
{
int largest;
if (a > b && a > c)
{
largest = a;
}
else if (a > b && c > a)
{
largest = c;
}
else if (b > c)
{
largest = b;
}
else
{
largest = c;
}
return (largest);
}



3-print_remaining_days.c

#include <stdio.h>
#include "main.h"
/**
 * print_remaining_days - takes a date and prints how many days are
 * left in the year, taking leap years into account
 * @month: month in number format
 * @day: day of month
 * @year: year
 * Return: void
 */
void print_remaining_days(int month, int day, int year)
{
if ((year % 100 == 0 && year % 400 == 0) || (year % 4 == 0))
{
if (month > 2 && day >= 60)
{
day++;
}
printf("Day of the year: %d\n", day);
printf("Remaining days: %d\n", 366 - day);
}
else
{
if (month == 2 && day == 60)
{
printf("Invalid date: %02d/%02d/%04d\n", month, day - 31, year);
}
else
{
printf("Day of the year: %d\n", day);
printf("Remaining days: %d\n", 365 - day);
}
}
}

