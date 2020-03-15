global field


def find_path(y,x,r,c,l): #from(x,y) to (r,c)

    if y == r && x == c:
        field[(y,x)] = 1
    elif (y == r && x != c) || (y != r && x == c):
        field[(y,x)] = 0
    else:
        #한칸 아래로, 두칸 옆으로
        if y + 1 <= r && x + 2 <= c:
            if (y+1,x+2) not in field:
                field[(y+1,x+2)] = find_path(y+1,x+2,r,c,l+1)
        #두칸 아래로, 한칸 옆으로
        if x + 1 <= c && y + 2 <= r:
            if (y+2,x+1) not in field:
                field[(y+2,x+1)] = find_path(y+2,x+1,r,c,l+1)
        field[(y,x)] = field[(y+1,x+2)] + field[(y+2,x+1)]
    return field[(y,x)]

field = {(-1,-1):0}

r,c = map(int,input().split(' '))

print(

    
