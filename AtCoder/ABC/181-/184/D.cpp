#include <bits/stdc++.h>
using namespace std;
const double pi = 3.14159265358979;
#define speed\
    cin.tie(0);\
    ios::sync_with_stdio(false);
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
    speed;
    ldb a,b,c;
    cin >> a >> b >> c;
    vector<vector<vector<ldb>>> dp(100, vector<vector<ldb>>(100, vector<ldb>(100)));
    for(ldb i = a; i <= 100; i++){
        for(ldb j = b; j <= 100; j++){
            for(ldb k = c; k <= 100; k++){
                dp[i+1][j][k] = dp[i][j][k] * i / (i + j + k)
                
            }
        }
    }
}