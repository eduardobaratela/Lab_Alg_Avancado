def canSort(a, v, n):
    for i in range(n-1):
        if v[i] == '0':
            for j in range(i+1, n):
                if int(a[j]) < int(a[i]):
                    return False
    return True

a = input().split()
v = input()
n = int(input())
canSort(a, v, n)
