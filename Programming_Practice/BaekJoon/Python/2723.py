
def nCr(n,r):
    n = 1
    for i in range(n-r,n+1):
        n = n * i
    for i in range(1,r+1):
        n = n / i
    return n

def facto(n):
    if n <= 1:
        return 1
    else:
        return n * facto(n-1)
    

#B개 중 N개의 Group을 뽑는 방법: (B+N-1)! / (B! * (N-1)!)


t = int(input())
for i in range(t):
    b = int(input())
    n = 0
    for j in range(0,b-1):
        n = n + (facto(b+j) / facto(j) / facto(b)) * (j+1)
    n = n + 1
    print(n)
