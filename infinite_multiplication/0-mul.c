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
 * handle_carry - Handles the carryover for each digit of the multiplication
 * result and expands memory if it need
 * @result: Pointer to the array storing of the multiplication result
 * @len1: The length of the first multiplicand.
 * @len2: The length of the second multiplicand.
 * Return: 1 - if a carryover exists in the highest digit, 0 - otherwise
 */
int handle_carry(int *result, int len1, int len2)
{
	/* 繰り上がりを処理する */
	int i;
	int carry = 0;

	for (i = 0; i < len1 + len2 - 1; i++)
	{
		result[i] += carry;
		carry = result[i] / 10;
		result[i] %= 10;
	}

	/* 最高位に桁上がりがあれば、メモリ拡張して桁を追加 */
	if (carry > 0)
	{
		/* 新たなメモリを確保 */
		int *temp = malloc((len1 + len2) * sizeof(int));
		/* resultの内容をtempにコピー */
		for (i = 0; i < len1 + len2 - 1; i++)
		{
			temp[i] = result[i];
		}
		/* 最高位に繰り上がりを設定 */
		temp[len1 + len2 - 1] = carry;
		/* 古いメモリを解放して新しいメモリをresultに設定 */
		free(result);
		result = temp;
		return (1);
	}
	return (0);
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
	int i, j;

	result = malloc((len1 + len2 - 1) * sizeof(int));
	for (i = 0; i < len1 + len2 - 1; i++)
	{
		result[i] = 0;
	}

	/* 各桁を掛け合わせる */
	for (i = 0; i < len1; i++)
	{
		for (j = 0; j < len2; j++)
			{
				result[i + j] += (num1[i] - '0') * (num2[j] - '0');
			}
	}

	int carry_over = handle_carry(result, len1, len2);

	/* 結果を出力 */
	int end = carry_over ? len1 + len2 - 1 : len1 + len2 - 2;

	for (i = 0; i <= end; i++)
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
