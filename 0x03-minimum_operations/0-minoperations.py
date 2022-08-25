#!/usr/bin/python3
'''Module contains minOperations function'''


def minOperations(n):
    '''
    Function calculates the fewest bufferber of operations
    needed to result in exactly n 'H' characters in the file
    '''
    buffer = n
    div = 2
    iterations = 0
    if type(n) is not int or n < 2:
        return 0
    while buffer > 1:
        if buffer % div == 0:
            buffer /= div
            iterations += div
        else:
            div += 1
    return iterations
