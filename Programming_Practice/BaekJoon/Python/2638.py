global delta_r
global delta_c
global r
global c

#치즈를 깎으면 True를 리턴
#0: 빈 공간, 1: 치즈, 2 : 이미 돌아본 빈 공간
#현재 위치에 도달하면 
def carve_cheese (field,r,c):
    field 
    is_carved = False
    for i in range(4):
        dr = r + delta_r[i]
        dc = c + delta_c[i]
        if 0 <= dr && dr < r:
            if 0 <= dc && dc < r:
                c


delta_r = [-1,0,1,0]
delta_c = [1,0,-1,0]

r,c = map(int,input().split())

field = []

for i in range(r):
    field.append(input().split(' '))
    field[i] = list(map(int,field[i]))
print(field)


