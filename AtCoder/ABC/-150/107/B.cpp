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
    int h, w;
    cin >> h >> w;
    vb ok_h(h, 0), ok_w(w, 0);
    V<V<char>> a(h, V<char>(w));
    rep2d(h,w){
        cin >> a[i][j];
        if(a[i][j] == '#'){
            ok_h[i] = 1;
            ok_w[j] = 1;
        }
    }
    Srep(h) if(ok_h[i]){
        Lrep(j,0,w) if(ok_w[j])
            cout << a[i][j];
        cout << endl;
    }
}