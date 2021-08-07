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
#define ENDLOOP clock_t END = clock(); if(((long double)(END - START) / CLOCKS_PER_SEC * 1000.0) > TIME) break;

constexpr long double TIME = 3;

vector<pii> get_path(map<pii,pii> &prev, pii t) {
    vector<pii> path;
    pii error = {-1, -1}, now = t;
    path.push_back(t);
    while(1){
        auto [nx, ny] = now;
        now = prev[{nx, ny}];
        if(now == error) break;
        path.push_back(now);
    }
    reverse(path.begin(), path.end());
    return path;
}

void Main(clock_t START, int TIME){
    int n, sx, sy;
    cin >> n >> sx >> sy;
    map<pii, int> s;
    rep(n) rep(j, n){
        char input;
        cin >> input;
        if(input == '#') s[{i, j}] = -1;
        else s[{i, j}] = input - '0';
    }
    pii _1/*, _2*/;
    while(1){
        int x = rand() % n, y = rand() % n;
        if(s[{x, y}] != -1 && !(sx == x && sy == y)){
            _1 = {x, y};
            break;
        }
    }   
    map<pii, pii> prev1, prev2;
    rep(n) rep(j, n){
        prev1[{i, j}] = {-1, -1};
        prev2[{i, j}] = {-1, -1};
    }
    map<pii, map<pii, ll>> dist;
    {
        int i = sx, j = sy;
        priority_queue<pair<ll,pii>,vector<pair<ll,pii>>,greater<pair<ll,pii>>> task;
        rep(k, n) rep(l, n) dist[{i, j}][{k, l}] = inf;
        dist[{i, j}][{i, j}] = 0;
        task.push({dist[{i, j}][{i, j}], {i, j}});
        while(task.size()){
            auto f = task.top(); task.pop();
            pii v = f.second;
            if(dist[{i, j}][v] < f.first) continue;
            rep(k, 4){
                auto [nx, ny] = v;
                if(0 <= nx + dx[k] && nx + dx[k] < n && 0 <= ny + dy[k] && ny + dy[k] < n){
                    if(s[{nx + dx[k], ny + dy[k]}] == -1) continue;
                    if(chmin(dist[{i, j}][{nx + dx[k], ny + dy[k]}], dist[{i, j}][v] + s[{nx + dx[k], ny + dy[k]}])){
                        task.push({dist[{i, j}][{nx + dx[k], ny + dy[k]}], {nx + dx[k], ny + dy[k]}});
                        prev1[{nx + dx[k], ny + dy[k]}] = v;
                    }
                }
            }
        }
    }
    {
        int i = _1.first, j = _1.second;
        priority_queue<pair<ll,pii>,vector<pair<ll,pii>>,greater<pair<ll,pii>>> task;
        rep(k, n) rep(l, n) dist[{i, j}][{k, l}] = inf;
        dist[{i, j}][{i, j}] = 0;
        task.push({dist[{i, j}][{i, j}], {i, j}});
        while(task.size()){
            auto f = task.top(); task.pop();
            pii v = f.second;
            if(dist[{i, j}][v] < f.first) continue;
            rep(k, 4){
                auto [nx, ny] = v;
                if(0 <= nx + dx[k] && nx + dx[k] < n && 0 <= ny + dy[k] && ny + dy[k] < n){
                    if(s[{nx + dx[k], ny + dy[k]}] == -1) continue;
                    if(chmin(dist[{i, j}][{nx + dx[k], ny + dy[k]}], dist[{i, j}][v] + s[{nx + dx[k], ny + dy[k]}])){
                        task.push({dist[{i, j}][{nx + dx[k], ny + dy[k]}], {nx + dx[k], ny + dy[k]}});
                        prev2[{nx + dx[k], ny + dy[k]}] = v;
                    }
                }
            }
        }
    }
    string ans = "", t1 = "", t2 = "";
    vector<pii> s1 = get_path(prev1, _1), s2 = get_path(prev2, {sx, sy});
    rep(s1.size()-1){
        auto [px, py] = s1[i];
        auto [nx, ny] = s1[i+1];
        if(px + 1 == nx) t1 += 'D';
        if(px - 1 == nx) t1 += 'U';
        if(py + 1 == ny) t1 += 'R';
        if(py - 1 == ny) t1 += 'L';
    }
    rep(s2.size()-1){
        auto [px, py] = s2[i];
        auto [nx, ny] = s2[i+1];
        if(px + 1 == nx) t2 += 'D';
        if(px - 1 == nx) t2 += 'U';
        if(py + 1 == ny) t2 += 'R';
        if(py - 1 == ny) t2 += 'L';
    }
    ans = t1 + t2;
    cout << ans << endl;
}

signed main(){
    clock_t START = clock();
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << setprecision(10) << fixed;
    Main(START, TIME * 993.0);
}