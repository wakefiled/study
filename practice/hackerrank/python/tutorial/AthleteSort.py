#!/bin/python3

import math
import os
import random
import re
import sys

if __name__ == '__main__':
    nm = input().split()

    n = int(nm[0])

    m = int(nm[1])

    arr = []

    for _ in range(n):
        arr.append(list(map(int, input().rstrip().split())))

    k = int(input())

    for i in range(1,n):
        j = i - 1
        key = arr[i][k]
        while arr[j][k] > key and j >=0:
            arr[j+1] = arr[j][k]
            j = j - 1     
        arr[j+1][k] = key

    for i in range(0,n):
        rowResult = ""
        for j in range(0,m):
            rowResult += str(arr[i][j]) + " "
        print(rowResult[0:len(rowResult)-1])

