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

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }
template <class T> int gcd(vector<T>& v){ int res = 0; for(auto x : v) res = gcd(res, x); return res; }
template <class T> int lcm(vector<T>& v){ int res = 1; for(auto x : v) res = lcm(res, x); return res; }

bool is_prime(ll n){
    if (n < 2) return 0;
    else if (n == 2) return 1;
    else if (n % 2 == 0) return 0;
    for(ll i = 3; i * i <= n; i += 2) if(n % i == 0) return 0;
    return 1;
}

void Main(){
    ll n, m, sum = 1;
    cin >> n >> m;
    vector a(n, 0ll);
    set<ll> prime, ans;
    rep(i,1,m+1) ans.insert(i);
    for(auto& x : a){
        cin >> x;
        for(int i = 2; i * i <= x; i++){
            while(x % i == 0){
                x /= i;
                prime.insert(i);
            }
            if(x == 1) break;
        }
        if(x != 1) prime.insert(x);
    }
    for(const auto& x : prime) for(ll i = x; i <= m; i += x) ans.erase(i);
    cout << ans.size() << endl;
    for(const auto& x : ans) cout << x << endl;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << setprecision(10) << fixed;
    Main();
}