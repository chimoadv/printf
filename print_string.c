#include "main.h"

/**
 * print_string - prints a string
 * @s: string to be printed
 *
 * Return: number of characters printed
 */
int print_string(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		_putchar(s[i++]);
	return (i);
}
