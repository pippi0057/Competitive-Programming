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

struct status{ int a, b, c, d, e; };

void Main(){
    int n, k = 0, ans = 0;
    cin >> n;
    vector<status> member(n);
    vector<vector<pii>> top(5, vector<pii>(3));
    for(auto& [a, b, c, d, e] : member){
        cin >> a >> b >> c >> d >> e;
        if(chmax(top[0][0].first, a)) top[0][0].first = a, top[0][0].second = k;
        if(chmax(top[1][0].first, b)) top[1][0].first = b, top[1][0].second = k;
        if(chmax(top[2][0].first, c)) top[2][0].first = c, top[2][0].second = k;
        if(chmax(top[3][0].first, d)) top[3][0].first = d, top[3][0].second = k;
        if(chmax(top[4][0].first, e)) top[4][0].first = e, top[4][0].second = k; 
        rep(5) sort(all(top[i]));
        k++;
    }
    rep(n-1) rep(j,i+1,n){
        int a = max(member[i].a, member[j].a),
            b = max(member[i].b, member[j].b),
            c = max(member[i].c, member[j].c),
            d = max(member[i].d, member[j].d),
            e = max(member[i].e, member[j].e);
        if(a <= b && a <= c && a <= d && a <= e){
            if(top[0][2].second != i && top[0][2].second != j) chmax(a, top[0][2].first);
            else if(top[0][1].second != i && top[0][1].second != j) chmax(a, top[0][1].first);
            else chmax(a, top[0][0].first);
        }else if(b <= a && b <= c && b <= d && b <= e){
            if(top[1][2].second != i && top[1][2].second != j) chmax(b, top[1][2].first);
            else if(top[1][1].second != i && top[1][1].second != j) chmax(b, top[1][1].first);
            else chmax(b, top[1][0].first);
        }else if(c <= a && c <= b && c <= d && c <= e){
            if(top[2][2].second != i && top[2][2].second != j) chmax(c, top[2][2].first);
            else if(top[2][1].second != i && top[2][1].second != j) chmax(c, top[2][1].first);
            else chmax(c, top[2][0].first);
        }else if(d <= a && d <= b && d <= c && d <= e){
            if(top[3][2].second != i && top[3][2].second != j) chmax(d, top[3][2].first);
            else if(top[3][1].second != i && top[3][1].second != j) chmax(d, top[3][1].first);
            else chmax(d, top[3][0].first);
        }else{
            if(top[4][2].second != i && top[4][2].second != j) chmax(e, top[4][2].first);
            else if(top[4][1].second != i && top[4][1].second != j) chmax(e, top[4][1].first);
            else chmax(e, top[4][0].first);
        }
        chmax(ans, min({a, b, c, d, e}));
    }
    cout << ans << endl;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    Main();
}