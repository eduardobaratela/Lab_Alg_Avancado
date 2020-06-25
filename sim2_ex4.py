def check(mid):
    times = 0
    for i in range(n):
        if a[i] > mid*q :
            times += int((a[i] - mid*q) / (p-q) + ((a[i]-mid*q) % (p-q) != 0))
    if times <= mid:
        return(True)

    return(False)

n, p, q = map(int, input().split())
a = list(map(int, input().split()))
left = 1
right = max(a)
ans = right

if p == q:
    ans = int(right / p)
    if right % p:
        ans +=1
    print(ans)
else:
    while left <= right:
        mid = int((left+right)/2)
        if check(mid):
            right = mid -1
            ans = mid
        else:
            left = mid + 1 
    print(ans)