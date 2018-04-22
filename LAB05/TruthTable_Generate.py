for i in range(0,8):
    for j in range(0,8):
        print(bin(i+8)[3:],bin(j+8)[3:],bin(i*j+64)[3:])
