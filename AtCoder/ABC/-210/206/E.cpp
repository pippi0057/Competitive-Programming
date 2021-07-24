#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define ll int64_t
#define u32 uint32_t
#define u64 uint64_t
constexpr ll inf = 1e17;
constexpr int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
constexpr int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
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
#define vv(type,name,size,...) vector<vector<type>> name(size,vector<type>(__VA_ARGS__))
#define ForEach(a,b) for_each(a.begin(),a.end(),b)
#define NextAfter(x) x = nextafter(x, INFINITY)
template <class T> inline bool chmin(T& a, T b){ if(a > b){ a = b; return 1; } return 0; }
template <class T> inline bool chmax(T& a, T b){ if(a < b){ a = b; return 1; } return 0; }
struct Edge { int to; ll cost; Edge(int to, ll cost) : to(to), cost(cost) {} };
using Graph = vector<vector<Edge>>;

vector<int> divisor(int n){
    vector<int> res;
    for(int i = 1; i * i <= n; i++){
        if(i == 1) continue;
        if (n % i == 0) {
            res.push_back(i);
        }
    }
    return res;
}

ll binary_gcd(ll a, ll b){
    if(!a) return b; if(!b) return a;
    if(~a & 1 && ~b & 1) return binary_gcd(a / 2, b / 2) * 2;
    if(~a & 1) return binary_gcd(a / 2, b); if(~b & 1) return binary_gcd(a, b / 2);
    if(a < b) return binary_gcd(a, (b - a) / 2); return binary_gcd(b, (a - b) / 2);
}

void Main(){
    int l, r;
    ll ans = 0;
    cin >> l >> r;
    rep(i,l,r+1){
        vector temp(1000100, false);
        vector<int> t = divisor(i);
        for(auto x : t){
            for(int j = 1; x * j <= r; j++){
                if(!temp[x*j]){
                    ans++; temp[x*j] = 1;
                    
                }
            }
        }
    }
    cout << ans << endl;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << setprecision(10) << fixed;
    Main();
}