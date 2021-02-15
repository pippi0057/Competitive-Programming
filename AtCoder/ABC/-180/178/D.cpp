#include <bits/stdc++.h>
using namespace std;
#define int long long int
const double pi = 3.14159265358979;
const int inf = 1e13;
vector<int> dx = {0, 1, 0, -1, 1, 1, -1, -1};
vector<int> dy = {1, 0, -1, 0, 1, -1, 1, -1};
#define pii pair<int,int>
#define endl "\n"
#define dtor(deg) (((deg)/360)*2*pi)
#define all(a) a.begin(),a.end()
#define overload(_1,_2,_3,_4,name,...) name
#define _rep1(n) for(int i = 0; i < (n); i++)
#define _rep2(i,n) for(int i = 0; i < (n); i++)
#define _rep3(i,a,b) for(int i = (a); i < (b); i++)
#define _rep4(i,a,b,c) for(int i = (a); i < (b); i += (c))
#define rep(...) overload(__VA_ARGS__,_rep4,_rep3,_rep2,_rep1)(__VA_ARGS__)
#define _rrep1(n) for(int i = (n) - 1; i >= 0; i--)
#define _rrep2(i,n) for(int i = (n) - 1; i >= 0; i--)
#define _rrep3(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define _rrep4(i,a,b,c) for(int i = (b) - 1; i >= (a); i -= (c))
#define rrep(...) overload(__VA_ARGS__,_rrep4,_rrep3,_rrep2,_rrep1)(__VA_ARGS__)
#define vec(type,name,...) vector<type> name(__VA_ARGS__)
#define vv(type,name,size,...) vector<vector<type>> name(size,vector<type>(__VA_ARGS__))
#define ForEach(a,b) for_each(a.begin(),a.end(),b)
struct Edge { int to, cost; Edge(int to, int cost) : to(to), cost(cost) {} };
using Graph = vector<vector<Edge>>;
template <class T> bool chmin(T& a, T b){ if(a > b){ a = b; return 1; } return 0; }
template <class T> bool chmax(T& a, T b){ if(a < b){ a = b; return 1; } return 0; }

template <int64_t mod> class modint {
    using ll = int64_t;
public:
    ll x;
    modint(ll x = 0) : x((x % mod + mod) % mod) {}
    modint operator + (const modint& y) { return modint(*this) += y; }
    modint operator - (const modint& y) { return modint(*this) -= y; }
    modint operator * (const modint& y) { return modint(*this) *= y; }
    modint operator / (const modint& y) { return modint(*this) /= y; }
    modint operator += (const modint& y) {
        x += y.x;
        if (x >= mod) x -= mod;
        return *this;
    }
    modint& operator -= (const modint& y) {
        if (x < y.x) x += mod;
        x -= y.x;
        if(x >= mod) x -= mod;
        return *this;
    }
    modint& operator *= (const modint& y) {
        x = x * y.x % mod;
        return *this;
    }
    modint& operator /= (const modint& y) {
        modint y_t = y;
        return *this = y_t.inv(*this);
    }
    friend ostream& operator << (ostream& os, const modint<mod>& modout) {
        return os << modout.x;
    }
    friend istream& operator >> (istream& is, modint<mod>& modin) {
        ll temp;
        is >> temp;
        temp = (temp % mod + mod) % mod;
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

void Main(){
    int n;
    cin >> n;
    vector<mint> dp(2100);
    dp[3] = 1;
    dp[4] = 1;
    dp[5] = 1;
    rep(i,6,2100) dp[i] = dp[i-1] + dp[i-3];
    cout << dp[n] << endl;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    Main();
}