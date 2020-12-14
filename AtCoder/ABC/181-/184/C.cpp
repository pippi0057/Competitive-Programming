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
    int sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;
    auto ok = [](int a, int b, int c, int d) -> bool {
        if(a + b == c + d) return 1;
        if(a - b == c - d) return 1;
        if(abs(a - c) + abs(b - d) <= 3) return 1;
        return 0;
    };
    if(sx == gx && sy == gy) return puts("0") & 0;
    if(ok(sx, sy, gx, gy)) return puts("1") & 0;
    for(int i = -3; i <= 3; i++){
        for(int j = -3; j <= 3; j++){
            if(ok(sx, sy, (sx + i), (sy + j)) && ok((sx + i), (sy + j), gx, gy)){
                return puts("2") & 0;
            }
        }
    }
    if((sx + sy) % 2 == (gx + gy) % 2) return puts("2") & 0;
    cout << 3 << endl;
}