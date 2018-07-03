class Union_Find:
    def init(self,index):
        self.index = index
        self.parent = index
        self.rank = 0
    

def find(x):
    if x.parent == x.index:
        return x.index
    else:
        x.parent = find(x.parent).index
        return x.parent

def Union(x,y):
    root_x = find(x)
    root_y = find(y)
    if root_x == root_y:
        return
    elif root_x.rank < root_y.rank:
        root_x.parent = root_y
        root_y.rank = root_x.rank + 1
    elif root_x.rank > root_y.rank:
        root_y.parent = root_x.index
        root_x.rank = root_y.rank + 1

t = int(input())

for z in range(t):
    v,e = map(int,input().split())
    vertex = []
    edge = []
    for i in range(v):
        t = Union_Find()
        t.init(i)
        vertex.append(t)
    for i in range(e):
        edge.append(list(map(int,input().split())))
    edge.sort(key = lambda x : (x[2]))
    weight = 0
    for i in range(e):
        print(find(vertex[edge[i][0]]),find(vertex[edge[i][1]]))
        if find(vertex[edge[i][0]]) == find(vertex[edge[i][1]]):
            continue
        else:
            weight += edge[i][2]
            Union(vertex[edge[i][0]],vertex[edge[i][1]])
    print(weight)
        
