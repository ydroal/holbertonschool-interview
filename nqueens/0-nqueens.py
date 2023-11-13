#!/usr/bin/python3
import sys


def could_place(board, row, col):
    """
    Check if a queen can be placed here

    Args:
        board (list): A list representing the current state of the chessboard.
                      - Index indicates the row
                      - Each element indicates the position of the row
        row (int): Index of the row where we want to place the new queen
        col (int): Index of the column where we want to place the new queen
    Returns:
        bool: True if queen can be placed, False otherwise

    """
    for i in range(row):
        if board[i] == col or \
           board[i] - i == col - row or \
           board[i] + i == col + row:
            return False
    return True


def place_queens(n, row, board, solutions):
    """
    Place queens on the chessboard, It's called recursively

    Args:
        n (int): Chess board size (N x N)
        row (int): The current row index where the queen is being placed.
        board (list): A list representing the current state of the chessboard
        solutions (list): A list to store all the valid solutions

    Returns:
        None
    """
    if row == n:
        solutions.append(board[:])
        return

    # 現在の行のすべての列に対してチェック
    for col in range(n):
        if could_place(board, row, col):
            board[row] = col  # 現在の行にクイーンを配置
            place_queens(n, row + 1, board, solutions)  # 再帰的に呼び出し
            board[row] = -1  # 呼び出し元の関数(前の行)に戻ってバックトラックが実行される


def solveNQ():
    args = sys.argv
    if len(args) != 2:
        print('Usage: nqueens N')
        exit(1)

    try:
        n = int(args[1])
    except ValueError:
        print('N must be a number')
        sys.exit(1)

    if int(args[1]) < 4:
        print(' N must be at least 4')
        exit(1)

    solutions = []
    # -1はクイーンがまだ配置されていない状態
    board = [-1] * n

    place_queens(n, 0, board, solutions)

    for solution in solutions:
        print_format = [[i, col] for i, col in enumerate(solution)]
        print(print_format)


if __name__ == "__main__":
    solveNQ()
