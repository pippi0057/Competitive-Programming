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
#define F function
template <class T> inline bool chmin(T& a, T b){ if(a > b){ a = b; return 1; } return 0; }
template <class T> inline bool chmax(T& a, T b){ if(a < b){ a = b; return 1; } return 0; }
struct Edge { int to; ll cost; Edge(int to, ll cost) : to(to), cost(cost) {} };
using Graph = vector<vector<Edge>>;
template<class T> istream& operator>>(istream& is, vector<T>& a){ for(auto& x : a) is >> x; return is; }
template<class T> void operator+=(vector<T>& a, T b){ a.push_back(b); return; }
template<class T> istream& operator>>(istream& is, set<T>& a){ T input; is >> input; a.insert(input); return is; }
template<class T> void operator+=(set<T>& a, T b){ a.insert(b); return; }
struct sorted_impl{
    template<class T> friend vector<T> operator|(vector<T> a, sorted_impl){ sort(all(a)); return a; }
    template<class T> friend void operator|=(vector<T>& a, sorted_impl){ sort(all(a)); }
} sorted;
struct reversed_impl{
    template<class T> friend vector<T> operator|(vector<T> a, reversed_impl){ reverse(all(a)); return a; }
    template<class T> friend void operator|=(vector<T>& a, reversed_impl){ reverse(all(a)); }
} reversed;

#define SEG_LEN (1 << 10)

int seg[SEG_LEN * 2];

void add(int ind, int v){
    ind += SEG_LEN;
    seg[ind] = v;
    while(true){
        ind /= 2;
        if(ind == 0) break;
        seg[ind] = min(seg[ind * 2], seg[ind * 2 + 1]);
    }
}

int get(int l, int r){
    l += SEG_LEN;
    r += SEG_LEN;
    int ans = 999999999;
    while(l < r){
        if(l % 2 == 1){
            chmin(ans, seg[l]);
            l++;
        }
        l /= 2;
        if(r % 2 == 1){
            chmin(ans, seg[r - 1]);
            r--;
        }
        r /= 2;
    }
    return ans;
}

void Main(){
    int n; cin >> n;
    vector<pair<int, pii>> a(n);
    rep(n){
        int l, r;
        cin >> l >> r;
        a[i] = {r - l, {l, r}};
        add(i, i);
    }
    add(n, n);
    for(Auto& [pt, range] : a | sorted){
        auto [l, r] = range;
        int ans = get(l, r + 1);
        cout << l << " " << r << " " << ans << endl;
        add(ans, n);
    }
    cout << endl;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    while(n--) Main();
}