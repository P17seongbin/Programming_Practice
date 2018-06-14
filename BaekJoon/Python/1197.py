def find(x):
    if par[x] == -1:
        return x
    else:
        dep[x] = 1
        par[x] = find(par[x])
        return par[x]

def union(x,y):
    p_x = find(x)
    p_y = find(y)
    if dep[p_x] < dep[p_y]:
        par[p_x] = p_y
    elif dep[p_x] > dep[p_y]:
        par[p_y] = p_x
    else:
        par[p_y] = p_x
        dep[p_x] += 1

dis = []
par = []
dep = []

v,e = map(int,input().split())

for i in range(v):
    par.append(-1)
    dep.append(1)

for i in range(e):
    u,v,w = map(int,input().split())
    dis.append((u-1,v-1,w))

dis = sorted(dis,key = lambda x : x[2])

total_weight = 0
v_c = 0
for i in range(e):
    if find(dis[i][0]) != find(dis[i][1]):
        union(dis[i][0],dis[i][1])
        v_c += 1
        total_weight += dis[i][2]
    if v_c >= v:
        print(par)
        print(total_weight)
        break

    
    



    
