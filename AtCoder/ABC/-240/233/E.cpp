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

template <class T> struct RAQ {
    int n;
    vector<T> seg;
    RAQ(int n) : n(n) { int x = 1; while(n > x) x *= 2; n = x; seg.resize(n * 2, 0); }
    RAQ(int n, int a) : n(n) { int x = 1; while(n > x) x *= 2; n = x; seg.resize(n * 2, a); }
    void add(int l, int r, T x){
        l += n + 1; r += n + 1;
        while(l < r){
            if(l % 2 == 1) seg[l] += x, l++; l /= 2;
            if(r % 2 == 1) seg[r-1] += x, r--; r /= 2;
        }
    }
    T get(int ind){
        ind += n + 1; T sum = 0; sum += seg[ind];
        while(1){ ind /= 2; if(ind == 0) break; sum += seg[ind]; }
        return sum;
    }
    T operator[](int ind){ return get(ind); }
};

vector<ll> carry_and_fix(vector<ll> digit) {
    int N = digit.size();
    for(int i = 0; i < N - 1; ++i) {
        // 繰り上がり処理 (K は繰り上がりの回数)
        if(digit[i] >= 10) {
            ll K = digit[i] / 10;
            digit[i] -= K * 10;
            digit[i + 1] += K;
        }
        // 繰り下がり処理 (K は繰り下がりの回数)
        if(digit[i] < 0) {
            ll K = (-digit[i] - 1) / 10 + 1;
            digit[i] += K * 10;
            digit[i + 1] -= K;
        }
    }
    // 一番上の桁が 10 以上なら、桁数を増やすことを繰り返す
    while(digit.back() >= 10) {
        ll K = digit.back() / 10;
        digit.back() -= K * 10;
        digit.push_back(K);
    }
    // 1 桁の「0」以外なら、一番上の桁の 0 (リーディング・ゼロ) を消す
    while(digit.size() >= 2 && digit.back() == 0) {
        digit.pop_back();
    }
    return digit;
}

void Main(){
    string x;
    cin >> x;
    RAQ<ll> seg(x.size());
    rep(x.size()) seg.add(i, x.size(), x[i] - '0');
    vector<ll> a(x.size());
    rep(x.size()) a[i] = seg.get(i);
    auto ans = carry_and_fix(a | reversed);
    for(auto& x : ans | reversed) cout << x;
    cout << endl;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << setprecision(10) << fixed;
    Main();
}