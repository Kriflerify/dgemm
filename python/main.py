#!/usr/bin/python3
import math
import random as r
import time
import sys

N = 100
K = 10

def gen():
    M = 2*math.sqrt((10 ** 16)/N)
    A = [[(r.random()-0.5)*M for i in range(N)] for j in range(N)]
    B = [[(r.random()-0.5)*M for i in range(N)] for j in range(N)]
    C = [[0]*N]*N

    return A, B, C


def mult(A, B, C):
    for i in range(N):
        for j in range(N):
            C[i][j] = sum([A[i][k]*B[k][j] for k in range(N)])

def main():
    time_record = []
    for i in range(K):
        A, B, C = gen()

        start_time = time.time()
        mult(A, B, C)
        finish_time = time.time()

        duration_time = finish_time - start_time
        time_record += [duration_time]
        print(f"Loop {i} took {duration_time} seconds.")

    average_time = sum(time_record)/K
    print(f"Average duration: {average_time} seconds.")
    

if __name__=="__main__":
    if len(sys.argv)>1:
        N = int(sys.argv[1])
    if len(sys.argv)>2:
        K = int(sys.argv[2])

    main()
