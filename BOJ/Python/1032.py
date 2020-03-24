n = int(input())

text_list = []
res = ''

for i in range(n):
    text_list.append(input())

l = len(text_list[0])

for i in range(l):
    dif = False
    for j in range(n-1):
        if text_list[j][i] != text_list[j+1][i]:
            res += '?'
            dif = True
            break
    if not dif:
        res += text_list[0][i]
print(res)
        
    
