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
    vi mx = {1, 1, 1, 0, 0, -1, -1, -1};
    vi my = {-1, 1, 0, 1, -1, -1, 1, 0};
    int h, w;
    cin >> h >> w;
    V<V<char>> s(h, V<char>(w));
    V<V<string>> ans(h, V<string>(w));
    rep2d(h,w) cin >> s[i][j];
    rep2d(h,w){
        if(s[i][j] == '#') ans[i][j] = "#";
        else{
            int temp = 0;
            Lrep(k,0,8){
                int nx = i + mx[k],
                    ny = j + my[k];
                if(nx < 0 || h <= nx || ny < 0 || w <= ny) continue;
                if(s[nx][ny] == '#') temp++;
            }
            ans[i][j] = to_string(temp);
        }
    }
    Srep(h){
        Lrep(j,0,w) cout << ans[i][j];
        cout << endl;
    }
}