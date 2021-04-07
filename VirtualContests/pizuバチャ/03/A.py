n = int(input())
s = input()

a = 0
b = 0

for i in s:
    if(i == 'R'):
        a += 1
    else:
        b += 1

if a > b:
    print("Yes")
else:
    print("No")