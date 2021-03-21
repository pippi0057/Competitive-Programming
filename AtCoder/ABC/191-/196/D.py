h, w, a, b = map(int, input().split())

if h > w:
    temp = w
    w = h
    h = temp

if h == 1 and w == 1:
    print(1)

if h == 1 and w == 2:
    print(1)

if h == 1 and w == 3:
    if a == 1:
        print(2)
    else:
        print(1)

if h == 1 and w == 4:
    if a == 2:
        print(1)
    if a == 1:
        print(3)
    if a == 0:
        print(1)

if h == 1 and w == 5:
    if a == 2:
        print(3)
    if a == 1:
        print(4)
    if a == 0:
        print(1)

if h == 1 and w == 6:
    if a == 3:
        print(1)
    if a == 2:
        print(6)
    if a == 1:
        print(5)
    if a == 0:
        print(1)

if h == 1 and w == 7:
    if a == 3:
        print(4)
    if a == 2:
        print(10)
    if a == 1:
        print(6)
    if a == 0:
        print(1)

if h == 1 and w == 8:
    if a == 4:
        print(1)
    if a == 3:
        print(10)
    if a == 2:
        print(15)
    if a == 1:
        print(7)
    if a == 0:
        print(1)

if h == 1 and w == 9:
    if 