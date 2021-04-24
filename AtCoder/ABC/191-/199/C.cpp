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

void Main(){
    int n, q;
    string s, t;
    bool cmd = 1;
    cin >> n >> s >> q;
    vector<char> c(n), d(n);
    t = s.substr(n);
    s = s.substr(0, n);
    rep(n) c[i] = s[i];
    rep(n) d[i] = t[i];
    rep(q){
        int t, a, b;
        cin >> t >> a >> b;
        a--; b--;
        if(t == 1){
            if(cmd){
                if(a > b) swap(a, b);
                if(n <= a && n <= b) swap(d[a-n], d[b-n]);
                else if(a < n && b < n) swap(c[a], c[b]);
                else swap(c[a], d[b-n]);
            }else{
                if(a > b) swap(a, b);
                if(n <= a && n <= b) swap(c[a-n], c[b-n]);
                else if(a < n && b < n) swap(d[a], d[b]);
                else swap(d[a], c[b-n]);
            }
        }else{
            if(cmd) cmd = 0;
            else cmd = 1;
        }
    }
    if(cmd){
        rep(n) cout << c[i];
        rep(n) cout << d[i];
    }else{
        rep(n) cout << d[i];
        rep(n) cout << c[i];
    }
    cout << endl;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    Main();
}