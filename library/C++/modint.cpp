template <int64_t mod> class modint {
    using ll = int64_t;
public:
    ll x;
    modint(ll x = 0) : x((x % mod + mod) % mod) {}
    modint operator+(const modint& y) { return modint(*this) += y; }
    modint operator-(const modint& y) { return modint(*this) -= y; }
    modint operator*(const modint& y) { return modint(*this) *= y; }
    modint operator/(const modint& y) { return modint(*this) /= y; }
    modint operator+=(const modint& y) {
        x += y.x;
        if (x >= mod) x -= mod;
        return *this;
    }
    modint& operator-=(const modint& y) {
        if (x < y.x) x += mod;
        x -= y.x;
        if(x >= mod) x -= mod;
        return *this;
    }
    modint& operator*=(const modint& y) {
        x = x * y.x % mod;
        return *this;
    }
    modint& operator/=(const modint& y) {
        modint y_t = y;
        return *this = y_t.inv(*this);
    }
    friend ostream& operator << (ostream& os, const modint<mod>& modout) {
        return os << modout.x;
    }
    friend istream& operator >> (istream& is, modint<mod>& modin) {
        ll temp;
        is >> temp;
        modin.x = temp;
        return is;
    }
    modint inv(modint& ret) { return pow(mod - 2, ret); }
    modint pow(ll y, modint& ret) {
        if (!y) return 1;

        while (y > 0) {
            if (y & 1) ret.x = ret.x * x % mod;
            x = x * x % mod;
            y >>= 1;
        }
        return ret;
    }
};