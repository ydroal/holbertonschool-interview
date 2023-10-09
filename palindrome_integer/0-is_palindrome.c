#include "palindrome.h"

/**
 * is_palindrome - checks whether or not a given unsigned integer
 *                 is a palindrome
 *
 * @n: the number to be checked
 *
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long original_number = n;
	unsigned long reversed_number = 0;
	unsigned long ones_place = 0;

	while (n > 0)
	{
		ones_place = n % 10;

		reversed_number = reversed_number * 10 + ones_place;
		n = n / 10;
	}

	if (original_number == reversed_number)
	{
		return (1);
	}
	return (0);

}
