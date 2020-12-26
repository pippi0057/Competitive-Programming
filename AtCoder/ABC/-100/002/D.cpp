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
#define graph vvi
#define vdb vector<db>
#define vb vector<bool>
#define V vector

signed main(){
    setup;
    int n, m, ans = 0;
    cin >> n >> m;
    V<vb> g(n, vb(n));
    Srep(m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a][b] = 1;
        g[b][a] = 1;
    }
    rep2d(n,n) if(i == j) g[i][j] = 1;
    Brep1st(n){
        int cnt = 0;
        bool ok = 1;
        vb temp(n);
        Brep2nd(n) temp[i] = 1;
        Brep2nd(n){
            Lrep(j,0,n)
                if(temp[j] && !g[i][j]) ok = 0;
            cnt++;
        }
        if(ok) ans = max(ans, cnt);
    }
    cout << ans << endl;
}