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
    int n, d, k, out = 0;
    cin >> n >> d >> k;
    V<P> ps(n);
    Srep(n) cin >> ps[i].S >> ps[i].F;
    sort(all(ps));
    Brep1st(n){
        if(bit == 0) continue;
        bool ok = 1;
        int ans = 0;
        V<P> temp;
        Brep2nd(n){
            ans++;
            temp.push_back(ps[i]);
        }
        vb table(ps[ans-1].F+1);
        Srep(ans){
            if(table[ps[i].F]) ok = 0;
            else table[ps[i].F] = 1;
            if(ans > 1){
                if(ps[ans-1].S != ps[ans].S){
                    Lrep(j,ps[ans-1].F,ps[ans-1].F+d+1){
                        if(table[j]) ok = 0;
                        else table[j] = 1;
                    }
                }
            }
        }
        if(ok) out = max(out, ans);
    }
    cout << out << endl;
}