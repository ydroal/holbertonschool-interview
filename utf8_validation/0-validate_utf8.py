#!/usr/bin/python3
"""
Module to determines if a given data set represents a valid UTF-8 encoding
"""


def validUTF8(data):
    """
    Check if a given data set represents a valid UTF-8 encoding

    Args:
    data (list[int]): Each integer represents 1 byte of data

    Returns:
    bool: True if data is a valid UTF-8 encoding, else return False
    """
    n_bytes = 0  # 連続するバイトの数

    for num in data:
        num &= 0xFF
        binary = format(num, '08b')

        if n_bytes == 0:
            if binary[0] == '0':
                continue
            elif binary.startswith('110'):
                n_bytes = 1
            elif binary.startswith('1110'):
                n_bytes = 2
            elif binary.startswith('11110'):
                n_bytes = 3
            else:
                return False  # 有効なUTF-8バイトパターンではない
        else:
            if not binary.startswith('10'):
                return False  # 続きのバイトのパターンが10ではない→無効

            n_bytes -= 1  # ２〜４バイト文字の場合、残りの連続するバイト数をデクリメント

    return n_bytes == 0
