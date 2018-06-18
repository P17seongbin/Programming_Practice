
import sys
import math
import bisect
import itertools

import time

global start_time

n,q = list(map(int,sys.stdin.readline().strip().split(' ')))
str_seq = list(map(int,input().split()))
arrow_seq = list(map(int,input().split()))
str_stacksum = [str_seq[0]]#누적합
#str_stacksum = [1000000000]#누적합


for i in range(1,n):
    str_stacksum.append(str_stacksum[i-1] + str_seq[i])
    #str_stacksum.append(str_stacksum[i-1] + 1000000000)
start_time = time.time()
stack_arrow = 0
tank_index = 0
for i in range(q):
    stack_arrow += arrow_seq[i]
    #stack_arrow += 1000000000
    ##다 죽일때까지
    tank_index = bisect.bisect_left(str_stacksum,stack_arrow)
    if tank_index < n and str_stacksum[tank_index] == stack_arrow:
        tank_index += 1
    if tank_index == n: # 다 죽음
        stack_arrow = 0
        print(n)
    else:
        print(n-tank_index)
#print(time.time()-start_time)
