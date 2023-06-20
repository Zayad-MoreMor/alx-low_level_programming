## C - Preprocessor

The C Preprocessor is not a part of the compiler, but is a separate step in the compilation process. In simple terms, a C Preprocessor is just a text substitution tool and it instructs the compiler to do required pre-processing before the actual compilation. We'll refer to the C Preprocessor as CPP.

All preprocessor commands begin with a hash symbol (#). It must be the first nonblank character, and for readability, a preprocessor directive should begin in the first column. The following section lists down all the important preprocessor directives −

## TASKS

0. Object-like Macro
Create a header file that defines a macro named SIZE as an abbreviation for the token 1024.

1. Pi
Create a header file that defines a macro named PI as an abbreviation for the token 3.14159265359.

2. File name
Write a program that prints the name of the file it was compiled from, followed by a new line.
You are allowed to use the standard library

3. Function-like macro
Write a function-like macro ABS(x) that computes the absolute value of a number x.

4. SUM
Write a function-like macro SUM(x, y) that computes the sum of the numbers x and y.





======================================

0-object_like_macro.h CODE


#ifndef OBJECT_LIKE_MACRO_H
#define OBJECT_LIKE_MACRO_H

#define SIZE 1024

#endif



======================================

1-pi.h CODE


#ifndef PI_H
#define PI_H

#define PI 3.14159265359

#endif



======================================

2-main.c CODE


#include <stdio.h>

/**
 * main - prints the name of the file
 *
 * Return: Always 0 (Success)
 */
int ain(void)
{
	printf("%s\n", __FILE__);
	return (0);
}




======================================

3-function_like_macro.h CODE


#ifndef FUNCTION_LIKE_MACRO_H
#define FUNCTION_LIKE_MACRO_H

#define ABS(x) ((x) < (0) ? -(x) : (x))

#endif



======================================

4-sum.h CODE


#ifndef SUM_H
#define SUM_H

#define SUM(x, y) ((x) + (y))

#endif
