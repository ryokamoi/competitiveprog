def average(points):
    sum = 0
    for i in points:
        sum += i
    return sum / len(points)

outputs = []

while True:
    num = int(input())
    if num == 0:
        break

    points = []
    for _ in range(num):
        point = int(input())
        points.append(point)

    points = sorted(points)
    points = points[1:len(points)-1]

    ave = average(points)
    outputs.append(int(ave))

for ave in outputs:
    print(ave)


