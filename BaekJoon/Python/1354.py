#Divide & Conquer

global cache
def find(n,p,q,x,y):

    if(n <= 0):
        return 1
    else:
        c = 0
        if n // p - x in cache:
            c = c + cache.get(n // p - x)
        else:
            cache[n // p - x] = find(n // p - x, p , q,x,y)
            c = c + cache.get(n // p - x)
        if n // q - y in cache:
            c = c + cache.get(n // q - y)
        else:
            cache[n // q - y] = find(n // q - y, p , q,x,y)
            c = c + cache.get(n // q - y)
        return c

cache = {0: 1}
n,p,q,x,y = map(int,input().split(" "))
print(find(n,p,q,x,y))
