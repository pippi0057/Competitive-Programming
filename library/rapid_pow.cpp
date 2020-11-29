int rapid_pow(int x, int n) {
    int ret = 1;
    while (n > 0) {
        if (n & 1) ret = ret * x;
        x = x * x;
        n >>= 1;
    }
    return ret;
}