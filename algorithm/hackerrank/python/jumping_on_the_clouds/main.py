#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the jumpingOnClouds function below.
def jumpingOnClouds(c):

    result = 0
    cnt0 = 0

    for i in range(0,len(c)):
        if c[i] == 0:
            cnt0 = cnt0+1;

        if c[i] == 1:
            result = result + int(cnt0/2) + 1
            cnt0 = 0;

    result = result + int(cnt0/2)

    return result

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    c = list(map(int, input().rstrip().split()))

    result = jumpingOnClouds(c)

    fptr.write(str(result) + '\n')

    fptr.close()

