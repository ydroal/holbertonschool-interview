#!/usr/bin/python3
"""The Module for Pascal's Triangle
"""


def pascal_triangle(n):
    """
    Create a list of lists of integers representing the Pascal’s triangle of n

    Args:
    n (int): The number of levels in the Pascal's triangle to generate.

    Returns:
    A list of lists of integers representing the Pascal’s triangle of n.
    """
    if n <= 0:
        return []

    list_triangle = [[1]]

    for i in range(1, n):
        row = [1]
        for j in range(1, i):
            row.append(list_triangle[i-1][j-1] + list_triangle[i-1][j])
        row.append(1)
        list_triangle.append(row)

    return list_triangle
