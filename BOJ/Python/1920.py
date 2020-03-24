# Python인 경우 sort랑 in 키워드로 바로 해결 가능합니다.
# 하지만 알고리즘분류가 이분탐색이니까 그걸로 풀어봅시다.    

n = int(input())
a = list(map(int,input().split()))
a.sort()
len_a = len(a)
def solve(t):
    global a
    global len_a
    m = len_a // 2
    l = 0
    r = len_a
    while l < r:
        if a[m] == t:
            return True
        elif a[m] < t:
            l = m + 1
        else:
            r = m
        m = (l+r) // 2
    return False
    

    

m = int(input())
t_list = list(map(int,input().split()))

for t in t_list:
    if solve(t):
        print('1')
    else:
        print('0')
    
