n = int(input())

n *= 0.001

if n < 0.1:
    print("00")
elif n <= 5:
    print(str(int(n * 10)).zfill(2))
elif n <= 30:
    print(int(n + 50))
elif n <= 70:
    print(int((n - 30) / 5 + 80))
else:
    print(89)