n = int(input())
ans = 1
now = 2

for _ in range(n):
    s = input()
    if s == "OR":
        ans += now
    now *= 2

print(ans)