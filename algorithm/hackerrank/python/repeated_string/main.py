#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the repeatedString function below.
def repeatedString(s, n):
    result = 0
    a_cnt = 0
    a_minor_cnt = 0
    strlen = len(s)

    major = int(n/strlen)
    minor = n%strlen

    for i in range(0,strlen):
        if s[i] == 'a':
            a_cnt = a_cnt + 1

            if i < minor:
                a_minor_cnt = a_minor_cnt + 1
        
    result = major * a_cnt + a_minor_cnt

    return result

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    n = int(input())

    result = repeatedString(s, n)

    fptr.write(str(result) + '\n')

    fptr.close()
