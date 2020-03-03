max_val = []

def find_max(eq, n):
    if n == 1:
        return int(eq)
    elif n == 3:
        return cal_single(int(eq[0]),eq[1],int(eq[2]))
    else:
        v1 = cal_single(int(eq[0]),eq[1],find_max(eq[2:],n-2))
        v2_t = cal_single(int(eq[0]),eq[1],int(eq[2]))
        v2 = cal_single(v2_t,eq[3],find_max(eq[4:],n-4))
        print(n,v1,v2)
        return v1 if v1 > v2 else v2
        
def cal_single(lv,op,rv):
    if op == '+':
        return lv+rv
    elif op == '-':
        return lv-rv
    else:
        return lv*rv

n = int(input())
raw_eq = input()
print(find_max(raw_eq,n))
