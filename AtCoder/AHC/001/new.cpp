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

bool judge(int x1, int y1, int x2, int y2, int a, int b, int c, int d){
    if(a <= x1 && x1 <= c){
        if(b <= y1 && y1 <= d) return 0;
        if(b <= y2 && y2 <= d) return 0;
        if(y1 <= b && d <= y2) return 0;
    }
    if(a <= x2 && x2 <= c){
        if(b <= y1 && y1 <= d) return 0;
        if(b <= y2 && y2 <= d) return 0;
        if(y1 <= b && d <= y2) return 0;
    }
    if(x1 <= a && c <= x2){
        if(b <= y1 && y1 <= d) return 0;
        if(b <= y2 && y2 <= d) return 0;
        if(y1 <= b && d <= y2) return 0;
    }
    return 1;
}

void Main(clock_t START, int TIME){
    int n;
    cin >> n;
    vector<poster> a(n);
    vector<answer> ans(n);
    vector<int> area(n);
    map<ll, vector<int>> order;
    priority_queue<int> task;
    { int i = 0; for(auto& [x, y, r] : a){
        cin >> x >> y >> r;
        ans[i].a = x, ans[i].b = y,
        ans[i].c = x + 1, ans[i].d = y + 1;
        area[i] = (ans[i].c - ans[i].a) * (ans[i].d - ans[i].b);
        task.push(abs(r - area[i]));
        order[abs(r - area[i])].emplace_back(i);
        i++;
    }}
    while(1){
        vector<int> cnt(n);
        while(task.size()){
            int i = order[task.top()][0], cmd = rand() % 4;
            order[task.top()].erase(order[task.top()].begin()); task.pop();
            bool ok = 1;
            int pre_area = area[i];
            answer prev = ans[i];
            if(cmd == 0) ans[i].a -= 1;
            if(cmd == 1) ans[i].b -= 1;
            if(cmd == 2) ans[i].c += 1;
            if(cmd == 3) ans[i].d += 1;
            area[i] = (ans[i].c - ans[i].a) * (ans[i].d - ans[i].b);
            rep(j, n){
                if(i == j) continue;
                if(!judge(ans[i].a, ans[i].b, ans[i].c, ans[i].d, ans[j].a, ans[j].b, ans[j].c, ans[j].d)) ok = 0;
            }
            if(ans[i].a < 0 || ans[i].b < 0 || ans[i].c > 10000 || ans[i].d > 10000) ok = 0;
            if(abs(a[i].r - area[i]) > abs(a[i].r - pre_area)) ok = 0;
            if(ok) cnt[i] = 0;
            else ans[i] = prev, area[i] = pre_area, cnt[i]++;
            if(cnt[i] < 50){
                task.push(abs(a[i].r - area[i]));
                order[abs(a[i].r - area[i])].emplace_back(i);
            }
            ENDLOOP
        }
        while(1000000){
            int i = rand() % n, cmd = rand() % 4;
            bool ok = 1;
            answer prev = ans[i];
            if(cmd == 1) ans[i].a += 1, ans[i].c += 1;
            if(cmd == 2) ans[i].b += 1, ans[i].d += 1;
            if(cmd == 3) ans[i].a -= 1, ans[i].c -= 1;
            if(cmd == 4) ans[i].b -= 1, ans[i].d -= 1;
            rep(j, n){
                if(i == j) continue;
                if(!judge(ans[i].a, ans[i].b, ans[i].c, ans[i].d, ans[j].a, ans[j].b, ans[j].c, ans[j].d)) ok = 0;
            }
            if(!(ans[i].a <= a[i].x && a[i].x < ans[i].c && ans[i].b <= a[i].y && a[i].y < ans[i].d)) ok = 0;
            if(ans[i].a < 0 || ans[i].b < 0 || ans[i].c > 10000 || ans[i].d > 10000) ok = 0;
            if(!ok) ans[i] = prev;
            ENDLOOP
        }
        order = {};
        { int i = 0; for(const auto& [x, y, r] : a){
            area[i] = (ans[i].c - ans[i].a) * (ans[i].d - ans[i].b);
            task.push(abs(r - area[i]));
            order[abs(r - area[i])].emplace_back(i);
            i++;
            ENDLOOP
        }}
        ENDLOOP
    }
    for(const auto& [a, b, c, d] : ans) cout << a << " " << b << " " << c << " " << d << endl;
}

signed main(){
    clock_t START = clock();
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << setprecision(10) << fixed;
    Main(START, TIME * 990.0);
}