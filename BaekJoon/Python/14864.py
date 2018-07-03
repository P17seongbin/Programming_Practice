import sys

n,m = map(int,sys.stdin.readline().split())

connection = [(x-1) for x in range(n+1)]

for i in range(m):
    v,u = map(int,sys.stdin.readline().split())
    connection[v] += 1
    connection[u] -= 1

res = [0 for x in range(n+1)]

for i in range(1,n+1):
    if not res[connection[i]+1] == 0:
        sys.stdout.write('-1')
        break
    else:
        res[connection[i]+1] = 1
        if i == n:
            for j in range(1,n+1):
                sys.stdout.write(str(connection[j]+1))
                sys.stdout.write(" ")
        
