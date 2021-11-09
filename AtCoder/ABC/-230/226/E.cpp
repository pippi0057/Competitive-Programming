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
template<class T> istream& operator>>(istream& is, vector<T>& a){ for(auto& x : a) is >> x; return is; }
template<class T> void operator+=(vector<T>& a, T b){ a.push_back(b); return; }
template<class T> istream& operator>>(istream& is, set<T>& a){ T input; is >> input; a.insert(input); return is; }
struct sorted_impl{
    template<class T> friend vector<T> operator|(vector<T> a, sorted_impl){ sort(all(a)); return a; }
    template<class T> friend void operator|=(vector<T>& a, sorted_impl){ sort(all(a)); }
} sorted;
struct reversed_impl{
    template<class T> friend vector<T> operator|(vector<T> a, reversed_impl){ reverse(all(a)); return a; }
    template<class T> friend void operator|=(vector<T>& a, reversed_impl){ reverse(all(a)); }
} reversed;

struct UnionFind{
    vector<ll> data;
    UnionFind(ll n): data(n, -1){}
    bool unite(ll a, ll b){
        a = root(a); b = root(b);
        if(a == b) return 0;
        if(data[a] > data[b]) swap(a, b);
        data[a] += data[b];
        data[b] = a;
        return 1;
    }
    bool find(ll a, ll b){ return root(a) == root(b); }
    ll root(ll a){ return data[a] < 0 ? a : data[a] = root(data[a]); }
    ll size(ll a){ return -data[root(a)]; }
    ll operator[](ll a){ return root(a); }
};

ll mow(ll x, ll n){ ll ret = 1; while(n > 0){ if(n & 1) ret = ret * x; x = x * x; n >>= 1; } return ret; }
ll mow(ll x, ll n, ll mod){ ll ret = 1; while(n > 0){ if(n & 1) ret = ret * x % mod; x = x * x % mod; n >>= 1; } return ret; }

void Main(){
    ll n, m, cnt = 0;
    cin >> n >> m;
    UnionFind uf(n);
    vector<bool> done(n, false);
    set<int> seen;
    rep(m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        if(a > b) swap(a, b);
        if(uf.find(a, b)){
            if(done[uf[a]]){ cout << 0 << endl; return; }
            done[uf[a]] = 1;
            cnt++;
        }
        uf.unite(a, b);
        seen.insert(a); seen.insert(b);
    }
    if(seen.size() != n) cout << 0 << endl;
    else if(mow(2, cnt, 998244353) == 1) cout << 0 << endl;
    else cout << mow(2, cnt, 998244353) << endl;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << setprecision(10) << fixed;
    Main();
}