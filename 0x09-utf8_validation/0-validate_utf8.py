#!/usr/bin/python3
'''Module contains validUTF8(data) function'''


def validUTF8(data):
    '''
    Function determines if a given data set
    represents a valid UTF-8 encoding
    '''
    n_bytes = 0

    m1 = 1 << 7
    m2 = 1 << 6

    for idx in data:
        m = 1 << 7
        if n_bytes == 0:
            while m & idx:
                n_bytes += 1
                m = m >> 1
            if n_bytes == 0:
                continue
            if n_bytes == 1 or n_bytes > 4:
                return False
        else:
            if not (idx & m1 and not (idx & m2)):
                return False
        n_bytes -= 1
    return n_bytes == 0
