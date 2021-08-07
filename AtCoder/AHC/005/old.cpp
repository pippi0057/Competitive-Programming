#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define all(v) v.begin(), v.end()
#define rep(i, begin, end) for(auto i = begin; i < (end); i++)
#define contains(v, x) (find(all(v), x) != v.end())
template<class T> inline bool chmin(T& a, T b){ if (a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b){ if (a < b){ a = b; return true; } return false; }
template<class T> inline T roundup(T a, T b){ return (a + b - 1) / b; }
const vector<int> dy = {0, 1, 0, -1, 1, 1, -1, -1, 0};
const vector<int> dx = {1, 0, -1, 0, 1, -1, 1, -1, 0};
using ll = long long;
const ll INF = 1e9;
const double EPS = 1e-10;
using P = pair<ll, int>;
struct Edge{ int to; ll cost; Edge(int to, ll cost) : to(to), cost(cost) {} };
using Graph = vector<vector<Edge>>;

constexpr double TIME_LIMIT = 2.95 * CLOCKS_PER_SEC;

vector<ll> dijkstra(const Graph &g, int s){
    int n = g.size();
    vector<ll> dist(n, INF * INF);
    dist[s] = 0;
    priority_queue<P, vector<P>, greater<P>> q;
    q.push(P(dist[s], s));
    while(q.size()){
        P p = q.top(); q.pop();
        int v = p.second;
        if(dist[v] < p.first) continue;
        for(auto e : g[v]){
            if(chmin(dist[e.to], dist[v] + e.cost)) q.push(P(dist[e.to], e.to));
        }
    }
    return dist;
}

void dijkstra2(const Graph &g, int s, vector<int>& prev){
    int n = g.size();
    vector<ll> dist(n, INF * INF);
    prev.resize(n, -1);
    dist[s] = 0;
    priority_queue<P, vector<P>, greater<P>> q;
    q.push(P(dist[s], s));
    while(q.size()){
        P p = q.top(); q.pop();
        int v = p.second;
        if(dist[v] < p.first) continue;
        for(auto e : g[v]){
            if(chmin(dist[e.to], dist[v] + e.cost)){
                prev[e.to] = v;
                q.push(P(dist[e.to], e.to));
            }
        }
    }
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    // int start = clock();
    
    // input
    int n, sy, sx;
    cin >> n >> sy >> sx;
    vector c(n, vector(n, '#'));
    rep(i, 0, n) rep(j, 0, n) cin >> c[i][j];
    
    int m = n * n;
    
    auto is_valid = [&](int y, int x){
        return 0 <= y && y < n && 0 <= x && x < n && c[y][x] != '#';
    };
    
    auto is_intersection = [&](int y, int x){
        int cnt = 0;
        rep(i, 0, 4){
            int yp = y + dy[i], xp = x + dx[i];
            if(is_valid(yp, xp)) cnt++;
        }
        return cnt >= 3 || (cnt >= 2 && ((y == 0 && (x == 0 || x == n - 1)) || (y == n - 1 && (x == 0 || x == n - 1))));
    };
    
    auto convert = [&](int y, int x){
        return y * n + x;
    };
    
    auto get_path = [&](const vector<int>& prev, int t){
        vector<int> path;
        for (int cur = t; cur != -1; cur = prev[cur]) {
            path.push_back(cur);
        }
        reverse(path.begin(), path.end());
        return path;
    };
    
    // init
    Graph g(m);
    rep(y, 0, n) rep(x, 0, n){
        if(!is_valid(y, x)) continue;
        rep(i, 0, 4){
            int yp = y + dy[i], xp = x + dx[i];
            if(is_valid(yp, xp)) g[convert(yp, xp)].emplace_back(convert(y, x), c[y][x]);
        }
    }
    vector dist(m, vector(m, INF));
    rep(i, 0, m) dist[i] = dijkstra(g, i);
    vector<pair<int, int>> visit;
    rep(i, 0, n) rep(j, 0, n) if(is_intersection(i, j)) visit.emplace_back(i, j);
    sort(all(visit), [&](pair<int, int> a, pair<int, int> b){
        return dist[convert(sy, sx)][convert(a.first, a.second)] < dist[convert(sy, sx)][convert(b.first, b.second)];
    });
    int posy = sy, posx = sx;
    string ans = "";
    for(const auto& [y, x] : visit){
        vector<int> ord;
        dijkstra2(g, convert(posy, posx), ord);
        vector<pair<int, int>> temp;
        for(const auto& e : get_path(ord, convert(y, x))) temp.emplace_back(e / n, e % n);
        rep(i, 0, temp.size() - 1){
            if(temp[i + 1].first - temp[i].first == 1) ans += 'D';
            else if(temp[i + 1].first - temp[i].first == -1) ans += 'U';
            else if(temp[i + 1].second - temp[i].second == 1) ans += 'R';
            else if(temp[i + 1].second - temp[i].second == -1) ans += 'L';
        }
        posy = y, posx = x;
    }
    cout << ans;
    reverse(all(ans));
    for(const auto& e : ans){
        if(e == 'R') cout << 'L';
        else if(e == 'L') cout << 'R';
        else if(e == 'U') cout << 'D';
        else if(e == 'D') cout << 'U';
    }
    cout << endl;
}