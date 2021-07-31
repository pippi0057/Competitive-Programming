#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define ll int64_t
#define u32 uint32_t
#define u64 uint64_t
constexpr ll inf = 1e17;
constexpr int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
constexpr int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
#define pii pair<int,int>
#define pll pair<ll,ll>
#define endl "\n"
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
#define ForEach(a,b) for_each(a.begin(),a.end(),b)
#define NextAfter(x) x = nextafter(x, INFINITY)
template <class T> inline bool chmin(T& a, T b){ if(a > b){ a = b; return 1; } return 0; }
template <class T> inline bool chmax(T& a, T b){ if(a < b){ a = b; return 1; } return 0; }
struct Edge { int to; ll cost; Edge(int to, ll cost) : to(to), cost(cost) {} };
using Graph = vector<vector<Edge>>;

using mint = modint998244353;

ll mow(ll x, ll n){ ll ret = 1; while(n > 0){ if(n & 1) ret = ret * x; x = x * x; n >>= 1; } return ret; }
ll mow(ll x, ll n, ll mod){ ll ret = 1; while(n > 0){ if(n & 1) ret = ret * x % mod; x = x * x % mod; n >>= 1; } return ret; }

template <class T> struct SegmentTree{
    using F = function<T(T, T)>;
    int n; vector<T> node; F combine; T identity;
    SegmentTree(int n, F combine, T identity) : n(n), node(n<<1, identity), combine(combine), identity(identity) {}
    T operator[](int ind){ return node[ind+n]; }
    void update(int i, int x){ node[i+=n] = x; while(i >>= 1) node[i] = combine(node[i<<1|0], node[i<<1|1]); }
    T get(int l, int r){
        T res = identity;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1){
            if(l & 1) res = combine(res, node[l++]);
            if(r & 1) res = combine(node[--r], res);
        }
        return res;
    }
};

void Main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> ng(n);
    rep(m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        ng[a].emplace_back(b);
        ng[b].emplace_back(a);
    }
    vector<vector<mint>> dp(k + 1, vector<mint>(n));
    dp[0][0] = 1;
    rep(k){
        mint sum = 0;
        rep(j,n) sum += dp[i][j];
        rep(j,n){
            mint t = dp[i][j];
            for(const auto& x : ng[j]) t += dp[i][x];
            dp[i+1][j] = sum - t;
        }
    }
    cout << dp[k][0].val() << endl;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << setprecision(10) << fixed;
    Main();
}