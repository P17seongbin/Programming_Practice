n = int(input())
words = []
weights = {}
for i in range(n):
  words.append(input()[::-1])

for i in range(n):
  l = len(words[i])
  weight = 1
  for j in range(l):
    t = words[i][j]
    if t in weights:
      v = weights[t]
      weights[t] = v + weight
    else: 
      weights[t] = weight
    weight *= 10

res_weight = list(weights.values())
res_weight.sort(reverse=True)
res = 0

for i in range(len(res_weight)):
  res += res_weight[i] * (9-i)
print(res)
