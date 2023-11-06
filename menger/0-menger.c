#include "menger.h"
/**
 * is_filled - Determines whether the specified cell
 * 　　　　　　 (specified by row and column) should be filled.
 *
 * @row: The row number of the cell
 * @column: The column number of the cell
 * Return: Nothing
 */

void is_filled(int row, int column)
{
	while (row > 0 || column > 0)
	{
		if (row % 3 == 1 && column % 3 == 1)
		{
		putchar(' ');
		return;
		}
		row /= 3;
		column /= 3;
	}
	putchar('#');

}

/**
 * menger - Draw a Menger sponge(2D)
 *
 * @level: The level of the Menger Sponge to draw
 * Return: Nothing
 */

void menger(int level)
{
	int size, i, j;


	if (level < 0)
		return;

	size = round(pow(3, level));

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
			is_filled(i, j);
		putchar('\n');
	}
}
