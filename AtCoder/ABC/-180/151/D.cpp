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
#define RoundUp(a,b) ((a) % (b) ? (a) / (b) + 1 : (a) / (b))
#define vi vector<int>
#define vvi vector<vi>
#define vdb vector<db>
#define vb vector<bool>
#define V vector

signed main(){
    setup;
    int h, w, ans = 0;
    cin >> h >> w;
    vi mx = {1, 0, -1, 0};
    vi my = {0, 1, 0, -1};
    V<vb> maze(h, vb(w));
    rep2d(h,w){
        char input;
        cin >> input;
        maze[i][j] = (input == '.');
    }
    rep2d(h,w) if(maze[i][j]){
        int sx = i, sy = j, temp = 0;
        vvi d(h, vi(w, inf));
        d[sx][sy] = 0;
        queue<P> search;
        search.push(P(sx, sy));
        while(!search.empty()){
            P p = search.front();
            search.pop();
            Lrep(k,0,4){
                int nx = p.F + mx[k],
                    ny = p.S + my[k];
                if(0 <= nx && nx < h && 0 <= ny && ny < w && maze[nx][ny] && d[nx][ny] == inf){
                    d[nx][ny] = d[p.F][p.S] + 1;
                    search.push(P(nx, ny));
                }
            }
            temp = max(temp, d[p.F][p.S]);
        }
        ans = max(ans, temp);
    }
    cout << ans << endl;
}