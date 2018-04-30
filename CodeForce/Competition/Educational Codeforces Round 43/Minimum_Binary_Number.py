digit_len = int(input())

digit = input()

#Count the number of 0 and 1

count_zero = 0
count_one = 0

for i in range(len(digit)):
    if digit[i] == '0':
        count_zero += 1
    else:
        count_one += 1

if count_zero == 1 and count_one == 0:
    print(0)
else:
    print(1,end='')
    for i in range(count_zero):
        print(0,end='')
