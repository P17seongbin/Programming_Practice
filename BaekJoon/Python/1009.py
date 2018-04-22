for i in range(0,8):
    for j in range(0,8):
        A = str(bin(i+8))
        B = str(bin(j+8))
        O = str(bin(i*j+64))
        for k in range(3,6):
            print(A[k],end=" ")
        for k in range(3,6):
            print(B[k],end=" ")
        for k in range(3,9):
            if O[k] == '0':
                print ('L', end = " ")
            else:
                print('H',end = " ")
        print("")
