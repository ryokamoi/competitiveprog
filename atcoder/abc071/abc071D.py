n = input()

l1 = input()
l2 = input()

output = 3
i=0
if l1[0] == l2[0]:
    i = 1
else:
    i = 2
    output *= 2

while True:
    if i >= len(l1):
        break

    if l1[i] == l2[i] and l1[i-1]==l2[i-1]:
        i += 1
        output *= 2
    elif l1[i] == l2[i] and l1[i-1]!=l2[i-1]:
        i += 1
        output *= 1
    elif l1[i] != l2[i] and l1[i-1]==l2[i-1]:
        i += 2
        output *= 2
    elif l1[i] != l2[i] and l1[i-1]!=l2[i-1]:
        i += 2
        output *= 3

print(output)
