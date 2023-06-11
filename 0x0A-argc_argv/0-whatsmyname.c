#include "main.h"
#include <stdio.h>

/**
 * main - it prints the name of the program
 * @argc: the number of arguments
 * @argv: it is the array of arguments
 *
 * Return: Always 0 (it means successful)
 */
int main(int argc __attribute__((unused)), char *argv[])
{
	printf("%s\n", *argv);

	return (0);
}
