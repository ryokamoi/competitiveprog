a = input()

alpha = [chr(i) for i in range(97, 97+26)]

flag = True;
for c in alpha:
    if c not in a:
        print(c)
        flag = False
        break

if flag:
    print("None")
