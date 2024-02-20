#include "sort.h"

/**
 * merge - Merges two subarrays　of array
 *
 * @array: The array to be sorted
 * @tmp: Temporary array for merging
 * @start: Starting index of the first subarray
 * @mid: Ending index of the first subarray, start of the second subarray
 * @end: Ending index of the second subarray
 */
void merge(int *array, int *tmp, int start, int mid, int end)
{
	int i, j, k, l;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + start, mid - start + 1); /* 左サブ配列の表示 */
	printf("[right]: ");
	print_array(array + mid + 1, end - mid); /* 右サブ配列の表示 */

	/* 一時配列tmpにサブ配列の要素をコピー */
	i = start;
	j = mid + 1;
	k = 0; /* tmp配列のインデックス */
	while (i <= mid && j <= end)
	{
		if (array[i] <= array[j])
			tmp[k++] = array[i++];
		else
			tmp[k++] = array[j++];
	}

	/* 残りの要素をコピー */
	while (i <= mid)
		tmp[k++] = array[i++];

	while (j <= end)
		tmp[k++] = array[j++];

	/* tmpからarrayにマージ結果をコピー */
	for (l = 0; l < k; l++)
		array[start + l] = tmp[l];

	printf("[Done]: ");
	print_array(array + start, end - start + 1);
}

/**
 * recursive_merge - Sorts an array of integers in ascending order
 *  using the Merge Sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * @start:　Start index of the array to be processed
 * @end: End index of the array to be processed
 */
void recursive_merge(int *array, int start, int end)
{
	int mid;
	int *tmp;

	if (start < end)
	{
		mid = (start + end) / 2;
		recursive_merge(array, start, mid);
		recursive_merge(array, mid + 1, end);
		tmp = malloc(sizeof(int) * (end - start + 1));
		if (!tmp)
			return;

		/* merge関数を使用して、二つのサブ配列をマージ */
		merge(array, tmp, start, mid, end);
		free(tmp);
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 * using the Merge Sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */

void merge_sort(int *array, size_t size)
{
	if (size >= 2)
	{
		recursive_merge(array, 0, size - 1);
	}
}
