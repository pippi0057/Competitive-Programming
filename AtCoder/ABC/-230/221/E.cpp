#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define ll long long int
#define u32 unsigned int
#define u64 unsigned long long int
#define F function
constexpr ll inf = 1e17;
constexpr int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
constexpr int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
#define pii pair<int,int>
#define pll pair<ll,ll>
#define endl "\n"
#define Auto const auto
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
#define vv(type,name,size,...) vector<vector<type>> name(size,vector<type>(__VA_ARGS__))
template <class T> inline bool chmin(T& a, T b){ if(a > b){ a = b; return 1; } return 0; }
template <class T> inline bool chmax(T& a, T b){ if(a < b){ a = b; return 1; } return 0; }
struct Edge { int to; ll cost; Edge(int to, ll cost) : to(to), cost(cost) {} };
using Graph = vector<vector<Edge>>;
template<class T> istream& operator>>(istream& is, vector<T>& a){ for(auto& x : a) is >> x; return is; }
template<class T> void operator+=(vector<T>& a, T b){ a.push_back(b); return; }
template<class T> istream& operator>>(istream& is, set<T>& a){ T input; is >> input; a.insert(input); return is; }
struct sorted_impl{
    template<class T> friend vector<T> operator|(vector<T> a, sorted_impl){ sort(all(a)); return a; }
    template<class T> friend void operator|=(vector<T>& a, sorted_impl){ sort(all(a)); }
} sorted;
struct reversed_impl{
    template<class T> friend vector<T> operator|(vector<T> a, reversed_impl){ reverse(all(a)); return a; }
    template<class T> friend void operator|=(vector<T>& a, reversed_impl){ reverse(all(a)); }
} reversed;

using mint = modint998244353;
 
ll mow(ll x, ll n){ ll ret = 1; while(n > 0){ if(n & 1) ret = ret * x; x = x * x; n >>= 1; } return ret; }
ll mow(ll x, ll n, ll mod){ ll ret = 1; while(n > 0){ if(n & 1) ret = ret * x % mod; x = x * x % mod; n >>= 1; } return ret; }

template <class T> struct BIT{
    int n; vector<T> bit;
    BIT(int n){ this->n = n; bit.resize(n, 0); }
    BIT(vector<T> v) : BIT(v.size()) { rep(v.size()) add(i, v[i]); }
    inline void add(int i, T x){ for(; i < n; i = i | (i + 1)) bit[i] += x; }
    inline T sum(int i){
        T res = 0; i--;
        for(; i >= 0; i = (i & (i + 1)) - 1) res += bit[i];
        return res;
    }
};

void Main(){
    int n; mint ans = 0;
    cin >> n;
    vector a(n, 0);
    map<int, vector<int>> b;
    map<int, int> link;
    { int i = 0; for(auto& x : a){
        cin >> x;
        b[x] += i;
    i++; }}
    vector<mint> data(b.size());
    BIT<mint> bit(b.size());
    { int i = 0; mint cur = 0; for(auto itr = prev(b.end()); ; itr--){
        link[itr->first] = i;
        data[i] += cur;
        for(Auto& x : itr->second) data[i] += mow(2, x, 998244353);
        cur = data[i];
        if(itr == b.begin()) break;
    i++; }}
    rep(n - 1){
        bit.add(link[a[i]], mint(mow(2, i, 998244353)));
        ans += (data[link[a[i]]] - bit.sum(link[a[i]] + 1)) / mow(2, i + 1, 998244353);
    }
    cout << ans.val() << endl;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << setprecision(10) << fixed;
    Main();
}