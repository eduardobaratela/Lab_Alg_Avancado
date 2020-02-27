n = int(input())
while(n != 0):

    d = {}
    maxN = 1

    for i in range(n):
        course = input().split()
        course.sort()
        str = ''.join(course)

        if str not in d:
            d[str] = 1
        else:
            d[str] += 1
            maxN = max(d[str], maxN)

    if maxN == 1:
        print(n)
    else:
        cont = 0
        for res in d.values():
            if res == maxN:
                cont += 1
        print(cont*maxN)

    n = int(input())