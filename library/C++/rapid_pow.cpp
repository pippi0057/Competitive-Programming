/**
 *   高速べき乗 O(log n)
 *   rapid_pow<mod>(n, m)
**/

template<int mod>
int rapid_pow(int x, int n) {
    int ret = 1;
    while (n > 0) {
        if (n & 1) ret = ret * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return ret;
}
