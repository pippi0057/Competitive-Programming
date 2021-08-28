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
template <class T> inline bool chmin(T& a, T b){ if(a > b){ a = b; return 1; } return 0; }
template <class T> inline bool chmax(T& a, T b){ if(a < b){ a = b; return 1; } return 0; }
struct Edge { int to; ll cost; Edge(int to, ll cost) : to(to), cost(cost) {} };
using Graph = vector<vector<Edge>>;

using mint = modint998244353;

vector<pair<char, int>> encode(const string& str) {
    int n = (int)str.size();
    vector<pair<char, int>> ret;
    for(int l = 0; l < n;){
        int r = l + 1;
        for (; r < n && str[l] == str[r]; r++) {};
        ret.push_back({str[l], r - l});
        l = r;
    }
    return ret;
}

ll mow(ll x, ll n){ ll ret = 1; while(n > 0){ if(n & 1) ret = ret * x; x = x * x; n >>= 1; } return ret; }
ll mow(ll x, ll n, ll mod){ ll ret = 1; while(n > 0){ if(n & 1) ret = ret * x % mod; x = x * x % mod; n >>= 1; } return ret; }

void Main(){
    int n;
    string s;
    cin >> n >> s;
    set<char> t;
    for(const auto& x : s) t.insert(x);
    vector<pair<char, int>> RLC = encode(s);
    mint ans = 0;
    string v;
    for(const auto& x : t) v += x;
    n = RLC.size();
    do{
        vector<vector<mint>> dp(n, vector(t.size() + 1, mint(0)));
        dp[0][0] = 1;
        if(RLC[0].first == v[0]) dp[0][1] = ((mow(2, RLC[0].second, 998244353) - 1 + 998244353)) % 998244353;
        rep(i, 1, n){
            rep(j, 0, t.size() + 1) dp[i][j] = dp[i - 1][j];
            rep(j, 1, t.size() + 1){
                if(RLC[i].first == v[j - 1]) dp[i][j] += dp[i - 1][j - 1] * ((mow(2, RLC[i].second, 998244353) - 1 + 998244353) % 998244353);
            }
        }
        ans += dp[n - 1][t.size()];
    }while(next_permutation(all(v)));
    cout << ans.val() << endl;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << setprecision(10) << fixed;
    Main();
}