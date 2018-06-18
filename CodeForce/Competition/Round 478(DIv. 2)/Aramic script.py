def find_aramic(script):
    aramic = []
    if(len(script) < 1):
        return aramic
    aramic.append(script[0])
    aramic_len = 1

    for i in range(1,len(script)):
        if aramic[aramic_len-1] != script[i]:
            aramic.append(script[i])
            aramic_len += 1
    return aramic



n = int(input())

raw_script = list(input().split())
script_list = []

for i in range(n):
    script_list.append(list(raw_script[i]))
    script_list[i].sort()
    script_list[i] = find_aramic(script_list[i])

script_list.sort()
aramic_count = 1
last_aramic = 0
for i in range(1,n):
    if script_list[i] != script_list[last_aramic]:
        aramic_count += 1
        last_aramic = i

print(aramic_count)
