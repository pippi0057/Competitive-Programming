#include <bits/stdc++.h>
using namespace std;
#define int long long int
const double pi = 3.14159265358979;
const int inf = 1e13;
vector<int> dx = {0, 1, 0, -1, 1, 1, -1, -1};
vector<int> dy = {1, 0, -1, 0, 1, -1, 1, -1};
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
#define rrep(...) overload(__VA_ARGS__,_null,_rrep3,_rrep2,_rrep1)(__VA_ARGS__)
#define vec(type,name,...) vector<type> name(__VA_ARGS__)
#define vv(type,name,size,...) vector<vector<type>> name(size,vector<type>(__VA_ARGS__))
#define ForEach(a,b) for_each(a.begin(),a.end(),b)
struct Edge { int to, cost; Edge(int to, int cost) : to(to), cost(cost) {} };
using Graph = vector<vector<Edge>>;
template <class T> bool chmin(T& a, T b){ if(a > b){ a = b; return 1; } return 0; }
template <class T> bool chmax(T& a, T b){ if(a < b){ a = b; return 1; } return 0; }

void Main(){
    int h, w, sx, sy, gx, gy;
    cin >> h >> w;
    vec(bool, done, 26, 0);
    vv(char, a, h, w);
    vv(int, dist, h, w, inf);
    vv(pii, p, 26);
    queue<pii> task;
    rep(h) rep(j,w){
        cin >> a[i][j];
        if(a[i][j] == 'S'){
            sx = i;
            sy = j;
        }else if(a[i][j] == 'G'){
            gx = i;
            gy = j;
        }else if(a[i][j] != '.' && a[i][j] != '#'){
            p[a[i][j]-'a'].push_back({i, j});
        }
    }

    // 多分これが原因
    auto ok = [h, w, a, dist](int x, int y) -> bool{
        if(a[x][y] == '#') return 0;
        if(x < 0 || y < 0) return 0;
        if(x >= h || y >= w) return 0;
        if(dist[x][y] != inf) return 0;
        return 1;
    };
    task.push({sx, sy});
    dist[sx][sy] = 0;
    while(task.size()){
        pii now = task.front();
        int nx = now.first, ny = now.second;
        if(a[nx][ny] == 'G') break;
        task.pop();
        if((97 <= a[nx][ny] && a[nx][ny] <= 122) && !done[a[nx][ny]-'a']){
            done[a[nx][ny]-'a'] = 1;
            for(auto i : p[a[nx][ny]-'a']){
                int next_x = i.first, next_y = i.second;
                if(nx == next_x && ny == next_y) continue;
                dist[next_x][next_y] = dist[nx][ny] + 1;
                task.push({next_x, next_y});
            }
        }else{
            rep(4){
                if(ok(nx + dx[i], ny + dy[i])){
                    dist[nx + dx[i]][ny + dy[i]] = dist[nx][ny] + 1;
                    task.push({nx + dx[i], ny + dy[i]});
                }
            }
        }
    }
    cout << dist[gx][gy] << endl;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    //int n; cin >> n; rep(n)
    Main();
}
