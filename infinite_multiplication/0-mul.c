#include "holberton.h"

/**
 * _strlen - Count the length of a string
 * @s: the string to counted length
 * Return: lenght of a string
 */

int _strlen(char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

/**
 * multiply - Multiplies two large numbers represented as strings
 * @num1: The first number
 * @num2: The second number
 * Return: Nothing
 */
void multiply(char *num1, char *num2)
{
	int len1 = _strlen(num1);
	int len2 = _strlen(num2);
	int *result;
	int i, j, mul, carry;

	result = malloc((len1 + len2) * sizeof(int));
	for (i = 0; i < len1 + len2 - 1; i++)
	{
		result[i] = 0;
	}

	/* 各桁を掛け合わせる */
	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			mul = (num1[i] - '0') * (num2[j] - '0');
			carry += result[i + j + 1] + mul; /* インデックスを修正 */
			result[i + j + 1] = carry % 10;
			carry /= 10;
		}
		result[i + j + 1] += carry; /* キャリーを加算 */
	}

	/* 先頭の0をスキップして出力 */
	i = 0;
	while (i < len1 + len2 - 1 && result[i] == 0)
		i++;

	for (; i < len1 + len2; i++)
	{
		_putchar(result[i] + '0');
	}
	_putchar('\n');
	free(result);
}


/**
 * _isdigit - Checks if a string is composed only of digits
 * @str: String to be checked
 * Return: 1 - if the string is composed only of digits, 0 - otherwise
 */
int _isdigit(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

/**
 * main - multiplies two positive numbers
 * @argc: number of command line arguments
 * @argv: An array containing the program command line arguments
 * Return: 0 - program executed successfully
 */
int main(int argc, char *argv[])
{
	char *err_msg = "Error\n";
	int i = 0;

	if (argc != 3 || _isdigit(argv[1]) == 0 || _isdigit(argv[2]) == 0)
	{
		while (err_msg[i] != '\0')
		{
			_putchar(err_msg[i]);
			i++;
		}
		exit(98);
	}

	multiply(argv[1], argv[2]);
	return (0);
}
