#segment tree?
#알고리즘은 맞으나 구현이 지나치게 비효율적임

import sys
import math
global seg_tree
global c

def Init(index):
    res = [0,0]
    if seg_tree[index][1] == -1:
        res = seg_tree[index].copy()
        if res[0] > 0:
            res = [0,0]
        elif res[0] == 0:
            res = [0,1]
        else:
            res = [1,0]
    else:
        l = Init(index*2)
        r = Init(index*2+1)
        res[0] = l[0] + r[0]
        res[1] = l[1] + r[1]
        seg_tree[index] = res.copy()
    return res

def Change(index,s,e,tar_index,delta):
    m = math.floor((s+e) / 2)
    if not (s == tar_index and e == tar_index):
        seg_tree[index][0] += delta[0]
        seg_tree[index][1] += delta[1]
        if tar_index > m:
            Change(index*2 +1,m+1,e,tar_index,delta)
        else:
            Change(index*2 , s,m,tar_index,delta)
            
def Cal(index,s,e,tar_scope):
    if s == e:
        res = []
        tee = seg_tree[index][0]
        if tee > 0:
            res = [0,0]
        elif tee == 0:
            res = [0,1]
        else:
            res = [1,0]
        return res
    
    m = math.floor((s+e) / 2)
    if s == tar_scope[0] and e == tar_scope[1]:
        return seg_tree[index]
    elif tar_scope[0] <= m and tar_scope[1] <= m:
        return Cal(index*2,s,m,tar_scope)
    elif tar_scope[0] > m and tar_scope[1] > m:
        return Cal(index*2+1,m+1,e,tar_scope)
    else:
        l = Cal(index*2,s,m,[tar_scope[0],m])
        r = Cal(index*2+1,m+1,e,[m+1,tar_scope[1]])
        return [l[0]+r[0],l[1]+r[1]]
_c = 0
try:
    while True:
        answer = ''
        n,k = map(int,sys.stdin.readline().split())
        if not _c == 0:
            print('')
        c = 0
        seg_tree = [] #1번부터 2n-1번까지 사용
        for i in range(25):
            if n <= 2**i:
                c = i
                seg_tree = [[0,0] for x in range(2**(c))]
                break
            
        t = list(map(int,sys.stdin.readline().split()))
        #t = [1 for x in range(2**c)]
        for i in range(n):
            seg_tree.append([t[i],-1])
        for i in range(n,2**c):
            seg_tree.append([1,-1])
        Init(1)
        for i in range(k):
            order = list(sys.stdin.readline().split())
            if order[0] == 'C': # Change
                delta=[]
                origin = seg_tree[2**c + int(order[1]) - 1][0]
                alter = int(order[2])
                if origin > 0:
                    delta = [0,0]
                elif origin == 0:
                    delta = [0,-1]
                else:
                    delta = [-1,0]
                    
                if alter > 0:
                    delta[0] += 0
                elif alter == 0:
                    delta[1] += 1
                else:
                    delta[0] += 1
                seg_tree[2**c + int(order[1])-1][0] = alter
                Change(1,1,2**c,int(order[1]),delta)
            else:
                res = []
                if int(order[1]) == int(order[2]):
                    tee = seg_tree[2**c + int(order[1])-1][0]
                    if tee > 0:
                        res = [0,0]
                    elif tee == 0:
                        res = [0,1]
                    else:
                        res = [1,0]
                else:
                    res = Cal(1,1,2**c,[int(order[1]),int(order[2])])
                if res[1] >= 1:
                    answer += '0'
                elif res[0] % 2 == 0:
                    answer += '+'
                else:
                    answer += '-'
        sys.stdout.write(answer)
        _c += 1
except:
    pass
