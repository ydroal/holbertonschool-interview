#include "sort.h"

/**
 * swap - Swap array elements
 *
 * @array: pointer to the array to sort
 * @index_a: index of element to be swap
 * @index_b: index of element to be swap
 * Return: Nothing
 */
void swap(int *array, int index_a, int index_b)
{
	int temp;

	temp = array[index_a];
	array[index_a] = array[index_b];
	array[index_b] = temp;
}

/**
 * down_to_leaf - Repeat comparison parent-child for selected node (parent)
 *
 * @array: pointer to the array to sort
 * @array_size: size of array (for print array)
 * @size: size of array
 * @index: The node to compare with its child
 * Return: Nothing
 */
void down_to_leaf(int *array, size_t array_size, size_t size, size_t index)
{
	size_t left = index * 2 + 1;
	size_t right = index * 2 + 2;
	size_t max_idx = index;

	/* left が存在する場合、max_idx と比較 */
	if (left < size && array[left] > array[max_idx])
	max_idx = left;

	/* right が存在する場合、max_idx と比較 */
	if (right < size && array[right] > array[max_idx])
	max_idx = right;

	/* index より大きい値があれば交換 */
	/* down_to_leaf を再帰的に呼び出す */
	if (index != max_idx)
	{
		swap(array, index, max_idx);
		print_array(array, array_size);
		down_to_leaf(array, array_size, size, max_idx);
	}
}

/**
 * build_heap - Initialize heap
 *
 * @array: pointer to the array to sort
 * @size: size of array
 *
 * Return: Nothing
 */
void build_heap(int *array, size_t size)
{
	size_t array_size = size;
	int i;
	/* ヒープの初期化 */
	for (i = (size / 2) - 1; i >= 0; i--)
		down_to_leaf(array, array_size, size, i);
}

/**
 * heap_sort - isorts an array of integers in ascending order using
 *	the Heap sort algorithm
 *
 * @array: pointer to the array to sort
 * @size: size of array
 *
 * Return: Nothing
 */
void heap_sort(int *array, size_t size)
{
	size_t array_size = size;

	if (size >= 2)
	{
		build_heap(array, size);

		while (size > 1)
		{
			swap(array, 0, --size); /* ヒープサイズを1減らす */
			print_array(array, array_size);
			down_to_leaf(array, array_size, size, 0);
		}
	}
}
