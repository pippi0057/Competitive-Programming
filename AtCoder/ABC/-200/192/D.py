def ok(x, m, a):
    res = 0
    cnt = 0
    for i in reversed(x):
        if res > m:
            return False
        if a ** cnt > m:
            return False
        res += (a ** cnt) * int(i)
        cnt += 1
    return res <= m

x = input()
m = int(input())

d = 0
r = 1000000000000000000

for i in x:
    d = max(d, int(i))

l = d + 1

while r - l > 1:
    mid = (l + r) // 2
    if ok(x, m, mid):
        l = mid
    else:
        r = mid

if ok(x, m, r):
    print(r - d)
else:
    print(l - d)