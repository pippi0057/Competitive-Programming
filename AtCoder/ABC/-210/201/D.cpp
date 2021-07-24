#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define ll int64_t
const ll inf = 1e17;
const int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
#define pii pair<int,int>
#define pll pair<ll,ll>
#define endl "\n"
#define all(a) a.begin(),a.end()
#define overload(_1,_2,_3,_4,name,...) name
#define _rep1(n) for(int i = 0; i < (n); i++)
#define _rep2(i,n) for(int i = 0; i < (n); i++)
#define _rep3(i,a,b) for(int i = (a); i < (b); i++)
#define _rep4(i,a,b,c) for(int i = (a); i < (b); i += (c))
#define rep(...) overload(__VA_ARGS__,_rep4,_rep3,_rep2,_rep1)(__VA_ARGS__)
#define _rrep1(n) for(int i = (n) - 1; i >= 0; i--)
#define _rrep2(i,n) for(int i = (n) - 1; i >= 0; i--)
#define _rrep3(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define _rrep4(i,a,b,c) for(int i = (b) - 1; i >= (a); i -= (c))
#define rrep(...) overload(__VA_ARGS__,_rrep4,_rrep3,_rrep2,_rrep1)(__VA_ARGS__)
#define vec(type,name,...) vector<type> name(__VA_ARGS__)
#define vv(type,name,size,...) vector<vector<type>> name(size,vector<type>(__VA_ARGS__))
#define ForEach(a,b) for_each(a.begin(),a.end(),b)
#define NextAfter(x) x = nextafter(x, INFINITY)
template <class T> bool chmin(T& a, T b){ if(a > b){ a = b; return 1; } return 0; }
template <class T> bool chmax(T& a, T b){ if(a < b){ a = b; return 1; } return 0; }
struct Edge { int to; ll cost; Edge(int to, ll cost) : to(to), cost(cost) {} };
using Graph = vector<vector<Edge>>;

ll mow(ll x, ll n){ ll ret = 1; while(n > 0){ if(n & 1) ret = ret * x; x = x * x; n >>= 1; } return ret; }
ll mow(ll x, ll n, ll mod){ ll ret = 1; while(n > 0){ if(n & 1) ret = ret * x % mod; x = x * x % mod; n >>= 1; } return ret; }

void Main(){
    int h, w;
    cin >> h >> w;
    vector a(h, vector(w, 0)), dp(h, vector(w, 0));
    rep(h) rep(j,w){
        char input;
        cin >> input;
        a[i][j] = input - '-' ? 1 : -1;
    }
    if(!(h + w - 2)) dp[h-1][w-1] = 0;
    else dp[h-1][w-1] = a[h-1][w-1];
    rrep(h) rrep(j,w){
        if((i + j) % 2){
            if(i < h - 1 && j < w - 1) dp[i][j] = min(dp[i+1][j] - a[i+1][j], dp[i][j+1] - a[i][j+1]);
            else if(i < h - 1) dp[i][j] = dp[i+1][j] - a[i+1][j];
            else if(j < w - 1) dp[i][j] = dp[i][j+1] - a[i][j+1];
        }else{
            if(i < h - 1 && j < w - 1) dp[i][j] = max(dp[i+1][j] + a[i+1][j], dp[i][j+1] + a[i][j+1]);
            else if(i < h - 1) dp[i][j] = dp[i+1][j] + a[i+1][j];
            else if(j < w - 1) dp[i][j] = dp[i][j+1] + a[i][j+1];
        }
    }
    if(dp[0][0] > 0) cout << "Takahashi" << endl;
    else if(dp[0][0] < 0) cout << "Aoki" << endl;
    else cout << "Draw" << endl;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    Main();
}