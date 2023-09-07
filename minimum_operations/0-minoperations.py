#!/usr/bin/python3
'''
Module to calculate the fewest number of operations
'''

def minOperations(n):
    '''
    calculates the fewest number of operations needed to
    result in exactly n 'H' characters in the file.

    Args:
    n (int): Number of 'H' characters to display
    
    Returns:
    int: fewest number of operations
    If n is impossible to achieve, return 0
    '''
    
    if n < 2:
        return 0
    
    ope = 0
    factor = 2
    
    while n > 1:
        while n % factor == 0:
            ope += factor # 素因数の値を加算
            n //= factor
        factor += 1 # 次の素数
    return ope
    
    