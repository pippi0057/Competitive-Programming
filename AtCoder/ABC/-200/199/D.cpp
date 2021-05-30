#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define ll int64_t
const ll inf = 1e17;
const int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
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
#define vec(type,name,...) vector<type> name(__VA_ARGS__)
#define vv(type,name,size,...) vector<vector<type>> name(size,vector<type>(__VA_ARGS__))
#define ForEach(a,b) for_each(a.begin(),a.end(),b)
#define NextAfter(x) x = nextafter(x, INFINITY)
template <class T> bool chmin(T& a, T b){ if(a > b){ a = b; return 1; } return 0; }
template <class T> bool chmax(T& a, T b){ if(a < b){ a = b; return 1; } return 0; }

int n, color[20];
vector<vector<int>> g(20);
vector<int> c;

ll dfs(int i){
    ll res = 0;
    bool ok = 1;
    if(i == c.size()) return 1;
    color[c[i]] = 1;
    for(auto v : g[c[i]]) if(color[c[i]] == color[v]) ok = 0;
    if(ok) res += dfs(i + 1);
    ok = 1;
    color[c[i]] = 2;
    for(auto v : g[c[i]]) if(color[c[i]] == color[v]) ok = 0;
    if(ok) res += dfs(i + 1);
    ok = 1;
    color[c[i]] = 3;
    for(auto v : g[c[i]]) if(color[c[i]] == color[v]) ok = 0;
    if(ok) res += dfs(i + 1);
    color[c[i]] = 0;
    return res;
}

void Main(){
    int m;
    cin >> n >> m;
    set<int> f;
    rep(m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        f.insert(a); f.insert(b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(auto x : f) c.push_back(x);
    if(!f.size()) cout << ll(pow(3, n)) << endl;
    else cout << ll(pow(3, n - f.size())) * dfs(0) << endl;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    Main();
}