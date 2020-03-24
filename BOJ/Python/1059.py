l = int(input())
lucky = list(map(int,input().split()))
lucky.sort()
n = int(input()) 


le = 0 # left
ri = l # right
m = (le+ri) // 2 # mid
s = False # n in lucky
while le < ri:
    if lucky[m] == n:
        s = True
        break
    elif lucky[m] < n:
        le = m+1
    else:
        ri = m
    m = (le+ri) // 2

if s:
    print(0)
elif m == 0:
    le = n
    ri = lucky[0] - n
    print(le*ri - 1)
else:
    le = n - lucky[m-1]
    ri = lucky[m] - n
    print(le * ri - 1)
