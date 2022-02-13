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

template <typename T>
struct BIT2D {
    int H, W;
    vector<vector<T>> bit;
    BIT2D(int H_, int W_) { init(H_, W_); }
    void init(int H_, int W_) {
        H = H_ + 1;
        W = W_ + 1;
        bit.assign(H, vector<T>(W, 0));
    }
    void add(int h, int w, T x) {
        for (int i = h; i < H; i += (i & -i)) {
            for (int j = w; j < W; j += (j & -j)) {
                bit[i][j] += x;
            }
        }
    }
    T sum(int h, int w) {
        T s(0);
        for (int i = h; i > 0; i -= (i & -i)) {
            for (int j = w; j > 0; j -= (j & -j)) {
                s += bit[i][j];
            }
        }
        return s;
    }
    T query(int h1, int w1, int h2, int w2) {
        return sum(h2 - 1, w2 - 1) - sum(h2 - 1, w1 - 1) - sum(h1 - 1, w2 - 1) + sum(h1 - 1, w1 - 1);
    }
};

void Main(){
    int H, W, ans = 0;
    cin >> H >> W;
    vector A(H, vector(W, 0));
    for(auto& v : A) for(auto& x : v) cin >> x;
    rep(H) rep(j, W){
        vector data(H, vector(W, 0));
        BIT2D<int> bit(H, W);
        queue<pii> task;
        task.push({i, j});
        rep(k, H) rep(l, W){
            while(!task.empty()){
                auto [ni, nj] = task.front(); task.pop();
                data[ni][nj] = 1;
                bit.add(ni + 1, nj + 1, 1); // 1 1 3 4
                rep(4){
                    int si = ni + dx[i], sj = nj + dy[i];
                    if(si < 0 || sj < 0 || H <= si || W < sj) continue;
                    if(si < min(i, k) || sj < min(j, l) || max(i, k) <= si || max(j, l) <= sj) continue;
                    if(A[ni][nj] > A[si][sj] && !data[si][sj]) task.push({si, sj});
                }
            }
            if(i < k && j < l) if((abs(i - k) + 1) * (abs(j - l) + 1) == bit.query(i + 1, j + 1, k + 2, l + 2)) ans++;
            if(i < k && l <= j) if((abs(i - k) + 1) * (abs(j - l) + 1) == bit.query(i + 1, l + 1, k + 2, j + 2)) ans++;
            if(k <= i && j < l) if((abs(i - k) + 1) * (abs(j - l) + 1) == bit.query(k + 1, j + 1, i + 2, l + 2)) ans++;
            if(k <= i && l <= j) if((abs(i - k) + 1) * (abs(j - l) + 1) == bit.query(k + 1, l + 1, i + 2, j + 2)) ans++;
            cout << ans << endl << i << " " << j << " " << k << " " << l << endl;
        }
    }
    cout << ans << endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    Main();
}