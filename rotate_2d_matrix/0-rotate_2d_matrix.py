#!/usr/bin/python3
"""
Mmodule to rotate a 2D matrix
"""


def rotate_2d_matrix(matrix):
    """
    Rotate the given n x n 2D matrix 90 degrees clockwise.

    Args:
    matrix (list of list of int): The matrix to be rotated.

    Returns:
    None: Nothing.
    """
    n = len(matrix)
    for i in range(n):
        for j in range(i, n):
            # タプルアンパッキング(右辺のタプルを作成してからアンパック)
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
    for i in range(n):
        matrix[i].reverse()
