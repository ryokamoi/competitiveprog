import math
import copy

def divisor(num):
    output = []
    for d in range(2, int(num/2)+1):
       if num % d == 0:
           output.append(d)
    output.append(num)
    return output

def build_net(me, you):
    output = []
    for i, l in enumerate(you):
        for num in me:
            if num in l:
                output.append(i)
                break
    return sorted(output)

while True:
    m, n = input().split()
    m = int(m)
    n = int(n)

    if m == 0:
        break

    b = []
    r = []
    for _ in range(math.ceil(m/10)):
        bt = input().split()
        b.extend([int(i) for i in bt])
    for _ in range(math.ceil(n/10)):
        rt = input().split()
        r.extend([int(i) for i in rt])

    bd = []
    rd = []
    for num in b:
        bd.append(divisor(num))
    for num in r:
        rd.append(divisor(num))

    bnet = []
    rnet = []
    for divisors in bd:
        bnet.append(build_net(divisors, rd))
    for divisors in rd:
        rnet.append(build_net(divisors, bd))

    max_matching = 0
    queue = [([], [])]
    while len(queue > 0):
        queue = [([i],[],[])]
        while len(queue > 0):
            bv, rv, matching = queue.pop(0)
            if len(matching[0]) > max_matching:
                max_matching = len(matching)
            
            tbq = []
            for bn in bnet[bv[-1]]:
                if (bn in matching[1]) and (bn not in bv):
                    tbq.append(copy(bv).append(bn))

            for bvt in tbq:
                for bn in bnet[matching[]]

