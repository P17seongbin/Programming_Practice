#Sliding Window Method
import sys
n= int(input())
score_value=[]

min_cache = [0 for y in range(2)]
max_cache = [0 for y in range(2)]

for i in range(n):
    score_value=list(map(int,sys.stdin.readline().split()))
    min_t = []
    max_t = []
    for i in range(3):
        min_t.append(min(min_cache[max(0,i-1):min(3,i+2)]) + score_value[i])
        max_t.append(max(max_cache[max(0,i-1):min(3,i+2)]) + score_value[i])
    min_cache = min_t.copy()
    max_cache = max_t.copy()
    
print(max(max_cache),min(min_cache))

                                        
