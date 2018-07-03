#Failed
#Divide & Conquer

global score
global field
global delta_x
global t

def find_max(y,x):
    res = []
    if y >= t-1:
        score[(y,x)] = field[y][x]
        return score[(y,x)]
    if (y,x) in score:
        return score[(y,x)]
    for i in range(3):
        if x+delta_x[i] >= 0 and x+delta_x[i] < t:
            res.append(find_max(y+1,x+delta_x[i]))
    score[(y,x)] = max(res) + field[y][x]

    return score[(y,x)]

def find_min(y,x):
    res = []
    if y >= t-1:
        score[(y,x)] = field[y][x]
        return score[(y,x)]
    if (y,x) in score:
        return score[(y,x)]
    for i in range(3):
        if x+delta_x[i] >= 0 and x+delta_x[i] < t:
            res.append(find_min(y+1,x+delta_x[i]))
    score[(y,x)] = min(res) + field[y][x]

    return score[(y,x)]
      

score = {(-1,-1):0}

t = int(input())
field = []
delta_x = [-1,0,1]

for i in range(t):
    t_list = list(map(int,input().split()))
    field.append(t_list)

res = []

for i in range(3):
    res.append(find_max(0,i))
print(max(res),end=" ")

score = {(-1,-1):0}
res = []

for i in range(3):
    res.append(find_min(0,i))
print(min(res))



