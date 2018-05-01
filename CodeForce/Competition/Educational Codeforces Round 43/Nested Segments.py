#Failed
def divconq(seq):
    if(len(seq) <= 1):
        return False

    eraser = seq[len(seq)//2]
    skip_index = len(seq)//2

    
    if divconq(seq[:skip_index]) or divconq(seq[skip_index+1:]):
        return True
    else:
        for i in range(skip_index):
            if(seq[i][1] >= eraser[1]):
                print(eraser[2],seq[i][2])
                return True
        for i in range(skip_index+1,len(seq)):
            if(seq[i][1] <= eraser[1]):
                print(seq[i][2],eraser[2])
                return True

n = int(input())


    
seq = []
for i in range(n):
    #seq.append(list(map(int,input().split())))
    seq.append([i,i])
    seq[i].append(i+1)
seq = sorted(seq,key = lambda x : (x[0]))




if not divconq(seq):
    print(-1,-1)
