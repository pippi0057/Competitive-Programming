#include <bits/stdc++.h>
using namespace std;
const double pi = 3.14159265358979;
#define setup\
    cin.tie(0);\
    ios::sync_with_stdio(false);\
    cout << setprecision(20) << fixed;
#define int long long int
#define db double
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
#define vb vector<bool>

signed main(){
    setup;
    int n, m, ans = 0;
    cin >> n >> m;
    vi h(n);
    vb s(n, 1);
    Srep(n) cin >> h[i];
    Srep(m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        if(h[a] < h[b]) s[a] = 0;
        else if(h[a] > h[b]) s[b] = 0;
        else s[a] = s[b] = 0;
    }
    Srep(n) if(s[i]) ans++;
    cout << ans << endl;
}
