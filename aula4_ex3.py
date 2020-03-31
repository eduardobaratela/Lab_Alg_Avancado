def quebraPalavra(d, s, n, frase):
    for i in range(1,n+1):
        sub = s[:i]
        #print(sub)
        if sub in d:
            if i == n:
                frase += sub
                print(frase)
                return()
            quebraPalavra(d, s[i:n-1+1], n-i, frase + sub + ' ')


d = []
n = int(input())
for i in range(n):
    st = input()
    if(st[-1] == '\r'):
        st = st[:-1]
    d.append(st)

t = int(input())
for i in range(t):
    s = input()
    if(s[-1] == '\r'):
        s = s[:-1]
    quebraPalavra(d, s, len(s), '')
    if i!= t-1:
        print()