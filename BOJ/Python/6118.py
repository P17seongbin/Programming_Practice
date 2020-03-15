import sys
import queue

v,e = map(int,sys.stdin.readline().split())

edge = [[] for y in range(v+1)]
ver_queue = queue.Queue()
ver_queue.put(1)
dist = [100000 for x in range(v+1)]
dist[1] = 0

for i in range(e):
    v1,v2 = map(int,sys.stdin.readline().split())
    edge[v1].append(v2)
    edge[v2].append(v1)

while not ver_queue.empty():
    sp = ver_queue.get()
    for j in range(len(edge[sp])):
        if dist[edge[sp][j]] > (dist[sp]+1) :
            dist[edge[sp][j]] = dist[sp] + 1
            ver_queue.put(edge[sp][j])
    
max_dis = -1
max_pos = -1
max_c = 0

for i in range(1,v+1):
    if dist[i] > max_dis:
        max_dis = dist[i]
        max_pos = i
        max_c = 1
    elif dist[i] == max_dis:
        max_c += 1

sys.stdout.write(str(max_pos) + " " + str(max_dis) + " " + str(max_c))
