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
template <class T> inline bool chmin(T& a, T b){ if(a > b){ a = b; return 1; } return 0; }
template <class T> inline bool chmax(T& a, T b){ if(a < b){ a = b; return 1; } return 0; }
struct Edge { int to; ll cost; Edge(int to, ll cost) : to(to), cost(cost) {} };
using Graph = vector<vector<Edge>>;
#define ENDLOOP clock_t END = clock(); if(((long double)(END - START) / CLOCKS_PER_SEC * 1000.0) > TIME) break;

constexpr long double TIME = 5;

struct poster { int x, y, r; };
struct answer { int a, b, c, d; };

void Main(clock_t START, int TIME){
    int n;
    cin >> n;
    vector<poster> a(n);
    vector<answer> ans(n);
    { int i = 0; for(auto& [x, y, r] : a){
        cin >> x >> y >> r;
        ans[i].a = x, ans[i].b = y,
        ans[i].c = x + 1, ans[i].d = y + 1;
        i++;
    }}
    while(1){
        int i = rand() % n, cmd = rand() % 4;
        bool ok = 1;
        answer prev = ans[i];
        if(cmd == 0) ans[i].a -= 1;
        if(cmd == 1) ans[i].b -= 1;
        if(cmd == 2) ans[i].c += 1;
        if(cmd == 3) ans[i].d += 1;
        rep(j, n){
            if(i == j) continue;
            int a = ans[j].a, b = ans[j].b,
                c = ans[j].c, d = ans[j].d;
            if(a <= ans[i].a && ans[i].a <= c){
                if(b <= ans[i].b && ans[i].b <= d) ok = 0;
                if(b <= ans[i].d && ans[i].d <= d) ok = 0;
                if(ans[i].b <= b && d <= ans[i].d) ok = 0;
            }
            if(a <= ans[i].c && ans[i].c <= c){
                if(b <= ans[i].b && ans[i].b <= d) ok = 0;
                if(b <= ans[i].d && ans[i].d <= d) ok = 0;
                if(ans[i].b <= b && d <= ans[i].d) ok = 0;
            }
            if(ans[i].a <= a && c <= ans[i].c){
                if(b <= ans[i].b && ans[i].b <= d) ok = 0;
                if(b <= ans[i].d && ans[i].d <= d) ok = 0;
                if(ans[i].b <= b && d <= ans[i].d) ok = 0;
            }
        }
        if(ans[i].a < 0 || ans[i].b < 0 || ans[i].c > 10000 || ans[i].d > 10000) ok = 0;
        if(!ok) ans[i] = prev;
        ENDLOOP
    }
    cout << endl;
    for(const auto& [a, b, c, d] : ans) cout << a << " " << b << " " << c << " " << d << endl;
}

signed main(){
    clock_t START = clock();
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << setprecision(10) << fixed;
    Main(START, TIME * 98000.0 / 100.0);
}