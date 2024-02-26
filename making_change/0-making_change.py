#!/usr/bin/python3
"""
Module makeChange
"""


def makeChange(coins, total):
    """
    Given a pile of coins of different values,
    determine the fewest number of coins needed to meet a given amount total.

    Args:
        coins (list):  list of the values of the coins in your possession.
        total (int): given total amount
    Returns:
        fewest number of coins needed to meet total
        - If total is 0 or less, return 0,
        - If total cannot be met by any number of coins you have, return -1
    """
    if total <= 0:
        return 0

    # 合計額iを達成するために必要な最少コイン数を格納する配列
    # 配列のサイズは total + 1（0からtotalまで）
    # 初期値は無限大（float('inf')）で、合計額iを達成できないことを意味する
    minCoins = [float('inf')] * (total + 1)

    # 合計額0を達成するのに必要なコインの数は0
    minCoins[0] = 0

    # 1から目標の合計額まで各合計額について計算
    for i in range(1, total + 1):
        # 利用可能な全てのコイン額面に対してループ
        for coin in coins:
            if i >= coin:
                # 現在の合計額iに対して、coinを使う場合の最少コイン数を計算
                # その値をminCoins[i]の現在の値と比較し、小さい方をminCoins[i]に格納
                minCoins[i] = min(minCoins[i], minCoins[i - coin] + 1)

    # minCoins[total]には、目標の合計額を達成するために必要な最少コイン数が格納されている
    # その値が無限大でなければ、その値を返す（達成できる）
    # 無限大の場合は、-1を返す（達成できない）
    return minCoins[total] if minCoins[total] != float('inf') else -1
