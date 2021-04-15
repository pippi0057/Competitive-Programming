#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define ll int64_t
const int inf_int = 1e9;
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

void Main(){
    int h, w, sx, sy, gx, gy;
    cin >> h >> w >> sx >> sy >> gx >> gy;
    sx--; sy--; gx--; gy--;
    vector maze(h, vector(w, false));
    vector ans(h, vector(w, inf_int));
    rep(h) rep(j,w){
        char input;
        cin >> input;
        maze[i][j] = (input == '#');
    }
    queue<pii> task;
    task.push({sx, sy});
    auto ok = [maze, h, w](int x, int y) -> bool{
        if(x < 0 || h <= x) return 0;
        if(y < 0 || w <= y) return 0;
        if(maze[x][y]) return 0;
        return 1;
    };
    for(int count = 0; ; count++){
        vector<pii> sub, sub2;
        while(task.size()){
            auto [fx, fy] = task.front();
            task.pop();
            if(ans[fx][fy] == inf_int){
                ans[fx][fy] = count;
                sub.push_back({fx, fy});
            }
            rep(4){
                int nx = fx + dx[i], ny = fy + dy[i];
                if(ok(nx, ny) && ans[nx][ny] == inf_int){
                    ans[nx][ny] = count;
                    task.push({nx, ny});
                    sub.push_back({nx, ny});
                }
            }
        }
        for(auto [fx, fy] : sub){
            for(int i = -2; i <= 2; i++) for(int j = -2; j <= 2; j++){
                int nx = fx + i, ny = fy + j;
                if(ok(nx, ny) && ans[nx][ny] == inf_int){
                    task.push({nx, ny});
                    ans[nx][ny] = count + 1;
                    sub2.push_back({nx, ny});
                }
            }
        }
        sub.clear();
        sub = sub2;
        sub2.clear();
        if(ans[gx][gy] != inf_int) break;
        if(count == 1000000){ cout << -1 << endl; return; }
    }
    cout << ans[gx][gy] << endl;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    Main();
}