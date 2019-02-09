import copy
import math

ms = []
for i in range(1, int(300000/7)+1):
    ms.append(i*7-1)
    ms.append(i*7+1)

delete = []
for i, n in enumerate(ms):
    for j, m in enumerate(ms[:int(math.sqrt(len(ms)))+1]):
        if j < i and n % m == 0:
            delete.append(i)
            break

for i in reversed(delete):
    del ms[i]

while True:
    num = input()
    num = int(num)

    if num == 1:
        break

    divisors = []
    for d in ms:
        if num % d == 0:
            divisors.append(str(d))

    output_str = " ".join(divisors)
    print("%d: %s" % (num, output_str))

