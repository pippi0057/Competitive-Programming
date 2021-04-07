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
    string a, b, c;
    cin >> a >> b >> c;
    int ac = 0, bc = 0, cc = 0, cmd = 0;
    auto aj = [a](int n) -> bool {
        if(a.size() == n){
            cout << 'A' << endl;
            return 1;
        }
        return 0;
    };
    auto bj = [b](int n) -> bool {
        if(b.size() == n){
            cout << 'B' << endl;
            return 1;
        }
        return 0;
    };
    auto cj = [c](int n) -> bool {
        if(c.size() == n){
            cout << 'C' << endl;
            return 1;
        }
        return 0;
    };
    while(true){
        if(cmd == 0){
            if(aj(ac)) return 0;
            if(a[ac] == 'a') cmd = 0;
            else if(a[ac] == 'b') cmd = 1;
            else cmd = 2;
            ac++;
        }else if(cmd == 1){
            if(bj(bc)) return 0;
            if(b[bc] == 'a') cmd = 0;
            else if(b[bc] == 'b') cmd = 1;
            else cmd = 2;
            bc++;
        }else{
            if(cj(cc)) return 0;
            if(c[cc] == 'a') cmd = 0;
            else if(c[cc] == 'b') cmd = 1;
            else cmd = 2;
            cc++;
        }
    }
}