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
#define vdb vector<db>
#define vb vector<bool>

const int MOD = 1000000007;

signed main(){
    setup;
    int n, m;
    cin >> n >> m;
    vi dp(n+1);
    vb b(n+1, 1);
    Srep(m){
        int input;
        cin >> input;
        b[input] = 0;
    }
    dp[0] = 1;
    Srep(n+1) if(dp[i]){
        if(b[i+1] && i <= n-1) dp[i+1] += dp[i] % MOD;
        if(b[i+2] && i <= n-2) dp[i+2] += dp[i] % MOD;
    }
    cout << dp[n] % MOD << endl;
}
