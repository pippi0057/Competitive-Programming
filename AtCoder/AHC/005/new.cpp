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
    
    int start = clock();
    
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
        vector check(3, vector(3, false));
        int cnt = 0;
        rep(i, 0, 4){
            int yp = y + dy[i], xp = x + dx[i];
            if(is_valid(yp, xp)) cnt++, check[1 + dy[i]][1 + dx[i]] = true;
        }
        if(cnt >= 3) return true;
        if(cnt <= 1) return false;
        return !(check[1][0] && check[1][2]) && !(check[0][1] && check[2][1]);
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
    set<pair<int, int>> XY;
    rep(i, 0, n) rep(j, 0, n) if(is_intersection(i, j)){
        bool ok = 0;
        for(int k = i; is_valid(k, j); k++) if(XY.find({k, j}) == XY.end()) ok = 1;
        for(int k = i; is_valid(k, j); k--) if(XY.find({k, j}) == XY.end()) ok = 1;
        for(int k = j; is_valid(i, k); k++) if(XY.find({i, k}) == XY.end()) ok = 1;
        for(int k = j; is_valid(i, k); k--) if(XY.find({i, k}) == XY.end()) ok = 1;
        if(ok){
            visit.emplace_back(i, j);
            for(int k = i; is_valid(k, j); k++) XY.insert({k, j});
            for(int k = i; is_valid(k, j); k--) XY.insert({k, j});
            for(int k = j; is_valid(i, k); k++) XY.insert({i, k});
            for(int k = j; is_valid(i, k); k++) XY.insert({i, k});
        }
    }
    sort(all(visit), [&](pair<int, int> a, pair<int, int> b){
        return dist[convert(sy, sx)][convert(a.first, a.second)] < dist[convert(sy, sx)][convert(b.first, b.second)];
    });
    int posy = sy, posx = sx;
    string ans = "";
    ll now = INF * INF;
    visit.push_back({sy, sx});
    do{
        if(clock() - start > TIME_LIMIT) break;
        string t5 = "";
        ll sum = 0;
        for(const auto& [y, x] : visit){
            vector<ll> d = dijkstra(g, convert(posy, posx));
            sum += d[convert(y, x)];
        }
        posy = sy, posx = sx;
        if(chmin(now, sum)){
            for(const auto& [y, x] : visit){
                vector<int> ord;
                dijkstra2(g, convert(posy, posx), ord);
                vector<pair<int, int>> temp;
                for(const auto& e : get_path(ord, convert(y, x))) temp.emplace_back(e / n, e % n);
                rep(i, 0, temp.size() - 1){
                    if(temp[i + 1].first - temp[i].first == 1) t5 += 'D';
                    else if(temp[i + 1].first - temp[i].first == -1) t5 += 'U';
                    else if(temp[i + 1].second - temp[i].second == 1) t5 += 'R';
                    else if(temp[i + 1].second - temp[i].second == -1) t5 += 'L';
                }
                posy = y, posx = x;
            }
            ans = t5;
        }
        posy = sy, posx = sx;
        if(clock() - start > TIME_LIMIT) break;
    }while(next_permutation(all(visit)));
    cout << ans << endl;
}