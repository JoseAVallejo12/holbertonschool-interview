#!/usr/bin/python3
"""
Main file for testing
"""

minOperations = __import__('0-minoperations').minOperations

n = 4563456
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))

n = 12342
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))
