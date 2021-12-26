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
#define F function
template <class T> inline bool chmin(T& a, T b){ if(a > b){ a = b; return 1; } return 0; }
template <class T> inline bool chmax(T& a, T b){ if(a < b){ a = b; return 1; } return 0; }
struct Edge { int to; ll cost; Edge(int to, ll cost) : to(to), cost(cost) {} };
using Graph = vector<vector<Edge>>;
template<class T> istream& operator>>(istream& is, vector<T>& a){ for(auto& x : a) is >> x; return is; }
template<class T> void operator+=(vector<T>& a, T b){ a.push_back(b); return; }
template<class T> istream& operator>>(istream& is, set<T>& a){ T input; is >> input; a.insert(input); return is; }
template<class T> void operator+=(set<T>& a, T b){ a.insert(b); return; }
struct sorted_impl{
    template<class T> friend vector<T> operator|(vector<T> a, sorted_impl){ sort(all(a)); return a; }
    template<class T> friend void operator|=(vector<T>& a, sorted_impl){ sort(all(a)); }
} sorted;
struct reversed_impl{
    template<class T> friend vector<T> operator|(vector<T> a, reversed_impl){ reverse(all(a)); return a; }
    template<class T> friend void operator|=(vector<T>& a, reversed_impl){ reverse(all(a)); }
} reversed;

struct UnionFind{
    vector<ll> data;
    UnionFind(ll n): data(n, -1){}
    bool unite(ll a, ll b){
        a = root(a); b = root(b);
        if(a == b) return 0;
        if(data[a] > data[b]) swap(a, b);
        data[a] += data[b];
        data[b] = a;
        return 1;
    }
    bool find(ll a, ll b){ return root(a) == root(b); }
    ll root(ll a){ return data[a] < 0 ? a : data[a] = root(data[a]); }
    ll size(ll a){ return -data[root(a)]; }
    ll operator[](ll a){ return root(a); }
    bool operator[](pair<int, int> a){ return find(a.first, a.second); }
};

vector<ll> dijkstra(const Graph &g, int s){
    int n = g.size();
    vector<ll> dist(n, inf);
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> task;
    dist[s] = 0;
    task.push({dist[s], s});
    while(task.size()){
        pii p = task.top();
        task.pop();
        int v = p.second;
        if(dist[v] < p.first) continue;
        for(auto e : g[v])
            if(chmin(dist[e.to], dist[v] + e.cost)) task.push({dist[e.to], e.to});
    }
    return dist;
}

void Main(){
    int n, m;
    cin >> n;
    vector<int> p(n), ans, place(n);
    map<pii, int> cmd;
    Graph g(n);
    UnionFind uf(n);
    rep(n){
        cin >> p[i]; p[i]--;
        place[p[i]] = i;
    }
    cin >> m;
    rep(m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        cmd[{a, b}] = i + 1;
        g[a] += {b, 1}; g[b] += {a, 1};
        uf.unite(p[a], p[b]);
    }
    rep(n) if(uf[p[i]] != uf[i]){ cout << -1 << endl; return; }
    rep(n){
        auto dist = dijkstra(g, i);
        queue<int> task;
        task.push(place[i]);
        while(task.size()){
            int now = task.front(); task.pop();
            for(Auto& [x, y] : g[now]) if(dist[x] + 1 == dist[now]){
                task.push(x); ans += cmd[{min(now, x), max(now, x)}];
                swap(p[x], p[now]);
                swap(place[p[x]], place[p[now]]);
            }
            if(ans.size() > 5000000) break;
        }
        if(ans.size() > 5000000) break;
    }
    if(ans.size() > 500000) cout << -1 << endl;
    else{
        cout << ans.size() << endl;
        for(Auto& x : ans) cout << x << " ";
        cout << endl;
    }
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << setprecision(10) << fixed;
    Main();
}