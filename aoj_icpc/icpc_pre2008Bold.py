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

print(delete)
for i in reversed(delete):
    del ms[i]

while True:
    num = input()
    num = int(num)

    if num == 1:
        break

    outputnum = copy.copy(num)

    divisors = [([], num)]
    for d in ms:
        tmp_d = []
        for div, n in divisors:
            tmp_d.append((div, n))
            if n % d == 0:
                while n % d == 0:
                    n /= d
                tmp_d.append((div+[d], n))
        if len(tmp_d) > 0:
            divisors = tmp_d

    output = []
    for div, res in divisors:
        if res == 1:
            for d in div:
                if d not in output:
                    output.append(d)

    divisors = [str(i) for i in sorted(output)]
    output_str = " ".join(divisors)
    print("%d: %s" % (outputnum, output_str))

