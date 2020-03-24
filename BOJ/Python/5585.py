v = 1000 - int(input())
unit = [500,100,50,10,5,1]
res = 0
for u in unit:
    res += v // u
    v %= u
print(res)
