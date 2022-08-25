#!/usr/bin/python3
"""
Main file for testing
"""

minOperations = __import__('0-minoperations').minOperations

n = 7
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))

n = 24
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))
