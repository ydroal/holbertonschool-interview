#include "sort.h"

/**
 * countSort - A function to do counting sort of array[] according to
 * the digit represented by exp
 * @array: The array to be sorted
 * @size: The size of the array
 * @exp: The exponent of the digit to be sorted
 */
void countSort(int *array, size_t size, int exp)
{
	int i;
	int count[10] = {0};

	int *result = malloc(sizeof(int) * size);

	if (!result)
		return;

	/* 各桁の出現回数を数える */
	for (i = 0; i < (int)size; i++)
		count[(array[i] / exp) % 10]++;

	/* ソート用にこの桁の実際の位置(index）を出す */
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* アウトプット用の配列を作成 */
	for (i = (int)size - 1; i >= 0; i--)
	{
		result[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	/* ソート後の配列を元の配列にコピー */
	for (i = 0; i < (int)size; i++)
		array[i] = result[i];

	free(result);
}

/**
 * getMax - Get the maximum value in the array
 * @array: The array to find the maximum value
 * @size: The size of the array
 * Return: The maximum value in the array
 */
int getMax(int *array, size_t size)
{
	size_t i;
	int max_value = array[0];

	for (i = 1; i < size; i++)
		if (array[i] > max_value)
		max_value = array[i];
	return (max_value);
}

/**
 * radix_sort - sorts an array of integers in ascending order
 *  using the Radix sort algorithm
 * @array: The array to be sorted
 * @size: The size of array
 * Return: Nothing
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (size < 2)
		return;

	max = getMax(array, size);

	/*
	*最大値 max が基数exp（10の乗数）で割り切れなくなる
	*（0より大きくなる）までループ
	*/
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		countSort(array, size, exp);
		print_array(array, size);
	}

}

