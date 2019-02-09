h, w = input().split()
h = int(h)
w = int(w)

n = input()
n = int(n)

an = input().split()
an = [int(a) for a in an]

field = [[0 for _ in range(w)] for _ in range(h)]

k = 0
for i in range(h):
    for j in range(w):
        if i % 2 != 0:
            j = -j - 1
        if an[k] > 0:
            pass
        else:
            k += 1
        an[k] -= 1
        field[i][j] = k+1

for i in range(h):
    output = [str(c) for c in field[i]]
    print(" ".join(output))

