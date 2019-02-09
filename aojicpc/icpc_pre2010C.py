INF = 1000000

while True:
    n = input()
    n = int(n)

    if n == 0:
        break

    i = 1
    tetra = []
    while True:
        t = i*(1+i)*(2+i)/6
        if t <= n:
            tetra.append(int(t))
            i += 1
        else:
            break

    dp1 = [INF for _ in range(n+1)]
    dp2 = [INF for _ in range(n+1)]
    dp1[0] = 0
    dp2[0] = 0

    for i in range(n):
        for j in range(len(tetra)):
            if i + tetra[j] <= n:
                dp1[i+tetra[j]] = min(dp1[i+tetra[j]], dp1[i]+1)
                if tetra[j] % 2 == 1:
                    dp2[i+tetra[j]] = min(dp2[i+tetra[j]], dp2[i]+1)
    
    print("%d %d" % (dp1[n], dp2[n]))

