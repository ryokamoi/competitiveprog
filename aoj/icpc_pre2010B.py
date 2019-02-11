d = [[0, -1],
     [0, 1],
     [-1, 0],
     [1, 0]]

INF = 1000000

tile = {"0":0,
        "1":1,
        " ":2}

def idx(i):
    return 2*i

output = []
while True:
    w, h = input().split()
    w = int(w)
    h = int(h)

    if w == 0:
        break

    maze = [[2 for i in range(2*w-1)] for j in range(2*h-1)]
    l = [[INF for i in range(w)] for j in range(h)]
    for j in range(2*h-1):
        row = input()
        for i in range(len(row)):
            maze[j][i] = tile[row[i]]
    
    queue = [(0, 0, 1)]
    while queue:
        x, y, count = queue.pop(0)

        for ud, rl in d:
            xxt = idx(x)+ud
            yyt = idx(y)+rl
            if xxt>=0 and xxt<w*2-1 and yyt>=0 and yyt<h*2-1:
                if maze[yyt][xxt] == 0:
                    xt = x+ud
                    yt = y+rl
                    if l[yt][xt] > count+1:
                        l[yt][xt] = count+1
                        queue.append((xt, yt, count+1))

    if l[h-1][w-1] == INF:
        output.append(0)
    else:
        output.append(l[h-1][w-1])

for i in output:
    print(i)

