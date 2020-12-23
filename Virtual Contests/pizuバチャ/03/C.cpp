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
    int n, sum = 0;
    cin >> n;
    vi a(n), b(n);
    Srep(n) cin >> a[i];
    a.insert(a.begin(), 0);
    Srep(n){
        if(a[i] > 0 && a[i+1] < 0) b[i] = (a[i] - a[i+1]) * 2;
        else if(a[i] < 0 && a[i+1] > 0) b[i] = (a[i+1] - a[i]) * 2;
        else b[i] = (max(a[i], a[i+1]) - min(a[i], a[i+1])) * 2;
        sum += b[i];
    }
    Srep(n) cout << sum - b[i] << endl;
}