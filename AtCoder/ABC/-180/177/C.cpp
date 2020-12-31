#include <bits/stdc++.h>
using namespace std;
#define int long long int
const double pi = 3.14159265358979;
const int inf = 1e13;
#define setup cin.tie(0); ios::sync_with_stdio(false); cout << setprecision(20) << fixed;
#define db double
#define P pair<int,int>
#define F first
#define S second
#define endl "\n"
#define dtor(deg) (((deg)/360)*2*pi)
#define rtod(rad) (((rad)/2/pi)*360)
#define all(a) a.begin(),a.end()
#define Srep(n) for(int i = 0; i < n; i++)
#define Lrep(i,a,n) for(int i = a; i < n; i++)
#define Brep1st(n) for(int bit = 0; bit < (1 << n); bit++)
#define Brep2nd(n) Srep(n) if(bit >> i & 1)
#define rep2d(n,m) Srep(n) Lrep(j,0,m)
#define RoundUp(a,b) ((a) % (b) ? (a) / (b) + 1 : (a) / (b))
#define vi vector<int>
#define vm vector<mint>
#define vvi vector<vi>
#define vdb vector<db>
#define vb vector<bool>
#define V vector

template <int64_t mod> class modint {
    using ll = int64_t;
public:
    ll x;
    modint(ll x = 0) : x(((x % mod) + mod) % mod) {}
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

using mint = modint<1000000007>;

signed main(){
    setup;
    int n;
    mint sum = 0, ans = 0;
    cin >> n;
    vm a(n);
    Srep(n){
        cin >> a[i];
        sum += a[i];
    }
    Srep(n-1){
        sum -= a[i];
        ans += a[i] * sum;
    }
    cout << ans << endl;
}