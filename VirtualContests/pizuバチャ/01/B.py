def sum(n):
    return (1 + n) * n // 2

a, b = map(int , input().split())

print(sum(b - a) - b)