#http://codeforces.com/problemset/problem/337/A (solved by Sorting)


n,m = map(int,input().split())

puzzle = list(map(int,input().split()))
puzzle.sort()

least_diff = puzzle[len(puzzle)-1] - puzzle[0]


for i in range(m-n+1):
    if puzzle[i+n-1] - puzzle[i] < least_diff:
        least_diff= puzzle[i+n-1] - puzzle[i]

print(least_diff)
    
