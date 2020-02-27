n = int(input())
a = input().split()
qtd = 0
d = {}

for cur in a:
    if cur not in d:
        qtd += 1
        d[cur] = 1

print(qtd)