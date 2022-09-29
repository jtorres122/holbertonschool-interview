#include "palindrome.h"

/**
 * is_palindrome - checks if number is a palindrome
 * @n: number to be check
 * Return: 1 if number is a palindrome, 0 if not
 */

int is_palindrome(unsigned long n)
{
	int remainder = 0, original = n, reversed = 0;

	while (n != 0)
	{
		remainder = n % 10;
		reversed = reversed * 10 + remainder;
		n /= 10;
	}
	return (original == reversed);
}
