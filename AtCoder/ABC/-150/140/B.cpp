#include <bits/stdc++.h>
using namespace std;
const double pi = 3.14159265358979;
#define int long long int
#define db double
#define ldb long double
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
#define vc vector<char>
#define vvc vector<vc>

int32_t main(){
    int n, ans = 0;
    cin >> n;
    vi a(n),b(n),c(n-1);
    Srep(n) cin >> a[i];
    Srep(n) cin >> b[i];
    Srep(n-1) cin >> c[i];
    Srep(n){
        ans += b[a[i]-1];
        if(i != 0) if(a[i] - a[i-1] == 1) ans += c[a[i-1]-1];
    }
    cout << ans << endl;
}