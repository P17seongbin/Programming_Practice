    class field:
        def init(self,x,y):
            self.f = [[0 for i in range(y)] for j in range(x)]
            self.x = x
            self.y = y

        def set_1(self,x,y):
            self.f[x][y] = 1

        def mark_single_area(self,x,y):
            if self.x <= x or x < 0:
                return False
            if self.y <= y or y < 0:
                return False
            d = [(0,1),(1,0),(-1,0),(0,-1)]
            
            if self.f[x][y] == 1:
                self.f[x][y] = 2
                search_queue = [(x,y)]
                while search_queue:
                    pos = search_queue[0]
                    for i in range(4):
                        tx = pos[0] + d[i][0]
                        ty = pos[1] + d[i][1]
                        if self.is_1(tx,ty):
                            search_queue.append((tx,ty))
                            self.f[tx][ty] = 2
                    del search_queue[0]
                return True
            else:
                return False

        def is_1(self,x,y):
            if self.x <= x or x < 0:
                return False
            elif self.y <= y or y < 0:
                return False
            else:
                return self.f[x][y] == 1
            
    def solve():
        m,n,k = list(map(int,input().split(' ')))
        min_bugs = 0;
        f = field()
        f.init(m,n)

        for i in range(k):
            x,y = list(map(int,input().split(' ')))
            f.set_1(x,y)

        for i in range(m):
            for j in range(n):
                if f.mark_single_area(i,j):
                    min_bugs += 1

        print(min_bugs)
        
            
        

    t = int(input())

    for i in range(t):
        solve()
