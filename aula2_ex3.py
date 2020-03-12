def gcd(a, b):
    while b > 0:
        a, b = b, a % b
    return a

d = {}
inp = input().split()
while(inp[0] != '#'):
    d[inp[1]] = int(inp[2])
    inp = input().split()

val = list(d.values())
keys = list(d.keys())

result = val[0]
for i in val[1:]:
    result = gcd(result, i)

n = int(input())
time = 0
i = 0
while(i<n):
    time += result
    for x in val:
        if time % x == 0:
            i +=1
            print(keys[val.index(x)])