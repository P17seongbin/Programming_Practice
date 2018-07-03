
n = int(input())

for i in range(n):
    t = int(input())
    print( t // 50000 + (t % 50000) // 10000 + (t % 10000) // 5000 + (t % 5000) // 1000)
