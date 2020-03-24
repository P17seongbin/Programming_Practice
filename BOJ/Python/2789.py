screen = ['C','A','M','B','R','I','D','G','E']

input_text = input()

for t in input_text:
    if not t in screen:
        print(t,end='')
