#!/usr/bin/python3
'''
0-island_perimeter
'''


def island_perimeter(grid):
    """
    calculete the perimeter of the island described in grid

    Args:
        grid (list): Alist of list of integers
    Returns:
        bool: the perimeter of the island
    """

    rows = len(grid)
    cols = len(grid[0]) if rows else 0
    perimeter = 0

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                # 上
                if i == 0 or grid[i-1][j] == 0:
                    perimeter += 1
                # 下
                if i == rows-1 or grid[i+1][j] == 0:
                    perimeter += 1
                # 左
                if j == 0 or grid[i][j-1] == 0:
                    perimeter += 1
                # 右
                if j == cols-1 or grid[i][j+1] == 0:
                    perimeter += 1
    return perimeter
