n = input()
n = int(n)

pn = input().split()
pn = [int(p) for p in pn]
s = sum(pn)

dp = [0 for _ in range(s+1)]
dp[0] = 1

for j in range(1, n+1):
    for i in range(s, -1, -1):
        if dp[i]:
            dp[i+pn[j-1]] = 1

s = 0
for i in dp:
    s += i

print(s)
