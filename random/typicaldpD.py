n, d = input().split()
n = int(n)
d = int(d)

dp = [[0 for _ in range(6**n+1)] for _ in range(n+1)]
dp[0][1] = 1

for i in range(n):
    for j in range(6**n, -1, -1):
        if dp[i][j] > 0:
            for k in range(1, 7):
                dp[i+1][j*k] += dp[i][j]

s = 0
dsum = 0

for i, num in enumerate(dp[n]):
    s += num
    if i % d == 0:
        dsum += num

print(dsum/s)

