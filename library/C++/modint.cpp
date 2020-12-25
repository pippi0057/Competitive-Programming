template <int64_t mod> class modint{
    using ll = int64_t;
public:
    ll x;
    modint(ll x = 0) : x((x % mod + mod) % mod) {}
    modint& operator+(const modint& y) { return modint(*this) += y; }
    modint& operator-(const modint& y) { return modint(*this) -= y; }
    modint& operator*(const modint& y) { return modint(*this) *= y; }
    modint& operator/(const modint& y) { return modint(*this) /= y; }
    modint& operator+=(const modint& y){
        x += y.x;
        if(x >= mod) x -= mod;
        return *this;
    }
    modint& operator-=(const modint& y){
        if(x < y.x) x += mod;
        x -= y.x;
        return *this;
    }
    modint& operator*=(const modint& y){
        x = x * y.x % mod;
        return *this;
    }
    modint& operator/=(const modint& y){
        return (*this) *= y.inv();
    }
    modint inv() { return pow(mod - 2); }
    modint pow(ll y){
        if(!y) return 1;
        ll ret = 1;
        while(y > 0){
            if(y & 1) ret = ret * x % mod;
            x = x * x % mod;
            y >>= 1;
        }
        return ret;
    }
};