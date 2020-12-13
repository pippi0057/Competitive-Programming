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
    int n, k, sum = 0;
    cin >> n >> k;
    vi a(n), b(n);
    Srep(n) cin >> a[i];
    Srep(n){
        cin >> b[i];
        sum += b[i];
    }
    if(k == 1) cout << a[n-1] + sum << endl;
    else if(k == 2){
        int ans = a[n-1];
        bool cmd = 0;
        Srep(n){
            if(b[i] % 2){
                if(cmd){
                    ans += b[i] / 2;
                    cmd = 0;
                }else{
                    ans += RoundUp(b[i], 2);
                    cmd = 1;
                }
            }else ans += RoundUp(b[i], 2);
        }
        cout << ans << endl;
    }else cout << "idk" << endl;
}   