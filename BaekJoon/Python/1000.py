def find(a,b):
    x=1
    for i in range(b):
        x = x * a
        x = x % 10
    print(x)

t = int(input())
for i in range(t):
    a,b = map(int,input().split(' '))
    find(a,b)
