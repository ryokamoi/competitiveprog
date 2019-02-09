n = input()
n = int(n)

an = input().split()
an = [int(a) for a in an]

two = 0
four = 0
odd = 0

for a in an:
    if a % 2 != 0:
        odd += 1
    elif a % 4 == 0:
        four += 1
    else:
        two += 1

if odd + four == n and odd-1 == four:
    print("Yes")
elif odd <= four:
    print("Yes")
else:
    print("No")
