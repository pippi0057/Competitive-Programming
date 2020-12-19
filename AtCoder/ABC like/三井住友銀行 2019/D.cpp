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
    int n, ans = 0;
    string s;
    cin >> n >> s;
    for(char a = 48; a <= 57; a++){
        for(char b = 48; b <= 57; b++){
            for(char c = 48; c <= 57; c++){
                vb ok(3, 0);
                for(auto x : s){
                    if(x == a && !ok[0]){
                        ok[0] = 1;
                        goto end;
                    }
                    if(x == b && ok[0] && !ok[1]){
                        ok[1] = 1;
                        goto end;
                    }
                    if(x == c && ok[1] && !ok[2]){
                        ok[2] = 1;
                        goto end;
                    }
                    end:;
                }
                if(ok[0] && ok[1] && ok[2]) ans++;
            }
        }
    }
    cout << ans << endl;
}