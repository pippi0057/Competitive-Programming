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

vi memo(100010);

signed main(){
    setup;
    int n, ans = 0;
    cin >> n;
    vi a(n);
    Srep(n) cin >> a[i];
    sort(all(a));
    vi memo(n-1);
    for(int i = 0; i < (n - 1) / 2; i++){
        memo[i] = memo[n-i-2] = (n - i - 1) * (i + 1);
    }
    if((n - 1) % 2 == 1) memo[(n-1)/2] = pow((n-1)/2+1, 2);
    Srep(n-1){
        ans += (a[i+1] - a[i]) * memo[i];
    }
    cout << ans << endl;
}