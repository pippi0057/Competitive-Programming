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

namespace CumulativeSum{
    template <class T> struct CumulativeVector{
        vector<T> a;
        CumulativeVector(int n) : a(n, 0) {}
        CumulativeVector(vector<T> v){ a = v; }
        void build(){ for(int i = 1; i < a.size(); i++) a[i] += a[i-1]; }
        T& operator [](int ind){ return a[ind]; }
        operator vector<T>&() const{ return a; }
    };
    template <class T> struct imos1D{
        vector<T> a;
        imos1D(int n) : a(n, 0) {}
        void add(int l, int r, int x){ a[l] += x; a[r] -= x; }
        void build(){ for(int i = 1; i < a.size(); i++) a[i] += a[i-1]; }
        T operator[](int ind){ return a[ind]; }
        operator const vector<T>&() const{ return a; }
    };
    template <class T> struct imos2D{
        vector<vector<T>> a;
        imos2D(int h, int w) : a(h, vector<T>(w, 0)) {}
        void add(int lx, int ly, int rx, int ry, int x){ a[lx][ly] += x; a[rx+1][ry+1] += x; a[lx][ry+1] -= x; a[rx+1][ly] -= x; }
        void build(){
            for(int i = 0; i < a.size(); i++) for(int j = 1; j < a[i].size(); j++) a[i][j] += a[i][j-1];
            for(int j = 0; j < a[0].size(); j++) for(int i = 1; i < a.size(); i++) a[i][j] += a[i-1][j];
        }
        vector<T> operator[](int ind){ return a[ind]; }
        operator const vector<vector<T>>&() const{ return a; }
    };
}

using namespace CumulativeSum;

void Main(){
    int n; ll k, ans = 0;
    cin >> n >> k;
    CumulativeVector<ll> a(n + 1);
    rep(i, 1, n + 1) cin >> a[i];
    a.build();
    map<ll, ll> m;
    rep(n + 1) m[a[i]]++;
    rep(n) m[a[i]]--, ans += m[a[i] + k];
    cout << ans << endl;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << setprecision(10) << fixed;
    Main();
}