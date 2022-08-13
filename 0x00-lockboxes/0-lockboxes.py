#!/usr/bin/python3
'''Module contains canUnlockAll function'''


def canUnlockAll(boxes):
    '''Function determines of all boxes can be opened'''
    bufferList = [0]

    for idx1 in bufferList:
        for idx2 in boxes[idx1]:
            if idx2 not in bufferList and idx2 < len(boxes):
                bufferList.append(idx2)

    return len(bufferList) == len(boxes)
