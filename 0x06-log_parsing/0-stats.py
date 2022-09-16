#!/usr/bin/python3
'''Module reads stdin line by line and computes metrics'''

import sys

codes = {}
status_codes = ['200', '301', '400', '401', '403', '404', '405', '500']
count = 0
size = 0

try:
    for line in sys.stdin:
        if count == 10:
            print("File size: {}".format(size))
            for key in sorted(codes):
                print("{}: {}".format(key, codes[key]))
            count = 1
        else:
            count += 1

        line = line.split()

        try:
            size = size + int(line[-1])
        except (IndexError, ValueError):
            pass

        try:
            if line[-2] in status_codes:
                if codes.get(line[-2], -1) == -1:
                    codes[line[-2]] = 1
                else:
                    codes[line[-2]] += 1
        except IndexError:
            pass

    print("File size: {}".format(size))
    for key in sorted(codes):
        print("{}: {}".format(key, codes[key]))

except KeyboardInterrupt:
    print("File size: {}".format(size))
    for key in sorted(codes):
        print("{}: {}".format(key, codes[key]))
    raise
