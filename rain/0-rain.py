#!/usr/bin/python3
"""
Module to calculate how much rainwater is retained by walls
"""


def rain(walls):
    """
    Calculate how many square units of water will be retained after it rains.

    Args:
    walls: List of non-negative integers where each integer represents
            the height of a wall of width 1.

    Returns:
    Integer indicating the total amount of rainwater retained.
    """
    if not walls:
        return 0

    total_water = 0
    for i in range(1, len(walls) - 1):
        left_max = max(walls[:i])
        right_max = max(walls[i+1:])
        water_level = min(left_max, right_max)

        if walls[i] < water_level:
            total_water += water_level - walls[i]

    return total_water
