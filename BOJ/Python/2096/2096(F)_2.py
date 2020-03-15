#Failed
#bottom-up Dynamic Programming
#Sliding Window method

import sys

global min_cache
global max_cache
global score_value
global n

def find_maxmin(x,y,Is_max):
    if y < 0 or y >= 3:
        return -1
    _x = 1
    if x == n-1:
        _x = 0
        
    delta_y = [-1,0,1]
    if Is_max:
        if max_cache[_x][y] == -10:
            if x == n-1:
                max_cache[_x][y] = score_value[x][y]
            else:
                max_cache[_x][y] = max(max_cache[0][max(0,y-1):min(3,y+2)]) + score_value[x][y]
        return max_cache[_x][y]
    else:
        if min_cache[_x][y] == -10:
            if x == n-1:
                min_cache[_x][y] = score_value[x][y]
            else:
                min_cache[_x][y] = min(min_cache[0][max(0,y-1):min(3,y+2)]) + score_value[x][y]
        return min_cache[_x][y]

n= int(input())
score_value=[]

min_cache = [[-10 for x in range(n)] for y in range(2)]
max_cache = [[-10 for x in range(n)] for y in range(2)]

for i in range(n):
    score_value.append(list(map(int,sys.stdin.readline().split())))

for i in range(n-1,-1,-1):
    for j in range(3):
        find_maxmin(i,j,True)
        find_maxmin(i,j,False)
    if not i == n-1:
        max_cache[0] = max_cache[1].copy()
        min_cache[0] = min_cache[1].copy()
        max_cache[1] = [-10 for x in range(3)]
        min_cache[1] = [-10 for x in range(3)]
        
print(max(max_cache[0]),min(min_cache[0]))

                                          
        
