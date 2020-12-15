import math
def is_prime(n):
    if(n < 2):
        return False
    elif n == 2:
        return True
    elif n % 2 == 0:
        return False
    for i in range(3, math.ceil(n ** 0.5), 2):
        if(n % i == 0):
            return False
    return True