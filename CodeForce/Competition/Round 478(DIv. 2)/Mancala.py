init_stone = list(map(int,input().split()))

max_score = -1

for i in range(14):
    released = init_stone[i] // 14
    leftover = init_stone[i] % 14
    res_stone = list(init_stone)
    res_stone[i] = 0
    for j in range(1,leftover+1):
        res_stone[(i+j) % 14] += 1
    score = 0

    for j in range(14):
        if (res_stone[j] + released) % 2 == 0:
            score += (res_stone[j] + released)
    if max_score < score:
        max_score = score

print(max_score)
