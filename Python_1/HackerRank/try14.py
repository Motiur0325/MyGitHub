#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'diagonalDifference' function below.
#
# The function is expected to return an INTEGER.
# The function accepts 2D_INTEGER_ARRAY arr as parameter.
#

def diagonalDifference(arr):
    # Write your code here
    diag1,diag2=0,0
    for i in range(len(arr)):
        for j in range(len(arr)):
            if i==j:
                diag1+=arr[i][j]
            if len(arr[i])-j-1==i:
                diag2+=arr[i][j]
    print(abs(diag1-diag2))
    return(abs(diag1-diag2))

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    arr = []

    for _ in range(n):
        arr.append(list(map(int, input().rstrip().split())))

    result = diagonalDifference(arr)

    fptr.write(str(result) + '\n')

    fptr.close()
