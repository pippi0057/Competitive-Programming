#include <bits/stdc++.h>
using namespace std;
#define int long long int
const double pi = 3.14159265358979;
const int inf = 1e18;
const int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
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
struct Edge { int to, cost, wa; Edge(int to, int cost, int wa) : to(to), cost(cost), wa(wa) {} };
using Graph = vector<vector<Edge>>;
template <class T> bool chmin(T& a, T b){ if(a > b){ a = b; return 1; } return 0; }
template <class T> bool chmax(T& a, T b){ if(a < b){ a = b; return 1; } return 0; }

int time(int a, int b){
    if(!(a % b)) return 0;
    else return (a / b + 1) * b - a;
}

vector<int> dijkstra(const Graph &g, int s){
    int n = g.size();
    vector<int> dist(n, inf);
    priority_queue<pii,vector<pii>,greater<pii>> task;
    dist[s] = 0;
    task.push(pii(dist[s], s));
    while(task.size()){
        pii p = task.top();
        task.pop();
        int v = p.second;
        for(auto e : g[v]) {
            if(dist[e.to] > dist[v] + e.cost + time(dist[v], e.wa)){
                dist[e.to] = dist[v] + e.cost + time(dist[v], e.wa);
                task.push(pii(dist[e.to], e.to));
            }
        }
    }
    return dist;
}

void Main(){
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    x--; y--;
    Graph g(n);
    rep(m){
        int a, b, t, k;
        cin >> a >> b >> t >> k;
        a--; b--;
        g[a].push_back(Edge(b, t, k));
        g[b].push_back(Edge(a, t, k));
    }
    vector<int> ans = dijkstra(g, x);
    cout << (ans[y] == inf ? -1 : ans[y]) << endl;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    Main();
}