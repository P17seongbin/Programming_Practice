import heapq as HQ
import sys

def Enquiry(lis1):
    if not lis1:
        return 1
    else:
        return 0

def find(x):
    if x.par != x:
        x.rank = 0
        x.par = find(x.par)
    return x.par

def union(x,y):
    xroot = find(x)
    yroot = find(y)
    if xroot == yroot:
        return
    elif xroot.rank < yroot.rank:
        xroot.par = yroot
    elif xroot.rank > yroot.rank:
        yroot.par = xroot
    else:
        xroot.par = yroot
        yroot.rank = xroot.rank+1
        


class Edge_Datum:
    def __init__(self,u,v,w): #undirected edge(u&v are Vertex_Datum)
        self.u = u
        self.v = v
        self.weight = w
    def __lt__(self,other):
        return self.weight < other.weight

class Vertex_Datum:
    def __init__(self,index):
        self.index = index
        self.connected = []
        self.parent = self
        self.rank = 0
        self.par = self
    def connect(self,target,weight):
        temp = Edge_Datum(self,target,weight)
        self.connected.append(temp)
    def sort_connect(self):
        self.connected = sorted(self.connected,key = lambda x:x.weight)
        
while(True):
    origin_cost = 0
    v,e = map(int,sys.stdin.readline().split())
    if v == 0 and e == 0:
        break
    
    vertex_cache = []
    for i in range(v):
        t = Vertex_Datum(i)
        vertex_cache.append(t)
    for i in range(e):
        u,v,w = map(int,input().split())
        vertex_cache[u].connect(vertex_cache[v],w)
        vertex_cache[v].connect(vertex_cache[u],w)
        origin_cost += w
    for i in range(v):
        vertex_cache[i].sort_connect()

    edge_cache = []
    t_len = len(vertex_cache[0].connected)
    for i in range(t_len):
        HQ.heappush(edge_cache,vertex_cache[0].connected[i])
    connect_count = 1
    total_cost = 0
    
    while not Enquiry(edge_cache):
        edge_top = HQ.heappop(edge_cache)
        u = edge_top.u
        v = edge_top.v
        w = edge_top.weight

        uroot = find(u)
        vroot = find(v)
        if uroot == vroot:
            continue
        else:
            union(u,v)
            t_len = len(v.connected)
            for i in range(t_len):
                HQ.heappush(edge_cache,v.connected[i])
            total_cost += w
    print(origin_cost - total_cost)
    



    
    
