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
template<class T> istream& operator>>(istream& is, set<T>& a){ T input; is >> input; a.insert(input); return is; }
template<class T> istream& operator>>(istream& is, vector<T>& a){ for(auto& x : a) is >> x; return is; }
struct sorted_impl{
    template<class T> friend vector<T> operator|(vector<T> a, sorted_impl){ sort(all(a)); return a; }
    template<class T> friend void operator|=(vector<T>& a, sorted_impl){ sort(all(a)); }
} sorted;
struct reversed_impl{
    template<class T> friend vector<T> operator|(vector<T> a, reversed_impl){ reverse(all(a)); return a; }
    template<class T> friend void operator|=(vector<T>& a, reversed_impl){ reverse(all(a)); }
} reversed;

pii operator+(const pii& a, const pii& other){ return {a.first + other.first, a.second + other.second}; }

void Main(){
    int n, x, y, ans = 10000;
    cin >> n >> x >> y;
    vector<map<pii, int>> dp(n);
    vector<pii> A(n);
    for(auto& [x, y] : A) cin >> x >> y;
    A |= sorted;
    A |= reversed;
    dp[0][{0, 0}] = 0;
    dp[0][A[0]] = 1;
    rep(i, 1, n){
        for(auto itr = dp[i-1].begin(); itr != dp[i-1].end(); itr++){
            auto& [nx, ny] = itr->first;
            if(dp[i].find(itr->first) == dp[i].end()) dp[i][itr->first] = itr->second;
            else chmin(dp[i][itr->first], itr->second);
            if(dp[i].find(itr->first + A[i]) == dp[i].end()) dp[i][itr->first + A[i]] = itr->second + 1;
            else chmin(dp[i][itr->first + A[i]], itr->second + 1);
        }
    }
    for(auto itr = dp[n-1].begin(); itr != dp[n-1].end(); itr++){
        auto& [nx, ny] = itr->first;
        if(x <= nx && y <= ny) chmin(ans, itr->second);
    }
    if(ans == 10000) cout << -1 << endl;
    else cout << ans << endl;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << setprecision(10) << fixed;
    Main();
}