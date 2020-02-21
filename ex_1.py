def yesno(str):

    stack = []

    for i in str:
        if(i == '('):
            stack.append(i)
        elif not stack:
            return('NO')
            exit()
        else:
            stack.pop()

    if not stack:
        return("YES")
    else:
        return("NO")

str = input()
print(yesno(str))