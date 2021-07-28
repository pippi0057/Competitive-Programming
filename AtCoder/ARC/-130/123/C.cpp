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

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a * b / gcd(a, b); }
template <class T> int gcd(vector<T>& v){ int res = 0; for(auto x : v) res = gcd(res, x); return res; }
template <class T> int lcm(vector<T>& v){ int res = 1; for(auto x : v) res = lcm(res, x); return res; }

void Main(){
    clock_t start = clock();
    int n;
    cin >> n;
    vector<pll> a, b;
    vector<ll> e, f, g, h;
    rep(n){
        int c, d;
        cin >> c >> d;
        if(i % 2) a.push_back({c, d});
        else b.push_back({c, d});
    }
    rep(bit, 1 << a.size()){
        ll t1 = 0, t2 = 0;
        rep(a.size()){
            if(bit >> i & 1) t1 = gcd(t1, a[i].first);
            else t2 = gcd(t2, a[i].second);
        }
        e.push_back(t1);
        f.push_back(t2);
    }
    rep(bit, 1 << b.size()){
        ll t1 = 0, t2 = 0;
        rep(b.size()){
            if(bit >> i & 1) t1 = gcd(t1, b[i].first);
            else t2 = gcd(t2, b[i].second);
        }
        g.push_back(t1);
        h.push_back(t2);
    }
    sort(all(e)); sort(all(f)); sort(all(g)); sort(all(h));
    ll ans = 0;
    vector<ll> q, s;
    rrep(e.size()) rrep(j,g.size()){
        q.push_back(gcd(e[i], g[j]));
        clock_t end = clock();
        if(end - start > 1000) goto endloop;
    }
    endloop:;
    rrep(f.size()) rrep(j,h.size()){
        s.push_back(gcd(f[i], h[j]));
        clock_t end = clock();
        if(end - start > 2000) goto endloop2;
    }
    endloop2:;
    sort(all(q)); sort(all(s));
    for(const auto& x : q) cout << x << " ";
    cout << endl;
    for(const auto& x : s) cout << x << " ";
    cout << endl;   
    rrep(q.size()) rrep(j,s.size()){
        clock_t end = clock();
        if(end - start > 3950){ cout << ans << endl; return; }
        chmax(ans, lcm(q[i], s[j]));
    }
    cout << ans << endl;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << setprecision(10) << fixed;
    Main();
}