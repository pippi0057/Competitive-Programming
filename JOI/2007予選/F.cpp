#include <bits/stdc++.h>
using namespace std;
#define int long long int
const double pi = 3.14159265358979;
const int inf = 1e13;
#define setup cin.tie(0); ios::sync_with_stdio(false); cout << setprecision(20) << fixed;
#define db double
#define P pair<int,int>
#define F first
#define S second
#define endl "\n"
#define dtor(deg) (((deg)/360)*2*pi)
#define rtod(rad) (((rad)/2/pi)*360)
#define all(a) a.begin(),a.end()
#define Srep(n) for(int i = 0; i < n; i++)
#define Lrep(i,a,n) for(int i = a; i < n; i++)
#define Brep1st(n) for(int bit = 0; bit < (1 << n); bit++)
#define Brep2nd(n) Srep(n) if(bit >> i & 1)
#define rep2d(n,m) Srep(n) Lrep(j,0,m)
#define RoundUp(a,b) (a % b ? a / b + 1 : a / b)
#define vi vector<int>
#define vvi vector<vi>
#define vdb vector<db>
#define vb vector<bool>
#define V vector

signed main(){
    setup;
    int a, b, n;
    cin >> a >> b >> n;
    V<vb> maze(a, vb(b, 1));
    Srep(n){
        int x, y;
        cin >> x >> y;
        maze[x-1][y-1] = 0;
    }
    vi mx = {1, 0};
    vi my = {0, 1};
    vvi ans(a, vi(b, 0));
    ans[0][0] = 1;
    queue<P> search;
    search.push(P(0, 0));
    auto ok = [maze, ans](int x, int y) -> bool {
        if(maze[x-1][y] && ans[x-1][y] == 0) return 0;
        if(maze[x][y-1] && ans[x][y-1] == 0) return 0;
        return 1;
    };
    while(!search.empty()){
        int nx, ny;
        P p = search.front();
        nx = p.F;
        ny = p.S;
        search.pop();
        if(nx == a - 1 && ny == b - 1){
            if(ans[nx][ny] == 0) search.push(P(nx, ny));
            else break;
        }
        if(nx == 0 && ny == 0) Srep(2) search.push(P(nx + mx[i], ny + my[i]));
        else if(nx == 0){
            ans[nx][ny] = ans[nx][ny-1];
            search.push(P(nx + 1, ny));
            search.push(P(nx, ny + 1));
        }else if(ny == 0){
            ans[nx][ny] = ans[nx-1][ny];
            search.push(P(nx + 1, ny));
            search.push(P(nx, ny + 1));
        }else{
            if(ok(nx, ny)){
                ans[nx][ny] = ans[nx-1][ny] + ans[nx][ny-1];
                search.push(P(nx + 1, ny));
                search.push(P(nx, ny + 1));
            }
            else search.push(P(nx, ny));
        }
    }
    cout << endl;
    Srep(a){
        Lrep(j,0,b){
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    cout << ans[a-1][b-1] << endl;
}