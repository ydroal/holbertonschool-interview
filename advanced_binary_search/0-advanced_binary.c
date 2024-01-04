#include "search_algos.h"

/**
  * print_array - print an array of integers
  *
  * @array: pointer to the first element of the array to print
  * @low: start index of array
  * @hight: end index of array
  * Return: Nothing
  */

void print_array(int *array, int low, int hight)
{
	int i = low;

	printf("Searching in array: ");
	while (i <= hight)
	{
		if (i == hight)
			printf("%d\n", array[i]);
		else
			printf("%d, ", array[i]);
		i++;
	}
}

/**
  * search_recursion - searches for a value in an array of integers
  *
  * @array: pointer to the first element of the array to search in
  * @low: start index of array
  * @hight: end index of array
  * @value: the value to search for
  * Return: index where value is located
  */

int  search_recursion(int *array, int low, int hight, int value)
{
	int mid;

	if (hight >= low)
	{
		mid = low + (hight - low) / 2;
		print_array(array, low, hight);

		if (array[mid] >= value)
		{
			if (array[mid] == value && (mid == low || array[mid - 1] != value))
			{
				return (mid);
			}
			return (search_recursion(array, low, mid, value));
		}
		return (search_recursion(array, mid + 1, hight, value));
	}
	return (-1);
}

/**
  * advanced_binary - searches for a value in an array of
  *                 integers using the binary search algorithm.
  *
  * @array: pointer to the first element of the array to search in
  * @size: the number of elements in array
  * @value: the value to search for
  * Return: index where the first value is located
  */
int advanced_binary(int *array, size_t size, int value)
{
	int low = 0;
	int hight = (int)size - 1;

	if (array == NULL)
		return (-1);

	return (search_recursion(array, low, hight, value));
}
