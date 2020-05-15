M = int(input())

for m in range(M):
    w = []
    w.append(0)
    total = 0
    line = input().split()
 
    for val in line:
        w.append(int(val))
        total += int(val)

    if total % 2 == 1:
        print("NO")
    else:
        dp = [[0 for col in range(len(w))] for row in range(total+1)]

        for i in range(1, total+1):
            for j in range(1, len(w)):
                if(i >= w[j]):
                    dp[i][j] = max(dp[i][j-1], dp[i-w[j]][j-1] + w[j])
                else:
                    dp[i][j] = dp[i][j-1]
        
        if(dp[int(total/2)][len(w)-1] == total/2):
            print("YES")
        else:
            print("NO")