def cal_delta(value,target):
    origin = 0
    for i in value:
        origin *= 36
        origin += i
    shifted = 0
    for i in value:
        shifted *= 36
        if i == target:
            shifted += 35
        else:
            shifted += i
    return shifted - origin

def dec_to_36(v):
    res = []
    while v >= 36:
        res.append(v % 36)
        v //= 36
    res.append(v)
    res = [_36_to_char(x) for x in reversed(res)]
    return res
        
def _36_to_dec(value):
    origin = 0
    for i in value:
        origin *= 36
        origin += i
    return origin

def _36_to_char(c):
    if 0 <= c and c <= 9:
        return chr(ord('0')+c)
    else:
        return chr(ord('A')+c-10)
    
def char_to_36(c):
    v = ord(c)
    if ord('0') <= v and v <= ord('9'):
        return v - ord('0')
    else:
        return v - ord('A') + 10

n = int(input())
value_list = []
origin_sum = 0
for i in range(n):
    t = list(input())
    t_36 = [char_to_36(x) for x in t]
    value_list.append(t_36)
    origin_sum += _36_to_dec(t_36)
    
delta_list = []
for i in range(36):
    d = 0
    for j in range(n):
        d += cal_delta(value_list[j],i)
    delta_list.append(d)

delta_list.sort(reverse=True)

k = int(input())
for i in range(k):
    origin_sum += delta_list[i]

res = dec_to_36(origin_sum)
for i in res:
    print(i,end='')   
        
        

        
