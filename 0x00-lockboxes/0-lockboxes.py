#!/usr/bin/python3
"""
You have n number of locked boxes in front of you.
Each box is numbered sequentially from 0 to n - 1
and each box may contain keys to the other boxes.
"""


def canUnlockAll(boxes):
    """Unlocks boxes"""

    if type(boxes) is not list:
        return False

    if len(boxes) == 0:
        return False

    unlock = [0]
    for key in unlock:
        for element in boxes[key]:
            if element not in unlock and element < len(boxes):
                unlock.append(element)

    if len(unlock) == len(boxes):
        return True
    return False
