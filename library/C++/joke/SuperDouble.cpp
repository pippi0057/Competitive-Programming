struct SuperDouble{
    long double x;
    const long double EPS = 1e-10; // 10^6
    // const long double EPS = 1e-14; // 10^9
    int sgn(const double a){ return a < -EPS ? -1 : a > EPS ? 1 : 0; }
    constexpr SuperDouble() : x(0.0) {}
    constexpr SuperDouble(long double x) : x(x) {}
    constexpr SuperDouble operator +(const SuperDouble& other) const{ return x + other.x; }
    constexpr SuperDouble operator -(const SuperDouble& other) const{ return x - other.x; }
    constexpr SuperDouble operator *(const SuperDouble& other) const{ return x * other.x; }
    constexpr SuperDouble operator /(const SuperDouble& other) const{ return x / other.x; }
    constexpr SuperDouble operator +(const double& other) const{ return x + other; }
    constexpr SuperDouble operator -(const double& other) const{ return x - other; }
    constexpr SuperDouble operator *(const double& other) const{ return x * other; }
    constexpr SuperDouble operator /(const double& other) const{ return x / other; }
    constexpr SuperDouble operator +(const long double& other) const{ return x + other; }
    constexpr SuperDouble operator -(const long double& other) const{ return x - other; }
    constexpr SuperDouble operator *(const long double& other) const{ return x * other; }
    constexpr SuperDouble operator /(const long double& other) const{ return x / other; }
    constexpr SuperDouble operator +() const{ return x; }
    constexpr SuperDouble operator -() const{ return -1.0 * x; }
    SuperDouble& operator +=(const SuperDouble& other) { x += other.x; return *this; }
    SuperDouble& operator -=(const SuperDouble& other) { x -= other.x; return *this; }
    SuperDouble& operator *=(const SuperDouble& other) { x *= other.x; return *this; }
    SuperDouble& operator /=(const SuperDouble& other) { x /= other.x; return *this; }
    SuperDouble& operator +=(const double& other) { x += other; return *this; }
    SuperDouble& operator -=(const double& other) { x -= other; return *this; }
    SuperDouble& operator *=(const double& other) { x *= other; return *this; }
    SuperDouble& operator /=(const double& other) { x /= other; return *this; }
    SuperDouble& operator +=(const long double& other) { x += other; return *this; }
    SuperDouble& operator -=(const long double& other) { x -= other; return *this; }
    SuperDouble& operator *=(const long double& other) { x *= other; return *this; }
    SuperDouble& operator /=(const long double& other) { x /= other; return *this; }
    inline bool operator ==(SuperDouble other) { return !sgn(x - other.x); }
    inline bool operator <(SuperDouble other) { if(sgn(other.x - x) == 1) return 1; return 0; }
    inline bool operator <=(SuperDouble other) { return *this == other || *this < other; }
    inline bool operator >(SuperDouble other) { return !(*this <= other); }
    inline bool operator >=(SuperDouble other) { return !(*this < other); }
    inline bool operator !=(SuperDouble other) { return !(*this == other); }
    constexpr operator long double&() { return x; }
    friend ostream& operator <<(ostream& os, const SuperDouble& out) { return os << out.x; }
    friend istream& operator >>(istream& is, SuperDouble& in) { return is >> in.x; }
    constexpr SuperDouble Sqrt() { return (SuperDouble)(sqrt(x)); }
};

/**
 * ABC189-B Alcoholic 
 * https://atcoder.jp/contests/abc189/submissions/23853361
 *
 * panasonic2020-C Sqrt Inequality
 * https://atcoder.jp/contests/panasonic2020/submissions/23853138
**/
