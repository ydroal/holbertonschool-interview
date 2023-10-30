#include "slide_line.h"
/**
 *  merge_slid_left - Slided & merged to the left
 *
 * @line: Points to an array of integers
 * @size: Size of array
 *
 * Return: 1 upon success, or 0 upon failure
 */
int merge_slid_left(int *line, int size)
{
	int i, j;
	int destination = 0;

	for (i = 0; i < size - 1 ; i++)
	{
		if (line[i] == 0)
			continue;
		j = i + 1;
		while (j < size && line[j] == 0)
			j++;
		if (j < size && line[i] == line[j])
		{
			line[i] += line[j];
			line[j] = 0;
		}
	}

	for (i = 0; i < size; i++)
	{
		if (line[i] != 0)
		{
			line[destination] = line[i];
			if (i != destination)
				line[i] = 0;
			destination++;
		}
	}
	return (1);
}

/**
 *  merge_slid_right - Slided & merged to the right
 *
 * @line: Points to an array of integers
 * @size: Size of array
 *
 * Return: 1 upon success, or 0 upon failure
 */
int merge_slid_right(int *line, int size)
{
	int i, j;
	int destination = size - 1;

	for (i = size - 1 ; i > 0 ; i--)
	{
		if (line[i] == 0)
			continue;
		j = i - 1;
		while (j > 0 && line[j] == 0)
			j--;

		if (j >= 0 && line[i] == line[j])
		{
			line[i] += line[j];
			line[j] = 0;
		}
	}

	for (i = size - 1; i >= 0 ; --i)
	{
		if (line[i] != 0)
		{
			line[destination] = line[i];
			if (i != destination)
				line[i] = 0;
			destination--;
		}
	}
	return (1);
}

/**
 * slide_line - Reproduce the 2048 game mechanics on a single horizontal line.
 *
 * @line: Points to an array of integers
 * @size: Size of array
 * @direction: Direction to slided & merged
 *
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	int length = (int)size;

	if (direction == SLIDE_LEFT)
		return (merge_slid_left(line, length));

	if (direction == SLIDE_RIGHT)
		return (merge_slid_right(line, length));

	return (0);
}
