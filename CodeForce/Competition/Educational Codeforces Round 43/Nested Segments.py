#Failed
n = int(input())

def divconq(seq):
    if(len(seq) <= 1):
        return False
    
    eraser = seq[0]
    left = []
    l_c = 0
    right  = []
    r_c = 0
    for i in range(1,len(seq)):
        if (seq[i][0] <= eraser[0] and seq[i][1] >= eraser[1]) or (seq[i][0] >= eraser[0] and seq[i][1] <= eraser[1]):
            print(seq[i][2],eraser[2])
            return True
        elif (seq[i][0] < eraser[0]):
            left.append(seq[i])
            left[l_c][1] = min(left[l_c][1],eraser[0])
            l_c += 1
        elif (seq[i][1] > eraser[1]):
            right.append(seq[i])
            right[r_c][0] = max(right[r_c][0],eraser[1])
            r_c += 1
    return divconq(left) or divconq(right)

    
seq = []
for i in range(n):
    seq.append(list(map(int,input().split())))
    seq[i].append(i+1)#Index

if not divconq(seq):
    print(-1,-1)
