#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define u32 uint32_t
#define u64 uint64_t
constexpr ll inf = 1e17;
constexpr int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
constexpr int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
#define pii pair<int,int>
#define pll pair<ll,ll>
#define endl "\n"
#define Auto const auto
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

vector<bool> seg1(1 << 20), seg2(1 << 20);

bool get(vector<bool>& seg, int ind){
    ind += 1 << 19;
    if(seg[ind]) return 1;
    while(true){
        ind /= 2;
        if(ind == 0) break;
        if(seg[ind]) return 1;
    }
    return 0;
}

void add(vector<bool>& seg, int l, int r){
    l += 1 << 19;
    r += 1 << 19;
    while(l < r){
        if(l % 2 == 1){
            seg[l] = 1;
            l++;
        }
        l /= 2;
        if(r % 2 == 1){
            seg[r-1] = 1;
            r--;
        }
        r /= 2;
    }
}

void Main(){
    int n;
    cin >> n;
    vector<int> d(n);
    for(auto& x : d) cin >> x;
    add(seg1, 0, 1); add(seg2, n - 1, n);
    rep(n-1) if(get(seg1, i)) add(seg1, i, min(n, i + d[i] / 10 + 1));
    if(!get(seg1, n - 1)){ cout << "no" << endl; return; }
    rrep(i,1,n) if(get(seg2, i)) add(seg2, max(0, i - d[i] / 10), i + 1);
    if(get(seg2, 0)) cout << "yes" << endl;
    else cout << "no" << endl;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << setprecision(10) << fixed;
    Main();
}