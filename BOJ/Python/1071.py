# 1071
# P) N개의 정수가 주어지면, 이것을 연속된 두
#    수가 연속된 값이 아니게 정렬(A[i] + 1 ≠ A[i+1])하는 프로그램을 작성하시오.
#    가능한 것이 여러 가지라면 사전순으로 가장 앞서는 것을 출력한다.
# I) 첫째 줄에 N이 주어진다. N은 50보다 작거나 같은 자연수이다.
#    둘째 줄에는 N개의 수가 주어진다. N개의 수는 1,000보다 작거나 같은 자연수 또는 0이다.


# O(n^2) 까지 허용된다.
# 입력을 한번 정렬(n log n)한 뒤 규칙에 따라 재정렬(n)하면 된다

n = int(input())
v = list(map(int,input().split()))
v.sort()


#연속된 두 숫자: 1 2 -> 2 1
#연속된 세 숫자: 1 2 n -> 1 n 2 (n > 2)
#연속된 네 숫자의 경우 연속된 세 숫자가 있는 것으로 취급하면 된다(1 2 3 4-> 1 3 2 4)
# 연속된 두 숫자인 경우 중복된 숫자는 하나로 취급한다
# 연속된 세 숫자인 경우 마지막 숫자를 제외하고, 중복된 숫자를 하나로 취급한다.

#중복된 값의 처음 위치
pos = 0
for i in range(n-1):
    # 중복 구간이 끝난 경우, pos를 갱신해준다
    if not v[pos] == v[i]:
        pos = i
    # 연속 구간 감지
    if v[pos] + 1 == v[i+1]:
        triseq = False
        d = 1
        while i+d < n-1:
            if v[i+d] == v[i+d+1]:
                d += 1
            elif v[i+d] < v[i+d+1]:
                triseq = True
                break
            else:
                break
        #print(v,triseq,i,d)
        if triseq:
            t = v[i+1]
            v[i+1] = v[i+d+1]
            v[i+d+1] = t
        else:
            t = v[pos]
            v[pos] = v[i+1]
            v[i+1] = t
            pos += 1
            
        
# 중복된 값이 분할된 경우, 최대한 작은 순서로 변환해주는 작업
# 중복된 값 뒤에 작은 값이 있으면
for i in range(n):
    print(v[i],end=' ')




