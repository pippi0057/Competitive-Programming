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
    int n, m;
    cin >> n >> m;
    vi ans(n);
    Srep(n) cin >> ans[i];
    V<V<P>> abc(n);
    Srep(m){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--; c--;
        abc[a].push_back(P(b, c));
    }
    Brep1st(n){
        vb temp(n);
        Brep2nd(n) temp[i] = 1;
        Srep(n){
            if(ans[i] == 1 && !temp[i]) goto end;
            else if(ans[i] == 2 && temp[i]) goto end;
        }
        Srep(n){
            if(temp[i]){
                Lrep(j,0,abc[i].size()){
                    if(temp[abc[i][j].F] && !temp[abc[i][j].S]) goto end;
                }
            }
        }
        Srep(n) cout << (temp[i] ? 1 : 2) << endl;
        return 0;
        end:;
    }
    cout << -1 << endl;
}