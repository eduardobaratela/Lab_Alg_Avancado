def backtracking(i, d, rule, senha):
    
    if i == len(rule):
        print(senha)
        return()
    if(rule[i] == '#'):
        for word in d:
            if(word[-1] == '\r'):
                word = word[:-1]
            senha += word
            backtracking(i+1, d, rule, senha)
            senha = senha[:-len(word)]
    elif(rule[i] == '0'):
        for j in range(10):
            senha += str(j)
            backtracking(i+1, d, rule, senha)
            senha = senha[:-1]

    return()

n = input()
while(n):
    print('--')
    n = int(n)    
    d = []
    for i in range(n):
        d.append(input())

    m = int(input())
    for i in range(m):
        rule = input()
        if(rule[-1] == '\r'):
            rule = rule[:-1]
        backtracking(0, d, rule, '')

    try:
    	n = input()	
    except EOFError:
    	break 

