import math
import time

def factorization(value,prime_table):
    res = []
    for p in prime_table:
        if value < p:
            break
        c = 0
        while value % p == 0:
            value //= p
            c += 1
        res.append(c)
    return res
    

def exp_of_single_prime_component(value,prime):
    res = 0
    while value > 1:
        res += value // prime
        value //= prime
    return res

def EOSPC(value,prime):
    return exp_of_single_prime_component(value,prime)

p_list = []
p_count = []
s,f,m = list(map(int,input().split()))

# Find all prime
for i in range(2,m+1):
    prime = True
    limit = int(math.sqrt(i))+1
    for j in range(2,limit):
        if i % j == 0:
            prime = False
            break
    if prime:
        p_list.append(i)
        c = EOSPC(s+f,i) - EOSPC(s,i) - EOSPC(f,i)
        p_count.append(c)
        if c > 0:
            res = i

start = time.time()
for i in range(m,res,-1):
    fac_i = factorization(i,p_list)
    l = len(fac_i)
    ans = True
    for j in range(l):
        if p_count[j] - fac_i[j] < 0:
            ans = False
            break
    if ans:
        res = i
        break
    
end = time.time()


print(res)

