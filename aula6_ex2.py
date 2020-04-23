def findgcd(x, y):
    if x % y == 0:
        return(y)
    return findgcd(y, x%y)


n = int(input())

for i in range(n):
    m = input().split()
    gcd = 0
    size = len(m)
    for j in range(size-1):
        for k in range(j+1,size):
            gcd = max(gcd, findgcd(int(m[j]), int(m[k])))
    print(gcd)