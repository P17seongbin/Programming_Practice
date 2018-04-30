#http://codeforces.com/problemset/problem/967/B
n,A,B = map(int,input().split())

hole = list(map(int,input().split()))
first = hole[0]
hole[1:] = sorted(hole[1:],reverse=True)
#S1 * A / (Sum) 이 B보다 클때까지 막으면 된다.
Sum = 0
for i in range(len(hole)):
    Sum += hole[i]


c=0

for i in range(1,len(hole)):
    if (hole[0] * A / Sum) < B:
        c += 1
        Sum -= hole[i]
    else:

        break
print(c)  
