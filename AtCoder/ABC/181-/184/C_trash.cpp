#include <bits/stdc++.h>
using namespace std;
const double pi = 3.14159265358979;
#define speed\
    cin.tie(0);\
    ios::sync_with_stdio(false);
#define int long long int
#define db double
#define ldb long double
#define P pair<int,int>
#define F first
#define S second
#define dtor(deg) (((deg)/360)*2*pi)
#define rtod(rad) (((rad)/2/pi)*360)
#define all(a) a.begin(),a.end()
#define Srep(n) for(int i = 0; i < n; i++)
#define Lrep(i,a,n) for(int i = a; i < n; i++)
#define Brep1st(n) for(int bit = 0; bit < (1 << n); bit++)
#define Brep2nd(n) Srep(n) if(bit >> i & 1)
#define rep2d(n,m) Srep(n) Lrep(j,0,m)
#define vi vector<int>
#define vvi vector<vi>
#define vc vector<char>
#define vvc vector<vc>

const int INF = 1000000000; 

int32_t main(){
    speed;
    int sx,sy,gx,gy;
    cin >> sx >> sy >> gx >> gy;
    sx--; sy--; gx--; gy--;
    int cmd;
    if(sx == gx && sy == gy){
        cout << 0 << endl;
        return 0;
    }
    if(sx < gx && sy < gy) cmd = 1;
    else if(sx > gx && sy < gy) cmd = 2;
    else if(sx > gx && sy < gy) cmd = 3;
    else cmd = 4;
    vvi d(1000000001,vi(1000000001,INF));
    vector<int> dx1 = {0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 4, 5};
    vector<int> dy1 = {3, 2, 1, 2, 1, 0, 2, 1, 0, 0, 3, 4, 5};
    vector<int> dx2 = {0, 0, 0, -1, -1, -1, -2, -2, -2, -3, -3, -4, -5};
    vector<int> dy2 = {3, 2, 1, 2, 1, 0, 2, 1, 0, 0, 3, 4, 5};
    vector<int> dx3 = {0, 0, 0, -1, -1, -1, -2, -2, -2, -3, -3, -4, -5};
    vector<int> dy3 = {-3, -2, -1, -2, -1, 0, -2, -1, 0, 0, -3, -4, -5};
    vector<int> dx4 = {0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 4, 5};
    vector<int> dy4 = {-3, -2, -1, -2, -1, 0, -2, -1, 0, 0, -3, -4, -5};
    queue<P> search;
    d[sx][sy] = 0;
    search.push(P(sx,sy));
    while(search.size()){
        P p = search.front();
        search.pop();
        if(p.F == gx && p.S == gy) break;
        Srep(13){
            int nx, ny;
            switch(cmd){
                case 1:
                    p.F = dx1[i];
                    p.S = dy1[i];
                    if(d[nx][ny] == INF){
                        search.push(P(nx,ny));
                        d[nx][ny] = d[p.F][p.S] + 1;
                    }
                    break;
                case 2:
                    p.F = dx2[i];
                    p.S = dy2[i];
                    if(d[nx][ny] == INF){
                        search.push(P(nx,ny));
                        d[nx][ny] = d[p.F][p.S] + 1;
                    }
                    break;
                case 3:
                    p.F = dx3[i];
                    p.S = dy3[i];
                    if(d[nx][ny] == INF){
                        search.push(P(nx,ny));
                        d[nx][ny] = d[p.F][p.S] + 1;
                    }
                    break;
                case 4:
                    p.F = dx4[i];
                    p.S = dy4[i];
                    if(d[nx][ny] == INF){
                        search.push(P(nx,ny));
                        d[nx][ny] = d[p.F][p.S] + 1;
                    }
                    break;
            }
        }
    }
    cout << d[gx][gy] << endl;
}