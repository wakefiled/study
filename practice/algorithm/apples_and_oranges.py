#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the countApplesAndOranges function below.
def countApplesAndOranges(s, t, a, b, apples, oranges):

    new_apples = []
    new_oranges = []

    a_cnt = 0
    o_cnt = 0

    #s t
    for apple in apples:
        a_location = apple+a
        if s <= a_location <= t:
            a_cnt+=1

    
    for oragne in oranges:
        o_location = oragne+b
        if s <= o_location <= t:
            o_cnt+=1

    print("{}\n{}".format(a_cnt,o_cnt))


if __name__ == '__main__':
    st = input().split()

    s = int(st[0])

    t = int(st[1])

    ab = input().split()

    a = int(ab[0])

    b = int(ab[1])

    mn = input().split()

    m = int(mn[0])

    n = int(mn[1])

    apples = list(map(int, input().rstrip().split()))

    oranges = list(map(int, input().rstrip().split()))

    countApplesAndOranges(s, t, a, b, apples, oranges)
