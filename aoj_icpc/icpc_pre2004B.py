c = {"#":0,
     "@":1,
     ".":2,
     "*":3}

d = [[0, -1],
     [0, 1],
     [-1, 0],
     [1, 0]]

output = []
while True:
    w, h = input().split()
    w = int(w)
    h = int(h)

    if w == 0:
        break

    tiles = [[0 for i in range(w)] for j in range(h)]
    for i in range(h):
        row = input()
        for j in range(w):
            tiles[i][j] = c[row[j]]
            if tiles[i][j] == 1:
                queue = [(j, i)]

    count = 1
    while queue:
        x, y = queue[0]
        queue.pop(0)

        for ud, rl in d:
            xt = x+ud
            yt = y+rl
            if xt >= 0 and xt <= w-1 and yt >= 0 and yt <= h-1:
                if tiles[yt][xt] == 2:
                    tiles[yt][xt] = 3
                    count += 1
                    queue.append((xt, yt))

    output.append(count)

for num in output:
    print(num)
