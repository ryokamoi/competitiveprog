while True:
    p, q, a, n = input().split()
    p = int(p)
    q = int(q)
    a = int(a)
    n = int(n)

    if p == 0:
        break

    div = []
    for i in range(1, int(q/2) + 1):
        if a % i == 0:
            div.append(i)

    print(div)
    dp = [[[0 for _ in range(int(a*p/q)+1)] \
            for _ in range(n+1)] for _ in range(len(div)+1)]

    for i in range(n+1):
        dp[0][i][0] = 1
        
    for i in range(len(div)):
        for j in range(n):
            for k in range(int(a*p/q)+1):
                if k+div[i] <= a*p/q:
                    dp[i+1][j+1][k+div[i]] = \
                        dp[i][j+1][k+div[i]] + dp[i+1][j][k]

    print(dp)
    print(dp[len(div)][n][int(a*p/q)])

