n = int(input())

ans = 0

for _ in range(n):
    a, b = map(int, input().split())
    ans += (a + b) * (b - a + 1) // 2

print(ans)