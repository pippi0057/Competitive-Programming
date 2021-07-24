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

int search(const Graph& g, vector<bool>& done, int s, bool cmd){
    if(done[s]) return -1;
    done[s] = 1;
    bool ok = 1;
    for(auto x : g[s]){
        if(x.to == s) continue;
        int ans = search(g, done, x.to, !cmd);
        if(ans != -1) ok = 0;
        if(cmd && ans == 1) return 1;
        if(!cmd && ans == 2) return 2;
    }
    if(!g[s].size()) return cmd ? 0 : 1;
    if(ok) return -1;
    else return cmd ? 0 : 1;
}

void Main(){
    int n;
    cin >> n;
    Graph g(n);
    vector<string> s(n);
    set<string> st;
    map<string, int> mp;
    for(auto& x : s){
        cin >> x;
        if(x.size() <= 2) continue;
        st.insert(x.substr(0, 3));
        st.insert(x.substr(x.size() - 3, 3));
    }
    int m = st.size();
    { int i = 0; for(auto x : st) mp[x] = i, i++; }
    vector<vector<int>> vvec(m);
    rep(n){
        if(s[i].size() <= 2) continue;
        vvec[mp[s[i].substr(0, 3)]].push_back(i);
    }
    rep(n){
        if(s[i].size() <= 2) continue;
        for(auto x : vvec[mp[s[i].substr(s[i].size() - 3, 3)]]) g[i].push_back({x, 1});
    }
    rep(n){
        vector<bool> done(n);
        int ans = search(g, done, i, true);
        if(ans == -1) cout << "Draw" << endl;
        else if(ans == 1) cout << "Aoki" << endl;
        else cout << "Takahashi" << endl;
    }
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << setprecision(10) << fixed;
    Main();
}